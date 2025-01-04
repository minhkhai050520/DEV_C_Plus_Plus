#include <iostream>

class Vector{
    public:
        Vector(int s);
        double& operator[](int i);
        int size();
    private:
        double* elem;
        int sz;
};

Vector :: Vector(int s) : elem(new double[s]), sz{s}{};
double& Vector::operator[](int i){
    return elem[i];
}
int Vector::size(){
    return sz;    
}

int main(){
    Vector v(5);

    int mul = 1;

    std :: cout << "Input five numbers of double: ";
    for(int i = 0; i < v.size(); ++i)
        std :: cin >> v[i];
    
    for(auto i = 0; i <v.size(); ++i)
        mul *= v[i];

    std :: cout << "The result: ";

    std :: cout << mul;

    return 0;
}
