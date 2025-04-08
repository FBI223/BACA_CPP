#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>
#include <cstddef>

class VectorException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};