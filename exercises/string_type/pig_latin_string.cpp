/*
In this programming example, we write a program that prompts the user to input a
string and then outputs the string in the pig Latin form. The rules for converting a
string into pig Latin form are as follows:

- If the string begins with a vowel, add the string "-way" at the end
of the string. For example, the pig Latin form of the string "eye" is
"eye-way".

- If the string does not begin with a vowel, first add "-" at the end of
the string. Then rotate the string one character at a time; that is,
move the first character of the string to the end of the string until the
first character of the string becomes a vowel. Then add the string
"ay" at the end. For example, the pig Latin form of the string
"There" is "ere-Thay".

- Strings such as "by" contain no vowels. In cases like this, the letter
y can be considered a vowel. So, for this program the vowels are a,e, i, o, u, y, A, E, I, O, U, and Y. Therefore, the pig Latin form of
"by" is "y-bay".

- Strings such as "1234" contain no vowels. The pig Latin form
of the string "1234" is "1234-way". That is, the pig Latin form
of a string that has no vowels in it is the string followed by the
string "-way".

** Input:  Input to the program is a string
** Output: Output of the program is the string in the pig Latin form
*/

#include<iostream>

bool isVowel(char ch)
{
    switch (ch)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'Y':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            return true;
        default:
            return false;
    }
}

std::string rotate (std::string pStr)
{
    std::string::size_type len = pStr.length();
    std::string rStr;
    rStr = pStr.substr(1, len -1) + pStr[0];
    return rStr;
}

std::string pigLatinString(std::string pStr)
{
    std::string::size_type len;
    bool foundVowel;

    std::string::size_type counter;

    if(isVowel(pStr[0]))
        pStr = pStr + "-way";
    else
    {
        pStr = pStr + '-';
        pStr = rotate(pStr);

        len = pStr.length();
        foundVowel = false;

        for(counter = 1; counter < len -1; counter ++)
            if(isVowel(pStr[0]))
            {
                foundVowel = true;
                break;
            }
            else
                pStr = rotate(pStr);
        
        if(!foundVowel)
            pStr = pStr.substr(1, len) + "-way";
        else
            pStr = pStr + "ay";
    }
    return pStr;
}

int main()
{
    std::string str;

    std::cout <<"Enter a tring: ";
    std::cin >> str;
    std::cout << std::endl;

    std::cout <<"The pig Latin form of " << str << " is: "
                << pigLatinString(str) << std::endl;
    return 0;
}