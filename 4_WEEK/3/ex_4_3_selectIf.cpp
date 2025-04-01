
#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

bool biggerThan5(int x){ return x>5; }

// zakladamy ze ::value_type jest w in conteiner
template<
	template<typename, typename> class OutContainer,
	typename InContainer,
	typename Predicate
>     // zwracany typ funkcji
OutContainer<typename InContainer::value_type, typename InContainer::allocator_type> selectIfv1(const InContainer& c, Predicate p) {

	// alias
	using T = typename InContainer::value_type;
	using Alloc = typename InContainer::allocator_type;

	OutContainer<T, Alloc> result;
	for (const auto& el : c) {
		if (p(el)) result.push_back(el);
	}

	return result;
}





// ogólna wersja dla STL kontenerów
template<
	template<typename, typename> class OutContainer,
	typename InContainer,
	typename Predicate
>
OutContainer<typename InContainer::value_type, typename InContainer::allocator_type>
selectIf(const InContainer& c, Predicate p) {
	using T = typename InContainer::value_type;
	using Alloc = typename InContainer::allocator_type;

	OutContainer<T, Alloc> result;
	size_t i = 0;

	for (const auto& el : c) {
		if (p(el)) {
			if constexpr (requires { result.push_back(el); }) {
				result.push_back(el);
			} else if constexpr (requires { result.insert(el); }) {
				result.insert(el);
			}
		}
	}
	return result;
}

int main(){
	auto print = [](auto v) { 
		for(auto x: v) cout << x << " ";
		cout << endl;
	};

	std::vector<int> v={1, 2, 13, 4, 5, 54};
  std::list<int> result = selectIf<std::list>(v, biggerThan5);
  print(result);  //  13 54
  
  auto result2 = selectIf<std::deque>(v, [](int x)->bool{ return x%2; } );
  print(result2); //  1 13 5
  
	auto result3 = selectIf<std::vector>(result2, biggerThan5);
	print(result3); //  13
	return 0;
}
