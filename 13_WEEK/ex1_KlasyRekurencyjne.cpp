#include <iostream>


template<int Base, int Exp>
struct Power {
  static const int value = Base * Power<Base, Exp - 1>::value;
};

template<int Base>
struct Power<Base, 0> {
  static const int value = 1;
};


template<int N, int K>
struct Binomial {
  static const long long value = Binomial<N - 1, K>::value + Binomial<N - 1, K - 1>::value;
};

template<int N>
struct Binomial<N, 0> {
  static const long long value = 1;
};

template<int N>
struct Binomial<N, N> {
  static const long long value = 1;
};


// //////////////////////////////////


constexpr int power(int base, int exp) {
  return (exp == 0) ? 1 : base * power(base, exp - 1);
}
constexpr long long binomial(int n, int k) {
  return (k == 0 || k == n) ? 1 : binomial(n - 1, k) + binomial(n - 1, k - 1);
}


int main() {
  std::cout << Power<5, 3>::value << std::endl; // 125
  static_assert(Power<5, 3>::value == 125);
  static_assert(Power<2, 8>::value == 256);

  std::cout << Binomial<4, 2>::value << std::endl; //6
  std::cout << Binomial<100, 0>::value << std::endl; //1
  std::cout << Binomial<100, 1>::value << std::endl; //100
  std::cout << Binomial<100, 7>::value << std::endl; //16007560800

  static_assert(Binomial<4,
                  2>::value == 6
      )
      ;
  static_assert(Binomial<100,
                  0>::value == 1
      )
      ;
  static_assert(Binomial<100,
                  1>::value == 100
      )
      ;
  static_assert(Binomial<100,
                  7>::value == 16007560800
      )
      ;

  return 0;
}
