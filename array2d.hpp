//
// Created by ik on 19.02.2021.
//

#pragma once

#include <initializer_list>
#include <cstddef>
#include <string>

using brick = char;

class Array2d {

    brick ** data_;
    size_t width_;
    size_t height_;

public:
    Array2d(size_t width, size_t height);
    Array2d(const brick **array, size_t width, size_t height);

    template<typename containerT>
    Array2d(const std::initializer_list<containerT> &init_list, brick empty_value = ' ');
    Array2d(const std::initializer_list<const brick *> &init_list, brick empty_value = ' ');

    ~Array2d() noexcept;
    Array2d(const Array2d &other);
    Array2d(Array2d &&other) noexcept;

    Array2d & operator=(const Array2d &other);
    Array2d & operator=(Array2d &&other) noexcept;

    [[nodiscard]] inline brick * operator[](size_t height_index) const noexcept
    {
        return data_[height_index];
    }

    [[nodiscard]] inline size_t getWidth() const noexcept
    {
        return width_;
    }

    [[nodiscard]] inline size_t getHeight() const noexcept
    {
        return height_;
    }

private:
    void allocate();
    void deallocate() noexcept;
    void copy(const brick ** src) noexcept;
};

extern template
Array2d::Array2d(const std::initializer_list<std::initializer_list<const brick>> &init_list, brick empty_value = 0);
extern template
Array2d::Array2d(const std::initializer_list<std::string> &init_list, brick empty_value = 0);