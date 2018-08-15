#include <iostream>
#include <initializer_list>
#include <pair>

typedef int32_t llint;

// llint d;

std::pair <llint, llint> ext_euclidean(llint a, llint b)
{
    if (!b)
        // d = a;
        return {1, 0};
    else
    {
        std::pair <llint, llint> out = ext_euclidean (b, a % b);
        llint tmp = out.first;
        out.first = out.second;
        out.second = tmp - (a / b) * out.second;
        return out;
    }
}

main()
{
    llint a, b; std::cin >> a >> b; 
    std::cout << ext_euclidean(a, b).first << " " << ext_euclidean(a, b).second;
}


// uncomment d to get GCD

// output specification :
// Ax + By = GCD(A, B)
// (with GCD (A, B) == d)
// x is first value of returned pair
// y is second value of returned pair
