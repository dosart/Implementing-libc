/*!
@file
@defgroup memory_management
@brief  Header file for shared_ptr
This file contains simple class shared_ptr.
*/
#ifndef MY_SHARED_PTR_HPP
#define MY_SHARED_PTR_HPP

#include <memory>
#include <utility>

namespace smart_ptr
{
    /**
     * @ingroup memory_management
     *
     * @brief smart_ptr::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer. Several shared_ptr objects may own the same object.
     */
    template <typename T>
    class shared_ptr
    {
    public:
        using pointer = T *;
        using element_type = T;

        /**
         * @ingroup memory_management
         *
         * @brief Default constructor, creates a unique_ptr that owns nothing.
         */
        constexpr shared_ptr() noexcept = default;

        /**
         * @ingroup memory_management
         *
         * @brief Constructor with std::nullptr_t, creates a unique_ptr that owns nothing.
         */
        constexpr shared_ptr(std::nullptr_t) noexcept : m_data(nullptr), m_count(nullptr){};

        /**
         * @ingroup memory_management
         *
         * @brief  Constructs a shared_ptr with p as the pointer to the managed object.
         */
        explicit shared_ptr(pointer data)
            : m_data(data), count(new (std::nothorw) int(1))
        {
            if (m_count == nullptr)
            {
                delete m_data;
                throw std::bad_alloc();
            }
        }

        /**
         * @ingroup memory_management
         *
         * @brief  Destructs the owned object if no more shared_ptrs link to it.
         */
        ~shared_ptr()
        {
            --(*m_count);
            if (*m_count == 0)
            {
                delete m_data;
            }
        }

        shared_ptr(shared_ptr const &copy)
            : m_data(copy.data), m_count(copy.count)
        {
            ++(*m_count);
        }

        /**
         * @ingroup memory_management
         *
         * @brief  Replaces the managed object with the one managed by src.
         */
        shared_ptr &operator=(unique_ptr &src)
        {
            shared_ptr tmp(src);
            tmp.swap(*this);
            return *this;
        }

        /**
         * @ingroup memory_management
         *
         * @brief  Specializes the std::swap algorithm.
         */
        void
        swap(shared_ptr &src) noexcept
        {
            std::swap(m_data, src.m_data);
            std::swap(m_count, src.m_count);
        }

        /// Const correct access owned object
        pointer operator->() const noexcept { return m_data; }
        element_type &operator*() const { return *m_data; }

        /**
         * @ingroup memory_management
         *
         * @brief  Returns the stored pointer.
         *
         * @returns The stored pointer.
         */
        pointer
        get() const noexcept
        {
            return m_data;
        }

        /**
         * @ingroup memory_management
         *
         * @brief checks if the stored pointer is not null.
         *
         * @returns True if *this stores a pointer, false otherwise..
         */
        explicit operator bool() const noexcept { return m_data; }

        /**
         * @ingroup memory_management
         *
         * @brief  Returns the number of shared_ptr objects referring to the same managed object.
         *
         * @returns The number of smart_pointer::shared_ptr instances managing the current object or ​0​ if there is no managed object.
         */
        size_t
        use_count() const noexcept
        {
            return m_count != nullptr ? *m_count : 0;
        }

    private:
        pointer m_data = nullptr;
        int *m_count = nullptr;
    };
}

#endif