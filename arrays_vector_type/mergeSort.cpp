#include <iostream>

void merge(int list[], int p, int q, int r)
{
    int i, j ,k;
    int nLeft = q - p + 1;
    int nRight = r - q;

    int L[nLeft];
    int R[nRight];

    for(i = 0; i < nLeft; ++i)
        L[i] = list[p + i];
    
    for(j = 0; j < nRight; ++j)
        R[j] = list[q + j + 1];
    
    i = j = 0;
    k = p;

    while(i < nLeft && j < nRight)
    {
        if(L[i] < R[j])
        {
            list[k] = L[i];
            i += 1;
        }
        else
        {
            list[k] = R[j];
            j += 1;
        }
        k += 1;
    }

    while(i < nLeft)
    {
        list[k] = L[i];
        ++i;
        ++k;
    }

    while(j < nRight)
    {
        list[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(int list[], int p, int r)
{
    int q;
    if(p >= r)
        return;
    
    q = (p + r)/2;
    mergeSort(list, p, q);
    mergeSort(list, q  +1, r);
    merge(list, p,q,r);
}

int main()
{
    int list[] = {2, 56, 34, 25, 73, 46, 89, 10, 5, 16};
    mergeSort(list, 0, sizeof(list)/sizeof(int) - 1);

    for(auto i : list)
        std::cout << i << ' ';
    return 0;
}