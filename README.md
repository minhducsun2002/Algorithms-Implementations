### A repository storing pieces of code implementing common data structures and algorithms.

Note that:
- some snippets require `llint` to be defined as a type of integers (`int64_t`, `long`, etc.) for storing indices & values
- some requires specific header files to be included upon compilation.
  Unless GNU G++ is used, it is recommended to include STL by hand, since some snippets use `bits/stdc++.h`, which is not C++ standard.

###### Currently implemented:
- Big integers calculation (in C++11)
  - Comparison
  - Arithmetic operations: addition, subtraction, multiplication
- Mathematical matrix
- Searching
  - Binary search (on sorted array)
- Sorting
  - Merge sort
  - Selection sort
  - Bubble sort
  - Insertion sort
- Special subsequences
  - Longest increasing subsequences
  - Longest common subsequence
- Strings
  - Longest palindromic substring
