#pragma include once

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

template<typename T, size_t N, size_t M>
class Matrix {
	T data[N * M];

public:
	constexpr size_t numberOfRows() const noexcept { return N; }
	constexpr size_t numberOfColumns() const noexcept { return M; }


	constexpr Matrix(int nrows = N, int ncols = M) noexcept {
		std::fill_n(data, N * M, T{});
	}


	Matrix(const std::initializer_list<std::initializer_list<T> > &list) {
		T *p = data;
		for (const auto &row: list) {
			T *p2 = std::copy(row.begin(), row.end(), p);
			std::fill(p2, p += M, T{});
		}
	}

	Matrix(const Matrix &m) {
		std::copy_n(m.data, N * M, data);
	}

	Matrix &operator=(const Matrix &m) {
		if (&m != this) {
			std::copy_n(m.data, N * M, data);
		}
		return *this;
	}

	constexpr T &operator()(int i, int j) noexcept {
		return data[(i - 1) * M + j - 1];
	}

	constexpr const T &operator()(int i, int j) const noexcept {
		return data[(i - 1) * M + j - 1];
	}


	friend Matrix operator+(const Matrix &a, const Matrix &b) {
		Matrix r;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				r(i, j) = a(i, j) + b(i, j);
			}
		}
		return r;
	}


	class iterator {
		T *ptr;

	public:
		constexpr explicit iterator(T *p) noexcept : ptr(p) {
		}

		T *operator->() { return ptr; }
		const T *operator->() const { return ptr; }
		constexpr T &operator*() const noexcept { return *ptr; }

		constexpr iterator &operator++() noexcept {
			++ptr;
			return *this;
		}

		constexpr bool operator!=(const iterator &other) const noexcept { return ptr != other.ptr; }
		constexpr bool operator==(const iterator &other) const noexcept { return ptr == other.ptr; }
	};


	class const_iterator {
		const T *ptr;

	public:
		constexpr explicit const_iterator(const T *p) noexcept : ptr(p) {
		}

		T *operator->() { return ptr; }
		const T *operator->() const { return ptr; }
		constexpr const T &operator*() const noexcept { return *ptr; }

		constexpr const_iterator &operator++() noexcept {
			++ptr;
			return *this;
		}

		constexpr bool operator!=(const const_iterator &other) const noexcept { return ptr != other.ptr; }
		constexpr bool operator==(const const_iterator &other) const noexcept { return ptr == other.ptr; }
	};


	class row_iterator {
		T *ptr;

	public:
		constexpr explicit row_iterator(T *p) noexcept : ptr(p) {
		}


		T *operator->() { return ptr; }
		const T *operator->() const { return ptr; }

		constexpr T &operator*() const noexcept { return *ptr; }

		constexpr row_iterator &operator++() noexcept {
			++ptr;
			return *this;
		}

		constexpr bool operator!=(const row_iterator &other) const noexcept { return ptr != other.ptr; }
		constexpr bool operator==(const row_iterator &other) const noexcept { return ptr == other.ptr; }
	};


	class col_iterator {
		T *ptr;
		size_t stride;

	public:
		constexpr col_iterator(T *p, size_t s) noexcept : ptr(p), stride(s) {
		}


		T *operator->() { return ptr; }
		const T *operator->() const { return ptr; }

		constexpr T &operator*() const noexcept { return *ptr; }

		constexpr col_iterator &operator++() noexcept {
			ptr += stride;
			return *this;
		}

		constexpr bool operator!=(const col_iterator &other) const noexcept { return ptr != other.ptr; }
		constexpr bool operator==(const col_iterator &other) const noexcept { return ptr == other.ptr; }
	};


	constexpr iterator begin() noexcept {
		return iterator(data);
	}

	constexpr iterator end() noexcept {
		return iterator(data + N * M);
	}

	constexpr const_iterator begin() const noexcept {
		return const_iterator(data);
	}

	constexpr const_iterator end() const noexcept {
		return const_iterator(data + N * M);
	}

	constexpr row_iterator row_begin(size_t i) noexcept {
		return row_iterator(data + (i - 1) * M); // ✅ poprawka
	}

	constexpr row_iterator row_end(size_t i) noexcept {
		return row_iterator(data + i * M); // ✅ poprawka
	}


	constexpr col_iterator col_begin(size_t j) noexcept {
		return col_iterator(data + (j - 1), M); // ✅ poprawka
	}

	constexpr col_iterator col_end(size_t j) noexcept {
		return col_iterator(data + (j - 1) + N * M, M); // ✅ poprawka
	}
};

template<typename T, size_t N, size_t M>
void printMatrix(const Matrix<T, N, M> &m, int width = 10) {
	for (int i = 1; i <= m.numberOfRows(); ++i) {
		for (int j = 1; j <= m.numberOfColumns(); ++j) {
			if (j != 1)
				cout << " ";
			cout << setw(width) << m(i, j);
		}
		cout << endl;
	}
}



