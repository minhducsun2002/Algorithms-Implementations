#include <bits/stdc++.h>
using namespace std;

typedef int32_t llint;
typedef pair <llint, llint> __;

vector <llint> parent;

void initialize()
{
    for (llint i = 0 ; i <= parent.size() - 1 ; i++) parent[i] = i;
}

llint find (llint x)
{
    return (parent[x] == x) ? x : parent[x] = find (x);
}

void union (llint x, llint y)
{
    parent[find(y)] = find(x);
}

bool check (llint x, llint y)
{
    return find(x) == find(y);
}
