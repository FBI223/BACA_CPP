
#ifndef LAB8_VECTOR_H
#define LAB8_VECTOR_H

#include <memory>
#include <iostream>
#include <cassert>
#include <vector>


#include "vector_traits.h"
#include "vector_policies.h"


//template<typename T, size_t N>

template<typename T, size_t N, typename P = SafePolicy>
class Vector {
	T data[N];

public:
	using traits = vector_traits<T>;
	using param_type = typename traits::param_type;
	using return_type = typename traits::return_type;
	using scalar_type = typename traits::scalar_type;


	typedef T value_type;
	typedef std::size_t size_type;
	typedef T *pointer;
	typedef T &reference;
	typedef const T &const_reference;

	Vector() {
		P::init(data); // delegujemy inicjalizację do policy
	}

	Vector(const Vector &v) = default;

	Vector &operator=(const Vector &m) = default;

	Vector(const std::initializer_list<T> &list) {
		std::copy(list.begin(), list.end(), data);
	}

	size_type size() const {
		return N;
	}

	return_type get(size_type index) const {
		P::check(index, N); // sprawdzenie indeksu przez policy
		return data[index];
	}

	void set(size_type index, param_type value) {
		P::check(index, N); // sprawdzenie indeksu przez policy
		data[index] = value;
	}

	friend Vector operator*(const scalar_type &s, const Vector &v) {
		Vector result;
		for (size_type i = 0; i < N; ++i) {
			result.set(i, traits::multiply(s, v.get(i)));
		}
		return result;
	}


	friend std::ostream &operator<<(std::ostream &out, const Vector &v) {
		for (int i = 0; i < v.size(); ++i) {
			out << v.get(i) << " ";
		}
		return out;
	}

	friend std::istream &operator>>(std::istream &in, Vector &v) {
		Vector::value_type value;
		for (int i = 0; i < v.size(); ++i) {
			in >> value;
			if (in)
				v.set(i, value);
		}
		return in;
	}
};

#endif // LAB8_VECTOR_H
