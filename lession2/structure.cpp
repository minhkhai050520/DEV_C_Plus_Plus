#include<iostream>

struct vector{
    int sz;
    double *elem;
};

void vector_init(vector& v, int s){
    v.elem = new double(s);
    v.sz = s;
}

double read_and_sum(int s){
    vector v;
    vector_init(v, s);

    std :: cout << "Please input the elements: ";
    for(auto i = 0; i != s; ++i){
        std :: cin >> v.elem[i];
    }

    double sum = 0;
    for(auto i = 0; i != s; ++i)
        sum += v.elem[i];
    return sum;
}

int main(){
    int s;
    double sum;
    std :: cout << "Please input the number of elements: ";
    std :: cin >> s;
    sum = read_and_sum(s);

    std :: cout << "The sum of the elements is : " << sum << std :: endl;
    return 0;
}