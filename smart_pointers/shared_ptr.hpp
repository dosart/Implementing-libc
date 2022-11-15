#ifndef MY_SHARED_PTR_HPP
#define MY_SHARED_PTR_HPP

#include <memory>
#include <utility>

namespace smart_ptr
{
    template <typename T>
    class shared_ptr
    {
    public:
        using pointer = T *;
        using element_type = T;

        /// Default constructor, creates a shared_ptr that owns nothing
        constexpr shared_ptr() noexcept = default;

        constexpr shared_ptr(std::nullptr_t) noexcept : m_data(nullptr), m_count(nullptr){};

        explicit shared_ptr(pointer data)
            : m_data(data), count(new (std::nothorw) int(1))
        {
            if (m_count == nullptr)
            {
                delete m_data;
                throw std::bad_alloc();
            }
        }

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

        shared_ptr &operator=(unique_ptr &src)
        {
            shared_ptr tmp(src);
            tmp.swap(*this);
            return *this;
        }

        void swap(shared_ptr &src) noexcept
        {
            std::swap(m_data, src.m_data);
            std::swap(m_count, src.m_count);
        }

        /// Const correct access owned object
        pointer operator->() const noexcept { return m_data; }
        element_type &operator*() const { return *m_data; }

        /// Access to smart pointer state
        pointer get() const noexcept { return m_data; }
        explicit operator bool() const noexcept { return m_data; }

        size_t use_count() const noexcept
        {
            return m_count != nullptr ? *m_count : 0;
        }

    private:
        pointer m_data = nullptr;
        int *m_count = nullptr;
    };
}

#endif