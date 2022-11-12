#ifndef MY_UNIQUE_PTR_HPP
#define MY_UNIQUE_PTR_HPP

#include <memory>
#include <utility>

namespace smart_ptr
{
    template <typename T>
    class unique_ptr
    {
    public:
        using pointer = T *;
        using element_type = T;

        /// Default constructor, creates a unique_ptr that owns nothing
        constexpr unique_ptr() noexcept = default;

        constexpr unique_ptr(std::nullptr_t) noexcept : m_data(nullptr){};

        explicit unique_ptr(pointer p) noexcept : m_data(p) {}

        /// Disables copy constructor
        unique_ptr(const unique_ptr &) = delete;

        /// Disables copy assignment
        unique_ptr &operator=(const unique_ptr &) = delete;

        ~unique_ptr() noexcept
        {
            if (m_data)
                delete m_data;
        }

        /// Const correct access owned object
        pointer operator->() const { return m_data; }
        element_type &operator*() const { return *m_data; }

        /// Access to smart pointer state
        pointer get() const { return m_data; }
        explicit operator bool() const { return m_data; }

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