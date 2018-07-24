#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;
// Knuth-Morris-Pratt string matching algorithm

void partial_match_compute (string pattern, vector <llint>& table)
{
	llint length = 0;
	table.front() = 0;

	llint i = 1;
	while (i <= pattern.size() - 1)
	{
		if (pattern[i] == pattern[length])
		{
			length++;
			table[i] = length;
			i++;
		}
		else
		{
			if (length)
				length = table[length - 1];
			else
			{
				table[i] = 0; i++;
			}
		}
	}
}

vector <llint> kmp (string str, string pattern)
{
	vector <llint> partial_match_table (pattern.size());
	partial_match_compute(pattern, partial_match_table);
	vector <llint> out;

	llint str_index = 0, pattern_index = 0;
	while (str_index <= str.size() - 1)
	{
		if (pattern[pattern_index] == str[str_index])
		{
			pattern_index++;
			str_index++;
		};
		if (pattern_index == pattern.size())
		{
			out.push_back(str_index - pattern_index);
			pattern_index = partial_match_table[pattern_index - 1];
		}
		else
			if (str_index <= str.size() - 1 && pattern[pattern_index] != str[str_index])
			{
				if (pattern_index)
					pattern_index = partial_match_table[pattern_index - 1];
				else 
					str_index++;
			}
	}
	return out;
}



main()
{
	string str, pattern; 
	cin >> str >> pattern;
	vector <llint> out = kmp (str, pattern);
	cout << "Positions found: "; for (llint I : out) cout << ++I << " ";
}