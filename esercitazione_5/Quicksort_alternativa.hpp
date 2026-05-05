#include <iostream>
#include <vector>
#include <algorithm>

#include "quicksort.hpp"
#include "insertionsort.hpp"

template<typename T>
void quicksort(std::vector<T>& A, int p, int r)
{
    const int THRESHOLD = 20;

    if (r - p < THRESHOLD)
    {
        insertionsort(A);
        return;
    }

    if (p < r)
    {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}