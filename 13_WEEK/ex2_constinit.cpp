
#include <array>
#include <iostream>
#include <cmath>


/** 
 * Exercise 2a: 
 * Implement function power that computes x^n 
 * during compilation using recurrent formula
   x^2n = (x^n)^2
   x^2n+1 = (x^2n)*x
  */

template<typename T>
consteval T power(T x, int n) {
  if (n == 0) return T{1};
  T half = power(x, n / 2);
  if (n % 2 == 0)
    return half * half;
  else
    return half * half * x;
}

constinit double fiveToPowerFour = power(5, 4);

/**
 *  Exercise 2b:
 * Implement function generate_triangle that during compilation 
 * generates the Pascal trriangle of the given size N.
 * Pascal triangle
 * https://en.wikipedia.org/wiki/Pascal%27s_triangle
 *  
 */


// ✅ Szablon klasy PascalTriangle
template<size_t N>
class PascalTriangle {
  std::array<std::array<int, N>, N> triangle{};

public:
  consteval PascalTriangle() {
    for (size_t i = 0; i < N; ++i) {
      triangle[i][0] = 1;
      triangle[i][i] = 1;
      for (size_t j = 1; j < i; ++j) {
        triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      }
    }
  }


  consteval int operator()(size_t n, size_t k) const {
    return triangle[n][k];
  }
};

template<unsigned int N>
consteval PascalTriangle<N> generatePascalTriangle() {
  return PascalTriangle<N>{};
}


constexpr size_t n = 10;
constexpr auto triangle = generatePascalTriangle<n>();


int main() {
  static_assert(triangle(0, 0) == 1);
  static_assert(triangle(5, 3) == 10);
  static_assert(triangle(9, 4) == 126);
}
