#include <cmath>

typedef int32_t llint;
typedef size_t ullint;

ullint gcd (llint a, llint b)
{
    return b ? gcd (abs(b), abs(a) % abs(b)) : abs(a);
}
