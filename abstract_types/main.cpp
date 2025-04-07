#include <iostream>
#include <list>

class Vector{
public:
    Vector(int s) : elem{new double[s]}, sz{s} // construct a Vector
    {
        for(int i = 0; i < s ; ++i)
            elem[i] = 10;
    }
    double& operator[](int i) {return elem[i];} // element access: subscripting
    int size() const {return sz;}
private:
    double* elem;
    int sz;
};

class Container{
public:
    virtual double& operator[](int i) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};

void use(Container& c)
{
    const int sz = c.size();

    for(int i = 0; i != sz; ++i)
        std :: cout << c[i] << "\n";
}

class Vector_container : public Container{
    Vector v;
public:
    Vector_container(int s): v(s){}
    ~Vector_container(){}
    double& operator[](int i){return v[i];}
    int size() const {return v.size();}
};

class List_container : public Container{
    std :: list<double> ld;
public:
    List_container(){};
    List_container(std::initializer_list<double>il):ld{il}{}
    ~List_container(){}
    double& operator[](int i);
    int size() const {return ld.size();}
};

double& List_container::operator[](int i)
{
    for(auto& x : ld)
    {
        if(i == 0) return x;
        --i;
    }
    throw std :: out_of_range("List container");
}

void h(){
    List_container ld{1, 2, 3, 4, 5, 6, 7, 8, 9 };
    use(ld);
}

int main()
{
    // Vector_container vc(15);
    // use(vc);
    // h();
    List_container ld{1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std :: cout << ld[3] + ld[4] << std :: endl;
    return 0;
}