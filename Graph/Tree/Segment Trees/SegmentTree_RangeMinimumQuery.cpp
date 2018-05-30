#include <bits/stdc++.h>
#include <iostream> // this header isn't required to use the wrapped functions

using namespace std;

typedef long long int llint;
const long long int LLINT_MAX = LLONG_MAX;
const long long int LLINT_MIN = LLONG_MIN;


// ============
const long long int MAX_ARRAY_LENGTH = 100000;
llint arr[MAX_ARRAY_LENGTH]; 
llint segtree[MAX_ARRAY_LENGTH];
void buildtree(llint first_element, llint last_element, llint treenode)
{
    if (first_element == last_element)
    {
        segtree[treenode] = arr[first_element];
        return;
    }
    llint mid = (last_element + first_element) >> 1;
    buildtree(first_element, mid, (treenode << 1) + 1);
    buildtree(mid + 1, last_element, (treenode << 1) + 2);
    segtree[treenode] = min(segtree[(treenode << 1) + 1], segtree[(treenode << 1) + 2]);
}

llint rmq(llint first_element, llint last_element, llint treetop, llint arr_first, llint arr_second)
{
    if (arr_first <= first_element && last_element <= arr_second) return segtree[treetop];
    if (arr_first > last_element || arr_second < first_element) return (llint) LLONG_MAX - 1e9;
    llint mid = (first_element + last_element) >> 1;
    return min(rmq(first_element, mid, (treetop << 1) + 1, arr_first, arr_second), rmq(mid + 1, last_element, (treetop << 1) + 2, arr_first, arr_second));
}

// =================

int main()
{
    llint length;
    std::cout << "Enter number of elements : "; cin >> length;
    for (llint i = 0 ; i <= length - 1 ; i++) 
    {
        std::cout << "Enter element " << i + 1 << " : "; std::cin >> arr[i];
    };
    buildtree(0, length - 1, 0);
    // for (llint i = 0 ; i <=  pow(2, ceil(log(length)/log(2))) ; i++) cout << segtree[i] << " ";
    std::cout << "Enter range query : ";
    llint m, n; cin >> m >> n;
    std::cout << "Minimum in range : " << rmq(0, length - 1, 0, --m, --n);
}