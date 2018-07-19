### A repository storing pieces of code implementing common data structures and algorithms.

Note that:
- some snippets require `llint` to be defined as a type of integers (`int64_t`, `long`, etc.) for storing indices & values
- some requires specific header files to be included upon compilation.
  Unless GNU G++ is used, it is recommended to include STL by hand, since some snippets use `bits/stdc++.h`, which is not C++ standard.

###### Currently implemented:
- [Big integers calculation (in C++11)](/Big%20Integers)
  - Comparison
  - Arithmetic operations: addition, subtraction, multiplication
- [Mathematical matrix](/Matrix)
- [Searching](/Searching)
  - [Binary search (on sorted array)](/Searching/BinarySearch.cpp)
- [Sorting](/Sorting%20Integers)
  - [Merge sort](/Sorting%20Integers/mergeSort.cpp)
  - [Selection sort](/Sorting%20Integers/selectionSort.cpp)
  - [Bubble sort](/Sorting%20Integers/bubbleSort.cpp)
  - [Insertion sort](/Sorting%20Integers/insertionSort.cpp)
- [Special subsequences](/Subsequences)
  - [Longest increasing subsequences](/Subsequences/LongestIncreasingSubsequences.cpp)
  - [Longest common subsequence](/Subsequences/LongestCommonSubsequence.cpp)
- [Strings](/String)
  - [Longest palindromic substring](/String/Palindromic%20Substring)
    - [Manacher's algorithm](/String/Palindromic%20Substring/LongestPalindromicSubstring_Manacher.cpp)
