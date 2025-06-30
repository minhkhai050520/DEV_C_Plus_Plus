#include<iostream>

class testClass
{
public:
    void print() const;
    testClass(int = 0, int = 0, double = 0.0, char = '*');
private:
    int x;
    int y;
    double z;
    char ch;
};

void testClass::print() const
{
    std::cout << "x: " << x << " " << "y: " << y << " " << "z: " << z << " " << "ch: " << ch << std::endl;
}

testClass::testClass(int tX, int tY, double tZ, char tCh)
{
    x = tX;
    y = tY;
    z = tZ;
    ch = tCh;
}

int main()
{
    testClass testCLass1;
    testClass testCLass2(4);

    std::cout << "testClass1:\n";
    testCLass1.print();

    std::cout << "testClass2:\n";
    testCLass2.print();

    return 0;
}