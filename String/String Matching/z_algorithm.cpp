#include <bits/stdc++.h>
using namespace std;

#ifdef ENG
string filename = "hash2";
string input_ext = "inp", output_ext = "out", debug_ext = "debugging";
string 	input_filename = filename + '.' + input_ext,
		output_filename = filename + '.' + output_ext,
		debug_filename = filename + '.' + debug_ext;
#endif


typedef int64_t llint;
typedef size_t ullint;

char delimiter = '#';

vector <llint> z (string b, string a)
// b is text, a is pattern
{
	string z_table_ref = a + delimiter + b;

	vector <llint> z_table (z_table_ref.size());

	for (llint i = 1 ; i <= z_table_ref.size() - 1 ; i++)
		// first entry is meaningless
	{
		{
			llint length = 0;
			for (llint n = i ; n <= z_table_ref.size() - 1 ; n++)
			{
				if (z_table_ref[n - i] == z_table_ref[n])
					length++;
				else break;
			}
			z_table[i] = length;
		}
	};
	return z_table;
}

main()
{
	string str, pattern; cin >> str >> pattern;
	vector <llint> out = z(str, pattern);

	cout << "Matches found :: ";
	if (out.size())
		for (llint i = 0 ; i <= out.size() - 1; i++)
			{
				if (out[i] == pattern.size()) cout << out[i];
			}
	else cout << "No matches found!";
}