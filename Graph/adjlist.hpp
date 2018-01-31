//==============================
// Include Guard
#ifndef _AdjList_HPP_INCLUDED__
#define _AdjList_HPP_INCLUDED__
// Check if ADJLIST.hpp has been defined

//==============================
// forward declare
class AdjList;

//==============================
// Include
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// typedef
typedef int __prop;
// property of data
typedef pair<int, __prop> __data;
// Data: include id and prop
typedef vector<__data> __vii;
// Vector of data
typedef vector<__vii> __vList;
// List of data

class AdjList
{
    int _Edge = 0;
    // Number of edge(s)
    int _Node = 0;
    // Number of Node(s)
    __vList _AdjList;
    // Adjacent List

  private:
    bool isNode(int);

  public:
    AdjList(int);
    int findEdge(int, int);
    bool isEdge(int, int);
    void pushEdge(int, int, __prop);
    void Print();
    int atEdge(int, int);
    __prop weightEdge(int, int);
};

AdjList::AdjList(int nodes)
{
    if (nodes < 1)
        return;
    _Node = nodes;
    _AdjList.assign(nodes, __vii());
}

bool AdjList::isNode(int node)
{
    return (node >= 0 && node < _Node);
}

bool AdjList::isEdge(int node, int id)
{
    return (findEdge(node, id) != 0);
}

void AdjList::pushEdge(int node, int id, __prop prop)
{
    if (!isEdge(node, id) && isNode(node))
    {
        _AdjList[node].push_back(__data(id, prop));
        _Edge++;
    }
}

void AdjList::Print()
{
    for (int i = 0; i < _Node; i++)
    {
        cout << "[" << i << "]->";
        for (int j = 0; j < (int)_AdjList[i].size(); j++)
        {
            cout << "\t" << _AdjList[i][j].first;
        }
        cout << endl;
    }
}

int AdjList::atEdge(int node, int place)
{
    return _AdjList[node][place].first;
}

__prop AdjList::weightEdge(int node, int place)
{
    return _AdjList[node][place].second;
}

#endif // _AdjList_HPP_INCLUDED__