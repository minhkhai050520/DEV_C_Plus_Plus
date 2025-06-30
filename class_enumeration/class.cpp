#include<iostream>

class Vector{
    public:
        Vector(int s) : elem{new double[s]}, sz{s} {} // construct a Vector
        double& operator[](int i) {return elem[i];} // element access: subscripting
        int size() {return sz;}
    private:
        double* elem;
        int sz;
};

double read_and_sum(int s ){
    Vector v(s);

    std :: cout << "Please input " << s << "elements of double" <<std :: endl;
    for(int i = 0; i < v.size(); ++i)
        std :: cin >> v[i];
    
    double sum = 0;

    for(int i =0; i<v.size(); ++i)
        sum += v[i];
    
    return sum;
}

int main(void){

    int k;

    std :: cout << "Please input a number: ";
    
    std :: cin >> k;

    std:: cout << read_and_sum(k) << std :: endl;

    return 0;
}