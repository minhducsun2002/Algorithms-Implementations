#include <vector>
#include <algorithm>
#include <iostream>	// unneeded for usage of the function

// Be noted that this searching method will only work if the array is sorted.

typedef int32_t llint;
 
// binary search algorithm to find a specific value in a sorted array
 
llint binary_search (llint query, std::vector <llint> &vct, llint start, llint end)
{
	if (start == end) return (vct[start] == query ? start : -1);
	llint mid = (start + end) >> 1;
	if (vct[mid] < query) return binary_search(query, vct, mid + 1, end);
	else return binary_search(query, vct, start, mid);
}
 
main()
{
	llint arrayLength; std::cin >> arrayLength;
	std::vector <llint> vct (arrayLength);
	for (llint &i : vct) std::cin >> i;
	std::sort (vct.begin(), vct.end());
 
	std::cout << "Enter the value to find: \n";
	llint query; std::cin >> query;
	std::cout << "Position found: " << binary_search (query, vct, 0, vct.size() - 1);
}
