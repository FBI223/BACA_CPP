//Marcin Sztukowski

#include <iostream>
#include <algorithm>
#include <utility>


using namespace std;

/*
 * https://ww2.ii.uj.edu.pl/~kapela/emcpp/talks/02-ModernClassDesign.html
 */




class Matrix {

    size_t N;
    size_t M;
    double* data;

public:

    Matrix() : N(0), M(0), data(nullptr) {
        cout << "default constructor  " << endl;
    }

    Matrix(size_t n, size_t m) : N(n), M(m) {
        data = new double[n * m]();
        std::fill(data, data + (n * m), 0.0);
        cout << "basic constructor  " << endl;
    }


    Matrix(const Matrix& other) : N(other.N), M(other.M), data(nullptr) {
        if (other.data) {
            data = new double[N * M];
            std::copy(other.data, other.data + N * M, data);
        }
        std::cout << "Copy Constructor\n";
    }



    Matrix(std::initializer_list<std::initializer_list<double>> list )   {
        size_t max_length_row = 0;

        for (const auto & row : list )
        {
            max_length_row = std::max(max_length_row,row.size());
        }

        N=list.size();
        M=max_length_row;
        cout << "constructor of " << N << " x " << "M matrix form initializer_list" << endl;
             data=new double[N*M];
        auto p = data;

        for (const auto & row : list)
        {
            auto p2 = std::copy(row.begin(),row.end(),p);
            std::fill(p2,p+=M,0.0);
        }

    }

    double operator()(size_t row, size_t col) const {
        return data[(row-1)*M+col-1];
    }

    double& operator()(size_t row, size_t col) {
        return data[(row-1)*M+col-1];
    }



    Matrix & operator=(const Matrix & other)
    {
        if ( this == &other ) {return *this;}

        cout << "assign constructor ( deep copy )  " << endl;
        N=other.N;
        M=other.M;
        double* data2 = nullptr;
        if ( N*M >0 )
        {
            data2 = new double[N * M];
            std::copy(other.data,other.data + N*M, data2);
        }

        data = data2;
        return *this;
    }


    Matrix (Matrix && other) noexcept  : N(other.N) , M(other.M) , data(other.data)
    {
        other.data = nullptr;
        other.N = 0 ;
        other.M = 0 ;
        cout << " move constructor " << endl;
    }
    Matrix & operator=  (Matrix && other) noexcept
    {
        if (this != &other) {
            delete[] data;
            N = other.N;
            M = other.M;
            data = other.data;
            other.data = nullptr;
            other.N = 0;
            other.M = 0;
        }
        std::cout << "Move Assignment\n";
        return *this;
    }

    Matrix operator-() const   {
        Matrix result(N, M);
        for (size_t i = 0; i < N * M; ++i) {
            result.data[i] = -data[i];
        }
        return std::move(result);
    }


    friend std::ostream & operator<<(std::ostream & out, const Matrix & a)
    {
        for (int i = 0; i < a.N; ++i) {
            for (int j = 0; j < a.M; ++j) {
                out << a.data[i * a.M + j] << " ";
            }
            out << '\n';
        }
        return out;
    }


    ~Matrix(){
        delete[] data;
        cout << "Destructor of matrix "<< endl;
    }

};



class MatrixWithLabel : public Matrix {
    string label="A";
    using Matrix::Matrix;

    public:

    MatrixWithLabel(std::initializer_list<std::initializer_list<double>> list)
            : Matrix(list) {}  // Jawne wywołanie konstruktora bazowego



    MatrixWithLabel(string  label, size_t numberOfRows, size_t numberOfColumns)
            : Matrix(numberOfRows, numberOfColumns), label(std::move(label)) {}


    MatrixWithLabel(const MatrixWithLabel& other) : Matrix(other), label(other.label) {
        cout << "Copy Constructor (MatrixWithLabel)\n";
    }

    MatrixWithLabel(MatrixWithLabel&& other) noexcept
            : Matrix(std::move(other)), label(std::move(other.label)) {
        cout << "Move Constructor (MatrixWithLabel)\n";
    }

    MatrixWithLabel& operator=(const MatrixWithLabel& other) {
        if (this == &other) return *this;
        Matrix::operator=(other);
        label = other.label;
        cout << "Copy Assignment (MatrixWithLabel)\n";
        return *this;
    }

    MatrixWithLabel& operator=(MatrixWithLabel&& other) noexcept {
        if (this != &other) {
            Matrix::operator=(std::move(other));
            label = std::move(other.label);
        }
        cout << "Move Assignment (MatrixWithLabel)\n";
        return *this;
    }

    void setLabel(const std::string& in)
    {
        this->label=in;
    }

    const std::string& getLabel(){
        return label;
    }


    ~MatrixWithLabel() { cout << "Destructor (MatrixWithLabel)\n"; }

};




int main(){
	
	Matrix m1;
	Matrix m2(3,4); 
	Matrix m3({{1,2,3},{32, 23, 22},{3,234,23,44}});
	cout << m2(1,1) << endl;  // 0
	cout << m3(2,2) << endl;  // 23
	cout << m3; 



    cout << "Copy semantics \n";
	Matrix m4 = m2;
	m4 = m3;


	cout << "Move semantics \n";
	Matrix m7 = std::move(m2);
	m4 = -m3;



	cout << "Copy elision \n";
	Matrix m6 = -m4;
	Matrix * pm = new Matrix(-m4);
	cout << m6(2,1) << endl; // 32




	cout << "Inheritance \n";

	MatrixWithLabel l0("B", 3, 4);
	MatrixWithLabel l1({{1,2},{4,5}});
    cout << l1.getLabel() << " abcd " << endl;
	l1.setLabel("A");
	MatrixWithLabel l2 = l1;
	MatrixWithLabel l3 = std::move(l1);
	cout << l2.getLabel() << " " << l3.getLabel() << endl;
	// 	cout << l1.getLabel() << endl;


	return 0;
}
