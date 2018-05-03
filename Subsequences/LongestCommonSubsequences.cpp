#include <bits/stdc++.h>

using namespace std;

typedef long long int llint;
const long long int LLINT_MAX  = LLONG_MAX;
const long long int LLINT_MIN  = LLONG_MIN;
const long long int LLINT_SIZE = sizeof(llint);
const long long int MAX_STRING_SIZE_A = 1000;
const long long int MAX_STRING_SIZE_B = 1000;

llint arr[MAX_STRING_SIZE_A][MAX_STRING_SIZE_B];

int main()
{
	cout << "Enter first string: "; string str1; cin >> str1;	//size should be smnaller than MAX_STRING_SIZE_A
	cout << "Enter second string: "; string str2; cin >> str2;	//size should be smnaller than MAX_STRING_SIZE_B
	
	str1 = " " + str1; str2 = " " + str2;	//padding
	//arr[0][0] = (str1[0] == str2[0]) ? 1 : 0;
	
	for (llint i = 1 ; i <= str1.length() - 1 ; i++)
	for (llint n = 1 ; n <= str2.length() - 1 ; n++)
	{
		if (str1[i] == str2[n]) arr[i][n] = arr[i - 1][n - 1] + 1;
		else arr[i][n] = (arr[i - 1][n] > arr[n - 1][i]) ? arr[i - 1][n] : arr[i][n - 1];
	};
	cout << "Length of the longest common subsequence : " << arr[str1.length() - 1][str2.length() - 1] << endl;
	
	string out = "";
	llint i = str1.length() - 1, n = str2.length() - 1;
	while (i >= 0 && n >= 0)
	{
		if (str1[i] == str2[n])
		{
			out.push_back(str1[i]);
			i--; n--;
		}
		else if (arr[i - 1][n] > arr[i][n - 1])
		{
			i--;
		}
		else n--;
	}
	reverse(out.begin(), out.end());
	cout << "Subsequence: " << out << endl;
}
