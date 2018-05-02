#include <bits/stdc++.h>

using namespace std;

typedef long long int llint;
const long long int LLINT_MAX = LLONG_MAX;
const long long int LLINT_MIN = LLONG_MIN;

//==========

vector <llint> insertionSort (vector <llint> arr)
{
	if (arr.size() == 1) return arr;
	list <llint> sorted;
	sorted.push_back(arr[0]);
	if (sorted.front() < arr[1]) sorted.push_back(arr[1]); else sorted.insert(sorted.begin(), arr[1]);
	for (llint i = 2 ; i <= arr.size() - 1 ; i++)
	{
		for (list<llint>::iterator it = sorted.begin(); it != --sorted.end() ; it++)
		{
			list <llint>::iterator itForward = it; itForward++;
			if (*it <= arr[i] && arr[i] <= *itForward)
			{
				sorted.insert(++it, arr[i]); break;
			}
			sorted.push_back(arr[i]);
		};
	};
	vector <llint> ret (sorted.begin(), sorted.end());
	return ret;
}

//=============

int main()
{
	cout << "Enter number of elements: ";
	llint arrlength; cin >> arrlength; 
	
	if (arrlength == 0)
	{
		cout << "No element to sort..The program will halt.";
		cin.get(); return 0;
	}
	
	vector <llint> arr (arrlength);
	for (llint i = 0 ; i <= arrlength - 1; i++)
	{
		cout << "Enter element " << i + 1 << " : "; cin >> arr[i];
	}
	arr = insertionSort(arr);
	cout << "\nSorted array: ";
	for (llint i = 0 ; i <= arrlength - 1; i++) cout << arr[i] << " ";
}
