#include <bits/stdc++.h>
using namespace std;
 
typedef long long int llint;
 
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
	llint arrayLength; cin >> arrayLength;
	vector <llint> vct (arrayLength);
	for (llint &i : vct) cin >> i;
	sort (vct.begin(), vct.end());
 
	cout << "Enter the value to find: \n";
	llint query; cin >> query;
	cout << "Position found: " << binary_search (query, vct, 0, vct.size() - 1);
}