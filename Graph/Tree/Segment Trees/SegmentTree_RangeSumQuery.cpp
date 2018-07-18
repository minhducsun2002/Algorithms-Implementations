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
        // if this is a leaf node
        segtree[treenode] = arr[first_element];
        // just perform assignment and then stop there
        return;
    }
    // else
    llint mid = (last_element + first_element) >> 1;
    // build the corresponding subtrees
    buildtree(first_element, mid, (treenode << 1) + 1);
    buildtree(mid + 1, last_element, (treenode << 1) + 2);
    // and then update the minimum value at current node
    segtree[treenode] = (segtree[(treenode << 1) + 1] + segtree[(treenode << 1) + 2]);
}

llint rsq(llint first_element, llint last_element, llint treetop, llint arr_first, llint arr_second)
{
    if (arr_first <= first_element && last_element <= arr_second) return segtree[treetop];
    // if the query range is within the current range then reply with precalculated value
    if (arr_first > last_element || arr_second < first_element) return 0;
    // if out of range
    // return 0
    // to not altering the right result
    llint mid = (first_element + last_element) >> 1;
    return rsq(first_element, mid, (treetop << 1) + 1, arr_first, arr_second) + rsq(mid + 1, last_element, (treetop << 1) + 2, arr_first, arr_second);
    // calculate from corresponding subtrees
}
// =================

int main()
{
    llint length;
    //std::cout << "Enter number of elements : ";
    cin >> length;
    for (llint i = 0 ; i <= length - 1 ; i++) 
    {
        //std::cout << "Enter element " << i + 1 << " : ";
        std::cin >> arr[i];
    };
    buildtree(0, length - 1, 0);
    // for (llint i = 0 ; i <=  pow(2, ceil(log(length)/log(2))) ; i++) cerr << segtree[i] << " ";
    //std::cout << "Enter range query : ";
    llint m, n; cin >> m >> n;
    //std::cout << "Sum of range : ";
    cout << rsq(0, length - 1, 0, --m, --n);
}