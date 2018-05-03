#include <string>
#include <vector>
#include <iostream>

typedef long long int llint;
const long long int LLINT_MAX = LLONG_MAX;
const long long int LLINT_MIN = LLONG_MIN;
std::string padding (4, ' ');

std::vector <std::vector <llint> > sort_to_piles (std::vector <llint> arr)
{
    std::vector <std::vector <llint> > piles;

    piles.push_back(std::vector<llint>(0));
    piles[0].push_back(arr[0]);
    for (llint i = 1 ; i <= arr.size() - 1 ; i++)
    {
        bool arranged = false;
        for (llint n = 0 ; n <= piles.size() - 1 ; n++)
        {
            if (piles[n].back() < arr[i])
            {
                piles[n].push_back(arr[i]);
                arranged = true;
                break;
            }
        };
        if (!arranged)
        {
            piles.push_back(std::vector<llint>(0));
            piles.back().push_back(arr[i]);
        }
    };
    return piles;
}

std::vector <std::vector <llint> > lis (std::vector <llint> arr)
{
    std::vector <std::vector <llint> > piles = sort_to_piles(arr);
    llint max = LLONG_MIN;
    for (llint i = 0 ; i <= piles.size() - 1; i++)
    if (piles[i].size() > max)
    {
        max = piles[i].size();
    }
    std::vector <std::vector <llint> > ret;
    for (llint i = 0 ; i <= piles.size() - 1; i++) if (piles[i].size() == max) ret.push_back(piles[i]);
    return ret;
}

int main()
{
    std::cout << "Enter number of elements: ";
    llint arrlength; std::cin >> arrlength;

    std::vector <llint> arr (arrlength);
    for (llint i = 0 ; i <= arrlength - 1; i++)
    {
        std::cout << "Element number " << i + 1 << " : "; std::cin >> arr[i];
    };

    std::vector <std::vector <llint> > lisResult = lis(arr);
    std::cout << "Longest increasing subsequence" << ((lisResult.size() > 1) ? "s" : "") << " found:\n" << padding << "Length: " << lisResult[0].size() << std::endl;
    std::cout << padding << "Subsequence" << ((lisResult.size() > 1) ? "s" : "") << ":\n";
    for (llint i = 0 ; i <= lisResult.size() - 1; i++)
    {
        std::cout << padding << i + 1 << ")\t";
        for (llint n = 0 ; n <= lisResult[i].size() - 1 ; n++) std::cout << lisResult[i][n] << " ";
        std::cout << std::endl;
    }
    //usage: lis(std::vector_of_numbers)
    //return value: std::vector of LISes (each LIS is a std::vector of numbers)
}
