#include <iostream>
#include <vector>
#include <string>
#include "insertionsort.hpp"
#include "is_sorted.hpp"
#include "randfiller.h"

template<typename T>
void print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main(void)
{   
    randfiller rf;
    for (int i = 1; i <= 100; i++) 
    {
        int size=std::rand() %100+1;
        std::vector<int> vi;
        vi.resize(size);
        rf.fill(vi, -100, 100);

        insertionsort(vi);


        if (!is_sorted(vi)) 
        {
            return EXIT_FAILURE;
        }
    }

    std::vector<std::string> s = {
        "ciao","gatto","albero","zebra","mela",
        "banana","sole","luna","computer","polito"
    };


    insertionsort(s);

    if (!is_sorted(s)) 
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
