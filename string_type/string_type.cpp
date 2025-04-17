#include <iostream>
#include <string>

int input_fullName(std :: string firstName, std :: string lastname);
int main()
{
    std :: string str1 = "Hello";
    std :: string str2 = "World";
    std :: cout << str1 + ' ' + str2 << std :: endl;

    input_fullName("Khai", "Nguyen Phan Minh");
    return 0;
}

int input_fullName(std :: string firstName, std :: string lastname)
{
    std :: string :: size_type len;

    std :: string fullName = firstName + ' ' + lastname;
    len = fullName.length();

    std :: cout << fullName << '\n'
    << "Length: " << len << std :: endl;

    return 0;
}