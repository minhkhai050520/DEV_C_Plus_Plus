#include<iostream>

class Vector{
    public:
        Vector(int s);
        double& operator[](int i);
        int size();
    private:
        double *elem;
        int sz;
};

double& Vector::operator[](int i){
    if(i < 0 || size() <= i)
        throw std :: out_of_range{"Vector::operator[]"};
    
    return elem[i];
}

Vector :: Vector(int s): elem{new double(s)}, sz{s}{};
int Vector::size(){
    return sz;
}

void set_value(Vector& v){
    try{
        v[v.size()] = 10.55;
    }
    catch (std :: out_of_range){
        std :: cout << "something wrong";
    }
}

int main(){
    Vector v(5);
    set_value(v);
    return 0;
}