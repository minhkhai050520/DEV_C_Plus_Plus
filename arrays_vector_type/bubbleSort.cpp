#include <iostream>

void bubleSort(int list[], int length)
{
    int interation;
    int index;
    int temp;
    
    for(interation = 1; interation < length; interation ++)
    {
        for(index = 0; index < length - interation; index++)
        {
            if(list[index] > list[index+1])
            {
                temp = list[index];
                list[index] = list[index+1];
                list[index+1] = temp;
            }
        }
    }
}

int main()
{
    int list[] = {10, 15, 23, 1, 4, 17, 88, 55};
    bubleSort(list, sizeof(list)/sizeof(int));

    for(auto x : list)
        std::cout<<x << ' ';
    return 0;
}