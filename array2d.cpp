//
// Created by ik on 19.02.2021.
//

#include "array2d.hpp"
#include <stdexcept>

Array2d::Array2d(size_t width, size_t height)
        :
        data_{nullptr},
        width_{width},
        height_{height}
{
    if (!(width && height))
        throw std::logic_error("Width > 0 && Height > 0 assertion failed");

    allocate();
}

template <typename containerT>
Array2d::Array2d(const std::initializer_list<containerT> &init_list, brick empty_value)
:
    data_{nullptr}, // tmp
    width_{0},      // tmp
    height_{init_list.size()}
{
    for (auto &elem : init_list) {
        if (width_ < elem.size())
            width_ = elem.size();
    }

    allocate();

    size_t i = 0;
    for (auto it_i = init_list.begin(); it_i != init_list.end(); ++it_i, ++i) {

        size_t j = 0;
        for (auto it_j = it_i->begin(); it_j != it_i->end(); ++it_j, ++j)
            data_[i][j] = *it_j;

        for (; j < width_; ++j)
            data_[i][j] = empty_value;
    }
}

Array2d::Array2d(const std::initializer_list<const brick *> &init_list, brick empty_value)
:
data_{nullptr}, // tmp
width_{0},      // tmp
height_{init_list.size()}
{
    for (auto elem : init_list) {

        size_t i;
        for (i = 0; elem[i] != '\0'; ++i);

        if (width_ < i + 1)
            width_ = i + 1;
    }

    allocate();

    size_t i = 0;
    for (auto elem : init_list) {

        size_t j;
        for (j = 0; elem[j] != '\0'; ++j)
            data_[i][j] = elem[j];

        for (j = j; j < width_; ++j)
            data_[i][j] = empty_value;
        ++i;
    }
}

template Array2d::Array2d(const std::initializer_list<std::initializer_list<const brick>> &init_list, brick empty_value);
template Array2d::Array2d(const std::initializer_list<std::string> &init_list, brick empty_value);

Array2d::~Array2d() noexcept
{
    deallocate();
}

Array2d::Array2d(const Array2d &other)
        :
        data_{nullptr}, // tmp
        width_{other.width_},
        height_{other.height_}
{
    allocate();
    copy(const_cast<const brick **>(other.data_));
}

Array2d::Array2d(const brick ** array, size_t width, size_t height)
:
data_{nullptr}, // tmp
width_{width},
height_{height}
{
    allocate();
    copy(array);
}

Array2d::Array2d(Array2d &&other) noexcept
        :
        data_{other.data_},
        width_{other.width_},
        height_{other.height_}
{
    other.data_ = nullptr;
    other.width_ = 0;
    other.height_ = 0;
}

Array2d & Array2d::operator=(const Array2d &other)
{
    if (this == &other)
        return *this;

    deallocate();

    width_ = other.width_;
    height_ = other.height_;

    allocate();
    copy(const_cast<const brick **>(other.data_));

    return *this;
}

Array2d & Array2d::operator=(Array2d &&other) noexcept
{
    if (this == &other)
        return *this;

    deallocate();

    data_ = other.data_;
    width_ = other.width_;
    height_ = other.height_;

    other.data_ = nullptr;
    other.width_ = 0;
    other.height_ = 0;

    return *this;
}

void Array2d::allocate()
{
    data_ = ::new brick * [height_];
    for (size_t i = 0; i < height_; ++i)
        data_[i] = ::new brick [width_];
}

void Array2d::deallocate() noexcept
{
    for (size_t i = 0; i < height_; ++i)
        ::delete [] data_[i];
    ::delete [] data_;
}

void Array2d::copy(const brick ** src) noexcept
{
    for (size_t i = 0; i < width_; ++i)
        for (size_t j = 0; j < height_; ++j)
            data_[i][j] = src[i][j];
}