#include <vector>
#include <string>

// uses the same partial match computation method as KMP.
// see https://github.com/minhducsun2002/Algorithms-Implementations/blob/master/String/String%20Matching/KnuthMorrisPratt.cpp
void partial_match_compute (std::string pattern, std::vector <std::size_t>& table)
{
	std::size_t length = 0;
	table.front() = 0;

	std::size_t i = 1;
	while (i <= pattern.size() - 1)
	{
		if (pattern[i] == pattern[length])
			table[i++] = ++length;
		else
			if (length)
				length = table[length - 1];
			else
				table[i++] = 0;
	}
}

auto z (string text, string pattern, char delimiter = '$')
{
    // assume the delimiter does not occur in either pattern or text
    std::vector <std::size_t> compute_table (text.size() + pattern.size() + 1);
    partial_match_compute(pattern + delimiter + text, compute_table);
    std::vector <std::size_t> out;
    for (std::size_t i = pattern.size() + 1 ; i <= compute_table.size() - 1 ; i++)
        if (compute_table[i] == pattern.size()) out.push_back(i - (pattern.size() << 1) + 1);
    return out;
}
