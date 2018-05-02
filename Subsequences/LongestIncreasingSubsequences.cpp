#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;
const long long int LLINT_MAX = LLONG_MAX;
const long long int LLINT_MIN = LLONG_MIN;
string padding (4, ' ');

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

vector <vector <llint> > lis (vector <llint> arr)
{
	vector <vector <llint> > piles = sort_to_piles(arr);
	llint max = LLONG_MIN;
	for (llint i = 0 ; i <= piles.size() - 1; i++)
	if (piles[i].size() > max)
	{
		max = piles[i].size();
	}
	vector <vector <llint> > ret;
	for (llint i = 0 ; i <= piles.size() - 1; i++) if (piles[i].size() == max) ret.push_back(piles[i]);
	return ret;
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
	
	//old code
	/*
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
	*/
	
	//demonstration code	
	vector <vector <llint> > lisResult = lis(arr);
	cout << "Longest increasing subsequence" << ((lisResult.size() > 1) ? "s" : "") << " found:\n" << padding << "Length: " << lisResult[0].size() << "\n" << padding << "Subsequence" << ((lisResult.size() > 1) ? "s" : "") << ":\n";
	for (llint i = 0 ; i <= lisResult.size() - 1; i++)
	{
		cout << padding << i + 1 << ")\t"; 
		for (llint n = 0 ; n <= lisResult[i].size() - 1 ; n++) cout << lisResult[i][n] << " ";
		cout << endl;
	}
}
