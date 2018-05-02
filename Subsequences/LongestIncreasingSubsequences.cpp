#include <bits/stdc++.h>

using namespace std;

typedef long long int llint;
const long long int LLINT_MAX = LLONG_MAX;
const long long int LLINT_MIN = LLONG_MIN;

vector <vector <llint> > sort_to_piles (vector <llint> arr)
{	
	vector <vector <llint> > piles;
	
	piles.push_back(vector<llint>(0));
	piles[0].push_back(arr[0]);
	for (llint i = 1 ; i <= arr.size() - 1 ; i++)
	{
		bool arranged = false;
		for (llint n = 0 ; n <= piles.size() - 1 ; n++)
		{
			if (piles[n].back() <= arr[i])
			{
				piles[n].push_back(arr[i]);
				arranged = true;
				break; 
			}
		};
		if (!arranged)
		{
			piles.push_back(vector<llint>(0));
			piles.back().push_back(arr[i]);
		}
	};
	
	return piles;
	/*
	vector <llint> lisLength; for (llint i = 0 ; i <= piles.size() - 1 ; i++) lisLength.push_back(piles[i].size());
	cout << *max_element(lisLength.begin(),lisLength.end());
	*/
}

int main()
{
	cout << "Enter number of elements: ";
	llint arrlength; cin >> arrlength;
	
	vector <llint> arr (arrlength);
	for (llint i = 0 ; i <= arrlength - 1; i++)
	{
		cout << "Element number " << i + 1 << " : "; cin >> arr[i];
	};
	vector <vector <llint> > piles = sort_to_piles(arr);
	llint max = LLONG_MIN, max_id = 0;
	for (llint i = 0 ; i <= piles.size() - 1; i++)
	if (piles[i].size() > max)
	{
		max = piles[i].size();
		max_id = i;
	}
	cout << "Longest increasing subsequence found:\n\tLength: " << max << "\n\tSubsequence: ";
	for (llint i = 0 ; i <= piles[max_id].size() - 1 ; i++) cout << piles[max_id][i] << ' ';
}
