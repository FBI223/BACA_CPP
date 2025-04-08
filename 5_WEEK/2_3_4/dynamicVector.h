

#pragma once
#include "vector_base.h"
#include "staticVector.h"

#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <stdexcept>











template<typename T>
class Vector<T, 0> {
    std::unique_ptr<T[]> data;
    std::size_t length;

public:
    using value_type = T;
    using size_type = std::size_t;
    using pointer = T*;
    using reference = T&;
    using const_reference = const T&;

    // Konstruktor z rozmiarem
    Vector(size_type n) : data(std::make_unique<T[]>(n)), length(n) {
        for (size_type i = 0; i < length; ++i) data[i] = T{};
    }

    Vector(std::initializer_list<T> list)
    : data(std::make_unique<T[]>(list.size())), length(list.size()) {
        std::copy(list.begin(), list.end(), data.get());
    }

    // Resize
    void resize(size_type newSize) {
        auto newData = std::make_unique<T[]>(newSize);
        size_type minSize = std::min(length, newSize);
        for (size_type i = 0; i < minSize; ++i)
            newData[i] = data[i];
        for (size_type i = minSize; i < newSize; ++i)
            newData[i] = T{};
        data = std::move(newData);
        length = newSize;
    }

    reference operator[](size_type i) { return data[i]; }
    const_reference operator[](size_type i) const { return data[i]; }

    size_type size() const { return length; }

    Vector<T, 0> operator+(const Vector<T, 0>& other) const {
        if (length != other.length)
            throw VectorException("Vector sizes do not match");
        Vector<T, 0> result(length);
        for (size_type i = 0; i < length; ++i)
            result[i] = data[i] + other[i];
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& v) {
        for (size_type i = 0; i < v.length; ++i) {
            out << v[i];
            if (i + 1 < v.length) out << " ";
        }
        return out;
    }

    // Move operations (opcjonalnie)
    Vector(Vector&&) = default;
    Vector& operator=(Vector&&) = default;


    Vector(const Vector& other)
    : data(std::make_unique<T[]>(other.length)), length(other.length) {
        for (size_type i = 0; i < length; ++i)
            data[i] = other.data[i];
    }



    template<std::size_t M>
    explicit operator Vector<T, M>() const {
        if (length != M)
            throw VectorException("Size mismatch in conversion from dynamic to static vector");
        Vector<T, M> result;
        for (std::size_t i = 0; i < M; ++i)
            result[i] = data[i];
        return result;
    }




};


