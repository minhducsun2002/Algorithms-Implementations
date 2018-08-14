#include <string>
#include <vector>
#include <algorithm>

char delimiter = '#';
bool out_of_bounds (size_t currentVal, size_t limit)
{
    return (currentVal < 0 || currentVal > limit);
}

std::string manacher(std::string str)
{
    std::string compute_table_ref (1, delimiter);
    for (char i : str) compute_table_ref += std::string (1, i) + std::string(1, delimiter);
    std::vector <std::size_t> compute_table (compute_table_ref.size());
    auto& table = compute_table;
    auto& table_ref = compute_table_ref;
    
    // computation logic
    std::size_t right = 0, center = 0;
    for (std::size_t i = 0 ; i <= compute_table_ref.size() - 1; i++)
    {
        table[i] = (right > i) ? min (right - i, table[(center << 1) - i]) : 0;
        while (table_ref[i - table[i] - 1]
        	== table_ref[i + table[i] + 1]) table[i]++;
        if (i + table[i] > right)
        {
        	right = i + table[i];
        	center = i;
        }
    };
    
    // Get maximum length palindrome and parse into proper string
    std::vector <std::size_t>::iterator central = std::max_element(compute_table.begin(), compute_table.end());
    std::size_t it = std::distance(compute_table.begin(), central);
    std::string raw_out = compute_table_ref.substr(it, *central);
    std::string out = ""; for (char i : raw_out) if (i != delimiter) out.push_back(i);
    if (raw_out.front() == delimiter)
    {
        std::string rev_out = out;
        std::reverse(rev_out.begin(), rev_out.end());
        return (rev_out + out);
    }
    else
    {
        std::string rev_out = out;
        std::reverse(rev_out.begin(), rev_out.end()); rev_out.pop_back();
        return (rev_out + out);
    }
}
