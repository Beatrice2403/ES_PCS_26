#include <vector>
#include <string>
#include <cstdlib>
#include "is_sorted.hpp"
#include "mergesort.hpp"
#include "randfiller.h"

int main()
{
    randfiller rf;

    for (int i = 0; i < 100; i++)
    {
        int size = rand() % 100 + 1;
        std::vector<int> v(size);

        rf.fill(v, -100, 100);

        mergesort(v, 0, v.size()-1);

        if (!is_sorted(v))
            return EXIT_FAILURE;
    }

    std::vector<std::string> s = {
        "ciao","gatto","albero","zebra","mela",
        "banana","sole","luna","computer","polito"
    };

    mergesort(s, 0, s.size()-1);

    if (!is_sorted(s))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}