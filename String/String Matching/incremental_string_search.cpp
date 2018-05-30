#include <string>
#include <vector>
#include <iostream> //not required to use inc_search()

typedef long long int llint;
typedef unsigned long long int ullint;

std::vector <bool> inc_search(std::string sample, std::string pattern)
{
    std::vector <bool> positional (sample.size(), 1);
    for (long long int i = 0 ; i <= pattern.size() - 1 ; i++)
    {
        for (llint n = 0 ; n <= sample.size() - 1 ; n++)
        {
            if (n + i < sample.size())  // if not out-of-bounds
            {
                if (positional[n])
                positional[n] = sample[n + i] == pattern[i];
            }
        }
    }
    return positional;
}

int main()
{
    std::string text; std::cin >> text;
    std::string pattern; std::cin >> pattern;
    std::vector <bool> out = inc_search(text, pattern);
    for (llint i = 1 ; i <= out.size() ; i++) std::cout << (out[i - 1] ? std::to_string(i) + std::string(" ") : std::string("")); std::cout << std::endl;
}
