#include<iostream>

void some_function(){
    double d {2.2};
    int i {7};
    d = d + i;
    i = d*i;

    std :: cout << "d: " << d << std :: endl;
    std :: cout << "i: " << i << std :: endl;
}

int main(){
    some_function();
    return 0;
}