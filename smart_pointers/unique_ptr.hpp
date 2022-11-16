/*!
@file
@defgroup memory_management
@brief  Header file for unique_ptr
This file contains simple class unique_ptr.
*/

#ifndef MY_UNIQUE_PTR_HPP
#define MY_UNIQUE_PTR_HPP

#include <memory>
#include <utility>

namespace smart_ptr
{
    /**
     * @ingroup memory_management
     *
     * @brief smart_ptr::unique_ptr is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope..
     */
    template <typename T>
    class unique_ptr
    {
    public:
        using pointer = T *;
        using element_type = T;

        /**
         * @ingroup memory_management
         *
         * @brief Default constructor, creates a unique_ptr that owns nothing.
         */
        constexpr unique_ptr() noexcept = default;

        /**
         * @ingroup memory_management
         *
         * @brief Constructor with std::nullptr_t, creates a unique_ptr that owns nothing.
         */
        constexpr unique_ptr(std::nullptr_t) noexcept : m_data(nullptr){};

        /**
         * @ingroup memory_management
         *
         * @brief Constructor with pointer, creates a unique_ptr that owns pointer.
         */
        explicit unique_ptr(pointer p) noexcept : m_data(p) {}

        /// Disables copy constructor
        unique_ptr(const unique_ptr &) = delete;

        /// Disables copy assignment
        unique_ptr &operator=(const unique_ptr &) = delete;

        /**
         * @ingroup memory_management
         *
         * @brief Destructor. Remove memory if pointer isn't nullptr.
         */
        ~unique_ptr() noexcept
        {
            if (m_data)
                delete m_data;
        }

        /**
         * @ingroup memory_management
         *
         * @brief Access owned object.
         *
         * @returns Returns owned object.
         */
        pointer operator->() const { return m_data; }

        /**
         * @ingroup memory_management
         *
         * @brief Access owned object.
         *
         * @returns Returns owned object.
         */
        element_type &operator*() const { return *m_data; }

        /**
         * @ingroup memory_management
         *
         * @brief Access to smart pointer state.
         *
         * @returns Returns a pointer to the managed object.
         */
        pointer get() const { return m_data; }

        /**
         * @ingroup memory_management
         *
         * @brief Checks if the unique pointer is not null.
         *
         * @returns True if *this stores a pointer, false otherwise..
         */
        explicit operator bool() const { return m_data; }

        /**
         * @ingroup memory_management
         *
         * @brief Access to smart pointer state.
         *
         * @returns Returns a pointer to the managed object and releases the ownership.
         */
        pointer release()
        {
            T *result = nullptr;
            std::swap(result, m_data);
            return result;
        }

        void swap(unique_ptr &src) noexcept
        {
            std::swap(m_data, src.m_data);
        }

        unique_ptr(unique_ptr &&moving) noexcept
        {
            moving.swap(*this);
        }

        unique_ptr &operator=(unique_ptr &&moving) noexcept
        {
            moving.swap(*this);
            return *this;
        }

    private:
        pointer m_data = nullptr;
    };
}

#endif
