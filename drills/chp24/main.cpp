#include <iostream>
#include <cmath>
#include <climits>
#include <complex>

#include "include/Matrix.h"

void mySqrt() {
    int val;
    std::cin>>val;
    double out = sqrt(val);
    if (out <= std::numeric_limits<double>::max())
        std::cout<<out<<std::endl;
    else 
        std::cout<<"no square root" << std::endl;
}

bool goodDouble(double val) {
    return val <= std::numeric_limits<double>::max();
}

Numeric_lib::Matrix<double, 2> mult_table(int n, int m) {
    Numeric_lib::Matrix<double, 2> out(n+1,m+1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            out[i][j] = i * j;
        }
    }
    return out;
}

int main() {
    std::cout << "Sizeof char: " << sizeof(char) << "bytes." << std::endl;
    std::cout << "Sizeof short: " << sizeof(short) << "bytes." << std::endl;
    std::cout << "Sizeof int: " << sizeof(int) << "bytes." << std::endl;
    std::cout << "Sizeof long: " << sizeof(long) << "bytes." << std::endl;
    std::cout << "Sizeof float: " << sizeof(float) << "bytes." << std::endl;
    std::cout << "Sizeof double: " << sizeof(double) << "bytes." << std::endl;
    std::cout << "Sizeof int*: " << sizeof(int*) << "bytes." << std::endl;
    std::cout << "Sizeof double*: " << sizeof(double*) << "bytes." << std::endl;
    
    Numeric_lib::Matrix<int> a(10);
    std::cout << "Sizeof Matrix<int>(10) : " << sizeof(a) << "bytes." << std::endl;
    Numeric_lib::Matrix<int> b(10);
    std::cout << "Sizeof Matrix<int>(100) : " << sizeof(b) << "bytes." << std::endl;
    Numeric_lib::Matrix<double> c(10);
    std::cout << "Sizeof Matrix<double>(10) : " << sizeof(c) << "bytes." << std::endl;
    Numeric_lib::Matrix<int, 2> d(10, 10);
    std::cout << "Sizeof Matrix<int, 2>(10, 10) : " << sizeof(d) << "bytes." << std::endl;
    Numeric_lib::Matrix<int, 3> e(10, 10, 10);
    std::cout << "Sizeof Matrix<int, 3>(10, 10, 10) : " << sizeof(e) << "bytes." << std::endl;
    
    std::cout << "Number of elements in a:" << a.size() << std::endl;
    std::cout << "Number of elements in b:" << b.size() << std::endl;
    std::cout << "Number of elements in c:" << c.size() << std::endl;
    std::cout << "Number of elements in d:" << d.size() << std::endl;
    std::cout << "Number of elements in e:" << e.size() << std::endl;

    mySqrt();

    Numeric_lib::Matrix<double> mat(10);
    for (int i = 0; i < 10; ++i) {
        double val;
        std::cin>>val;
        mat[i] = val;
    }
    for (double i = 0; i < 10; ++i)
        std::cout<<mat[i]<<" ";
    std::cout<<std::endl;
{
    int n,m;
    std::cin>>n>>m;
    Numeric_lib::Matrix<double, 2> mult(mult_table(n,m));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            std::cout << mult[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}
    std::complex<double> sum;
    for (int i = 0; i < 10; ++i) {
        std::complex<double> val;
        std::cin >> val;
        sum += val;
    }
    std::cout << sum << std::endl;

    Numeric_lib::Matrix<int, 2> m(2,3);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> m[i][j];
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << m[i][j] << " "; 
        }
        std::cout << std::endl;
    }
}