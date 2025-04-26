#include <iostream>
#include <string>

int input_fullName(std :: string firstName, std :: string lastname);
int find_string(std :: string origin_string, std :: string search_string);
int main()
{
    std :: string str1 = "Hello";
    std :: string str2 = "World";
    std :: cout << str1 + ' ' + str2 << std :: endl;

    input_fullName("Khai", "Nguyen Phan Minh");
    std :: cout << find_string("Outside it is cloudy and warm.", "is") << "\n";
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

int find_string(std :: string origin_string, std :: string search_string)
{
    return origin_string.find(search_string);
}