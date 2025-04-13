#include <iostream>
#include <vector>
using namespace std;


template<typename... Ts>
class MultiVector {
	std::tuple<std::vector<Ts>...> columns;

public:
	template<typename T>
	void push_back(const T &val) {
		push_back_dispatch<T>(val);
	}

	void print() const {
		std::apply([](const auto &... cols) {
			((std::cout << "[ ", print_vector(cols), std::cout << "] "), ...);
			std::cout << "\n";
		}, columns);
	}

private:
	// 🔁 najprostsze dopasowanie typu
	template<typename T>
	void push_back_dispatch(const T &val) {
		auto &vec = std::get<std::vector<T> >(columns);
		vec.push_back(val);
	}

	// wypisanie jednego wektora
	template<typename T>
	static void print_vector(const std::vector<T> &vec) {
		for (const auto &el: vec) std::cout << el << " ";
	}
};


int main() {
	MultiVector<int, string, double> m;
	m.push_back(5);
	m.push_back(string("text"));
	m.push_back(7);
	m.push_back(1.2);
	m.print(); // [ 5 7 ] [ text ] [ 1.2 ]
	auto v = std::move(m);
	for (auto x: {1, 2, 3}) {
		v.push_back(x + 10);
		v.push_back(std::to_string(x));
		v.push_back(x / 10.0);
	}
	m.print(); // [ ] [ ] [ ]   but can be undefined
	v.print(); // [ 5 7 11 12 13 ] [ text 1 2 3 ] [ 1.2 0.1 0.2 0.3 ]
	//MultiVector<int, int, double, int> w;
	MultiVector<int, double> w;
	w.push_back(1);
	w.push_back(2.0);
	w.print(); // [ 1 ] [ ] [ 2 ] [ ]
}

/*
[ 5 7 ] [ text ] [ 1.2 ]
[ ] [ ] [ ]
[ 5 7 11 12 13 ] [ text 1 2 3 ] [ 1.2 0.1 0.2 0.3 ]
[ 1 ] [ ] [ 2 ] [ ]
 */
