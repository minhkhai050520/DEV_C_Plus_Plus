#include <iostream>

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(int list[], int length)
{
    int smallestIndex;
    int index;
    int miniIndex;

    for(index = 0; index < length - 1; ++index)
    {
        smallestIndex = index;

        for(miniIndex = index + 1; miniIndex < length ; ++miniIndex)
            if(list[miniIndex] < list[smallestIndex])
                smallestIndex = miniIndex;
        
        swap(list[index], list[smallestIndex]);
    }
}

int main()
{
    int list[] = {2, 56, 34, 25, 73, 46, 89, 10, 5, 16};
    selectionSort(list, sizeof(list)/sizeof(int));

    for(auto i : list)
        std::cout << i << ' ';
    return 0;
}