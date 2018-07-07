#include <iostream>

template <typename T>
T power (T base, T exponent)
{
    if (exponent == 0) return 1;
    if (exponent & 1) return base * power (base, exponent >> 1) * power (base, exponent >> 1);
    return power (base, exponent >> 1) * power (base, exponent >> 1);
}

main()
{
    long int a, b; std::cin >> a >> b;
    std::cout << power <long int> (a, b);
}
