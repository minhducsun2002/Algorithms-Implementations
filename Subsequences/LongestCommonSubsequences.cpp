#include <algorithm>
#include <string>
#include <iostream>
#include <climits>

typedef long long int llint;
const long long int MAX_STRING_SIZE_A = 1000;
const long long int MAX_STRING_SIZE_B = 1000;

llint arr[MAX_STRING_SIZE_A][MAX_STRING_SIZE_B];
std::string lcs (std::string str1, std::string str2)
{
	// popping strings until their last character matches
	while (str1.back() != str2.back() && str1.back() != *next(str2.rbegin()) && str2.back() != *next(str1.rbegin()))
	{
		str1.pop_back(); str2.pop_back();
	};
	if (str1.back() != str2.back()) if (str1.back() == *next(str2.rbegin())) str2.pop_back(); else str1.pop_back();



	str1 = " " + str1; str2 = " " + str2;	//padding
	//arr[0][0] = (str1[0] == str2[0]) ? 1 : 0;
	
	for (llint i = 1 ; i <= str1.length() - 1 ; i++)
	for (llint n = 1 ; n <= str2.length() - 1 ; n++)
	{
		if (str1[i] == str2[n]) arr[i][n] = arr[i - 1][n - 1] + 1;
		else arr[i][n] = (arr[i - 1][n] > arr[n - 1][i]) ? arr[i - 1][n] : arr[n - 1][i];
	};
	//std::cout << "Length of the longest common subsequence : " << arr[str1.length() - 1][str2.length() - 1] << std::endl;
	
	std::string out = "";
	llint i = str1.length() - 1, n = str2.length() - 1;
	while (i >= 1 && n >= 1)
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
	std::reverse(out.begin(), out.end());
	return out;
}

int main()
{
	std::cout << "Enter first string: "; std::string str1; std::cin >> str1;	//size should be smaller than MAX_STRING_SIZE_A
	std::cout << "Enter second string: "; std::string str2; std::cin >> str2;	//size should be smaller than MAX_STRING_SIZE_B
	std::cout << "Subsequence: " << lcs(str1, str2) << std::endl;
}
