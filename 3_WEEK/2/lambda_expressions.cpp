#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <cassert>
#include <numeric>
#include <cmath>
#include <type_traits>
using namespace std;

void print(const std::vector<int> & v, const std::string & label = ""){
  cout << label;
  for( auto x  : v)
	cout << " " << x ;
  cout << endl;
}

int main(){
  std::vector<int> v = {256, 64, 16*3, 16*9, 16, 8*7, -9, -3, 1, 6, -2, 5, 9, 0};
  print(v, "original:");

  /// 1. Sort v with respect to the distance to the center (closest first)
  int center = 50;
  std::sort(v.begin(), v.end(), [=](int a , int b){ return abs(center-a) < abs(center-b) ; });            // 1
  print(v, "center 50:");


  /// 2. Sort in increasing order but
  ///  - negative numbers  are after positive ones, with zero in the middle,
  ///  - if numbers have the same sign then odd numbers are after even ones
  /// e.g.  4  < 8 < 1 < 3 < 0 <  -8 < -2 < -7 < -3

  auto positiveEvenFirst= [](int a , int b ){
      if (a > 0 && b <= 0) return true;     // a dodatni, b zero lub ujemny
      if (a <= 0 && b > 0) return false;    // a zero lub ujemny, b dodatni
      if (a == 0) return true;              // a == 0, b < 0 → true
      if (b == 0) return false;             // a < 0, b == 0 → false

      bool a_even = a % 2 == 0;
      bool b_even = b % 2 == 0;
      if (a_even != b_even) return a_even;

      // Jeśli dalej równe, sortuj rosnąco
      return a < b;
  };
  std::sort(v.begin(), v.end(), positiveEvenFirst);
  print(v, "positiveEven:");

  assert(positiveEvenFirst(2,-2));
  assert(positiveEvenFirst(2,-1));
  assert(positiveEvenFirst(1,-2));
  assert(!positiveEvenFirst(-2,1));
  assert(positiveEvenFirst(2, 1));
  assert(positiveEvenFirst(-2,-1));
  assert(!positiveEvenFirst(2,2));
  assert(!positiveEvenFirst(1,2));
  assert(positiveEvenFirst(0, -1));
  assert(!positiveEvenFirst(0, 1));
  assert(positiveEvenFirst(1, 0));
  assert(!positiveEvenFirst(-1, 0));


  /// 3. generator = function without parameters that return random integer number
  /// from interval [a, b] (a and b both included).
  /// Changing values of a or b should change the interval used by generator.
  srand(2022);
  int a = 0, b = 40;
  auto generator = [&](){ return a + rand() % (b - a + 1);  };  /// 3

  std::generate(v.begin(), v.end(), generator);
  print(v, "generator [0,40]:");
  a = 100, b = 200;
  std::generate(v.begin(), v.end(), generator);
  print(v, "generator [100, 200]:");


  /// 4. Function that generates arithmetic sequence with given start value and step.
  /// Changing start does not change the beginning of the sequence
  /// but a change of step influences the function output.
  int start = 5, step =2;
    auto arithmeticGenerator = [start, &step]()  { // odpalamy tylko raz glowna lambde
        int value = start; // to nam robi za zmienna statyczna
        return [value, &step]() mutable {
            int current = value;
            value += step;
            return current;
        };
    }(); // <<– generator stworzony tutaj
    // [ 4 ]
  std::generate(v.begin(), v.end(), arithmeticGenerator );
  print(v, "arithm [5,2] :");

  v.resize(20);
  start=0; step =5;
  std::generate(v.begin(), v.end(), arithmeticGenerator);
  print(v,"arithm [5,5] :");

  /// 5. Function that for given standard container (vector, list, deque)
  ///  computes l1 norm i.e. the sum of the absolute values of elements in the container.
  ///  Try to use std::accumulate algorithm with another lambda expression to implement it.
    auto l1_norm = [](const auto & container){
        //using T = std::decay_t<decltype(*std::begin(container))>;
        auto abs_sum = [](auto a, auto b)
        {
            return abs(a)+abs(b);
        };
        auto value = accumulate(begin(container), end(container), decltype(*begin(container)){} ,abs_sum); // decl type pobiera typ i dodajemy {} wywolanie konstruktora

        return value;
    };                           // [ 5 ]

  cout << "l1 norm (v) : " << l1_norm(v) << endl;
  assert(l1_norm(v) == 1050);

  vector<double> m = { 1.4, 2.4, -2.4, -4.2, -43.3 };
  cout << "l1 norm (m) : " << l1_norm(m) << endl;

  list<double> l(m.begin(), m.end());
  cout << "l1 norm (l) : " << l1_norm(l) << endl;

  /// 6. Function that for given array a and integer n returns
  /// a function with one parameter x that computes
  /// a value of a polynomial of degree n with coefficients a at the point x.
    auto polynomial = [](const double* a, int n) {
        return [a, n](double x) {
            double potega = 1.0;
            double suma = 0.0;
            for (int i = 0; i <= n; ++i) {
                suma += a[i] * potega;
                potega *= x;
            }
            return suma;
        };
    };

  double c[] = {1, 2, 3, 4, 5};
  auto w1  = polynomial(c, 4);
  cout << w1(1.0) << " " << w1(0.0) << " " << w1(2.0) << endl;

  auto w2  = polynomial(c, 2);
  cout << w2(1.0) << " " << w2(0.0) << " " << w2(2.0) << endl;

  return 0;
}
/** Expected ouput
original: 256 64 48 144 16 56 -9 -3 1 6 -2 5 9 0
center 50: 48 56 64 16 9 6 5 1 0 -2 -3 -9 144 256
negativeOdd: 6 16 48 56 64 144 256 1 5 9 0 -2 -9 -3
generator [0,40]: 2 10 15 19 37 11 27 30 37 1 0 23 38 32
generator [100, 200]: 120 115 173 107 127 186 178 171 142 176 186 124 200 132
arithm [5,2] : 5 7 9 11 13 15 17 19 21 23 25 27 29 31
arithm [5,5] : 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95 100
l1 norm (v) : 1050
l1 norm (m) : 53.7
l1 norm (l) : 53.7
15 1 129
6 1 17
 */