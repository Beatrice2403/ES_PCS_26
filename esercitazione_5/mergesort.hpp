#include <iostream>
#include <vector>
#include <algorithm>


template<typename T>
void merge(std::vector<T>& A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<T> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2)
        A[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];
}

// mergesort
template<typename T>
void mergesort(std::vector<T>& A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A, p, q, r);
    }
}