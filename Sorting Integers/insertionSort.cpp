#include <climits>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>

typedef long long int llint;
const long long int LLINT_MAX = LLONG_MAX;
const long long int LLINT_MIN = LLONG_MIN;

std::vector <llint> insertionSort (std::vector <llint> arr)
{
    if (arr.size() == 1) return arr;
    std::list <llint> sorted;
    sorted.push_back(arr[0]);
    if (sorted.front() < arr[1]) sorted.push_back(arr[1]); else sorted.insert(sorted.begin(), arr[1]);
    for (llint i = 2 ; i <= arr.size() - 1 ; i++)
    {
        for (std::list<llint>::iterator it = sorted.begin(); it != sorted.end() ; it++)
        {
            std::list <llint>::iterator itForward = it; itForward++;
            if (*it <= arr[i] && arr[i] <= *itForward)
            {
                sorted.insert(itForward, arr[i]); break;
            }
            sorted.push_back(arr[i]);
        };
    };
    std::vector <llint> ret (sorted.begin(), sorted.end());
    return ret;
}

int main()
{
    std::cout << "Enter number of elements: ";
    llint arrlength; std::cin >> arrlength;

    if (arrlength == 0)
    {
        std::cout << "No element to sort..The program will halt.";
        std::cin.get(); return 0;
    }

    std::vector <llint> arr (arrlength);
    for (llint i = 0 ; i <= arrlength - 1; i++)
    {
        std::cout << "Enter element " << i + 1 << " : "; std::cin >> arr[i];
    }
    arr = insertionSort(arr);
    std::cout << "\nSorted array: ";
    for (llint i = 0 ; i <= arrlength - 1; i++) std::cout << arr[i] << " ";
}
