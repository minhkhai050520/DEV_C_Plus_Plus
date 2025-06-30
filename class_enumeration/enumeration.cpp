#include <iostream>

enum class Traffic_light {green, yellow, red};

Traffic_light& operator++(Traffic_light& t){
    switch(t){
        case Traffic_light :: green :
            t = Traffic_light :: yellow;
            break;
        case Traffic_light :: yellow:
            t = Traffic_light :: red;
            break;
        case Traffic_light :: red :
            t = Traffic_light :: green;
            break;
    }
    return t;
}

int main(){
    // std :: cout << "Hello Nguyen Phan Minh Khai" <<std :: endl;
    Traffic_light next;
    Traffic_light light = Traffic_light :: red;
    next = ++light;

    if(next == Traffic_light :: red)
        std :: cout << "Yes" << std :: endl;
    else
        std :: cout << "No" << std :: endl;
    return 0;
}