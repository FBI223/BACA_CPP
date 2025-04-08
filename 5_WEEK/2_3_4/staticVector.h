
#pragma once
#include "vector_base.h"


#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>


template <typename T, size_t N>
class Vector{
    T data[N];

public:
    typedef T value_type;
    typedef std::size_t  size_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T& const_reference;

    Vector() {
        for (size_type i = 0; i < N; ++i)
            data[i] = T{};
    }

    Vector(const Vector & v) = default ;
    Vector& operator=(const Vector& m) = default;

    Vector(std::initializer_list<T> list) {
        if (list.size() != N)
            throw std::invalid_argument("Wrong number of elements");
        std::copy(list.begin(), list.end(), data);
    }

    Vector<T, N> operator+(const Vector<T, N>& other) const {
        Vector<T, N> result;
        for (std::size_t i = 0; i < N; ++i)
            result[i] = data[i] + other[i];
        return result;
    }

    constexpr size_type size() const {
        return N;
    }

    const_reference get(size_type index) const {
        return data[index];
    }

    void set(size_type index, const_reference value) {
        data[index] = value;
    }

    reference operator[](size_type index){
        return data[index];
    }
    const_reference operator[](size_type index) const{
        return data[index];
    }

    friend std::ostream &operator<<(std::ostream &out, const Vector & v) {
        for( auto elem: v.data ){
            out << elem << " ";
        }
        return out;
    }


    explicit operator Vector<T, 0>() const {
        Vector<T, 0> result(N);
        for (size_type i = 0; i < N; ++i)
            result[i] = data[i];
        return result;
    }




};



