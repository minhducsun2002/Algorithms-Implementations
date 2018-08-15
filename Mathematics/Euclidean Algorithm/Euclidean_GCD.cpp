typedef size_t ullint;

ullint gcd (ullint a, ullint b)
{
    return b ? gcd(b, a % b) : a;
}
