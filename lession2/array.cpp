#include<iostream>

int main(){
    int v[] = {1,2,3,4,5,6,7,8,9};

    for(auto& x : v)
        std :: cout << x << " " ;
    return 0;
}