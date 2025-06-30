#include<iostream>
#include <complex>

int main(){
    double d {2.3};
    double i = 7;

    std :: complex<double> z{d,i};

    std :: cout << z.real() << std :: endl;
    std :: cout << z.imag() << std :: endl;   
    return 0;
}