

#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <iterator>
#include <algorithm>


template<typename Container>
double median_dispatch(Container set, std::random_access_iterator_tag) {
    std::sort(set.begin(), set.end());

    size_t n = set.size();
    if (n % 2 == 0) {
        return (set[n / 2 - 1] + set[n / 2]) / 2.0;
    } else {
        return set[n / 2];
    }
}

template<typename Container>
double median_dispatch(Container set, std::forward_iterator_tag) {
    std::vector<typename Container::value_type> vec(set.begin(), set.end());
    std::sort(vec.begin(), vec.end());

    size_t n = vec.size();
    if (n % 2 == 0) {
        return (vec[n / 2 - 1] + vec[n / 2]) / 2.0;
    } else {
        return vec[n / 2];
    }
}

template<typename Container>
double median(Container set) {
    using Iter = typename Container::iterator;
    using Tag = typename std::iterator_traits<Iter>::iterator_category;
    return median_dispatch(std::move(set), Tag{});
}


int main() {
    std::vector<int> vec{4, 1, 3, 2}; // random access iterator
    std::cout << "vector: " << median(vec) << "\n"; // 2.5

    std::deque<int> deq{10, 20, 30, 40, 50}; // random access iterator
    std::cout << "deque: " << median(deq) << "\n"; // 30

    std::list<int> lst{5, 1, 3, 2, 4}; // bidirectional/forward iterator
    std::cout << "list: " << median(lst) << "\n"; // 3

    std::forward_list<int> flst{9, 2, 5, 1}; // forward iterator
    std::cout << "forward_list: " << median(flst) << "\n"; // 3.5

    std::vector<double> v2{3.5, 1.5, 2.5};
    std::cout << "vector<double>: " << median(v2) << "\n"; // 2.5

    std::list<char> chars{'c', 'a', 'b'};
    std::cout << "list<char>: " << median(chars) << "\n"; // 'b'
}

