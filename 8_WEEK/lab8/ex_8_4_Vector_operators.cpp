#include <iostream>
using namespace std;

template<int N>
class Vector {
 int data[N];

public:
 Vector() {
  cout << " Default constr" << endl;
 }

 Vector(std::initializer_list<int> list) {
  cout << " Init list constr" << endl;
  auto it = list.begin();
  for (int i = 0; i < N; i++)
   data[i] = *it++;
 }

 Vector(const Vector &m) {
  std::copy(m.data, m.data + N, data);
  cout << " Copy constr" << endl;
 }

 template<typename Expr>
 Vector(const Expr &expr) {
  cout << " Expr constr" << endl;
  for (int i = 0; i < N; ++i)
   data[i] = expr[i];
 }

 template<typename Expr>
 Vector &operator=(const Expr &expr) {
  for (int i = 0; i < N; ++i)
   data[i] = expr[i];
  return *this;
 }

 int operator[](int index) const {
  return data[index];
 }

 int &operator[](int index) {
  return data[index];
 }

 friend ostream &operator<<(ostream &out, const Vector &m) {
  for (int i = 0; i < N; ++i)
   out << m[i] << ", ";
  return out;
 }

 static constexpr int size() { return N; }
};


// Dodawanie: AddExpr
template<typename L, typename R>
struct AddExpr {
 L left;
 R right;

 AddExpr(L &&l, R &&r) : left(l), right(r) {
 }

 int operator[](int i) const {
  return left[i] + right[i];
 }
};

// Odejmowanie: SubExpr
template<typename L, typename R>
struct SubExpr {
 L left;
 R right;

 SubExpr(L &&l, R &&r) : left(l), right(r) {
 }

 int operator[](int i) const {
  return left[i] - right[i];
 }
};

// Mnożenie skalarne: MulExpr
template<typename S, typename R>
struct MulExpr {
 S scalar;
 R right;

 MulExpr(S s, R &&r) : scalar(s), right(r) {
 }

 int operator[](int i) const {
  return scalar * right[i];
 }
};

// L ORAZ R to moze byc wektor jak i expression bo wspieraja [] operator
template<typename L, typename R>
AddExpr<L, R> operator+(L &&l, R &&r) {
 return AddExpr<L, R>(forward<L>(l), forward<R>(r));
}

template<typename L, typename R>
SubExpr<L, R> operator-(L &&l, R &&r) {
 return SubExpr<L, R>(forward<L>(l), forward<R>(r));
}

template<typename S, typename R>
MulExpr<S, R> operator*(S s, R &&r) {
 return MulExpr<S, R>(s, forward<R>(r));
}


int main() {
 using V = Vector<10>;
 V v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 V x(v);
 V y{4, 4, 2, 5, 3, 2, 3, 4, 2, 1};

 cout << "Lazy operations :\n";
 // It does not create temporary Vectors
 // It computes resulting vector coordinate by coordinate
 // (evaluating whole expression)

 auto z = v + x + 3 * y - 2 * x;
 //Vector<10> z = v + x + 3 * y - 2 * x; // solution no 2


 // SubExpr<AddExpr<AddExpr<v, x>, MulExpr<3, y>>, MulExpr<2, x>


 // AddExpr<Vector, Vector> tmp1 = operator+(v, x);
 // expr[i] → x[i] + v[i]
 // ...
 // MulExpr<int, Vector> tmp2 = operator*(3, y);
 // AddExpr<AddExpr<Vector, Vector>, MulExpr<int, Vector>> tmp3 = operator+(tmp1, tmp2);

 //SubExpr<
 //   AddExpr<AddExpr<Vector, Vector>, MulExpr<int, Vector>>,
 //   MulExpr<int, Vector>> tmp5 = operator-(tmp3, tmp4);


 // Vector(const Expr& expr) // ← tu jest pętla i obliczanie

 cout << z << endl;

 // Computes only one coordinate of Vector
 int e = (z + x + y)[2];
 cout << " e = " << e << endl;
 return 0;
}

/**
 Init list constr
 Copy constr
 Init list constr
Lazy operations :
 Default constr
12, 12, 6, 15, 9, 6, 9, 12, 6, 3,
e = 11
 */
