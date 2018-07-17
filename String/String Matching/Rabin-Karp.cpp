#include <bits/stdc++.h>
using namespace std;

typedef int64_t llint;

// Rabin-Karp algorithm for string matching problem
const llint accuracy = 1e9 + 7;
// Modify the accuracy (i.e. 'modulo') for your own need.

const llint base = 256;
// let's assume ASCII charset

vector <llint> rabin_karp (string str, string pattern, llint modulo)
{

	// calibration, preventing errors
	for (auto &I : str) I++;
	for (auto &I : pattern) I++;

	// precompute the powers of base
	vector <llint> power_table (str.size());
	power_table.front() = 1;
	for (llint i = 1 ; i <= str.size() - 1 ; i++) power_table[i] = (power_table[i - 1] * base) % modulo;

	vector <llint> string_hash (str.size() + 1);
	// hashing for document i.e. text to find pattern
	string_hash.front() = 0;
	for (llint i = 0 ; i <= str.size() - 1 ; i++)
	{
		// string_hash[i + 1] = string_hash[i] * base + (str[i] - 'a');
		string_hash[i + 1] = string_hash[i] * base + (str[i]);
		string_hash[i + 1] %= modulo;
	};

	string_hash.erase(string_hash.begin());

	vector <llint> out;

	llint pattern_hash = 0;
	for (char I : pattern)
	{
		pattern_hash = pattern_hash * base + I;
		pattern_hash %= modulo;
	}

	for (llint i = 0 ; i <= str.size() - pattern.size() ; i++)
	{
		if (pattern_hash == 
			// calculate hash for this match
			(string_hash[i + pattern.size() - 1] - string_hash[i] * power_table[pattern.size()] + modulo * 30) % modulo
			)
			out.push_back(i);
	}
	return out;
}

main()
{
	string str, pattern; cin >> str >> pattern;
	vector <llint> out = rabin_karp(str, pattern, accuracy);

	if (!out.size()) 
		return cout << "No matching positions found !", 0;
	else
	{
		cout << "Positions found :: ";
		for (auto &Z : out) cout << Z << " ";
	}
}