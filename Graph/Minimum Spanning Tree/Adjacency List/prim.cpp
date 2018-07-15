#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;
typedef size_t ullint;

// Prim's algorithm to find the minimum spanning tree in a connected graph
// using adjacency list representation

const long long int MAX = 1e9 + 7;

// Note that the index of each vertex counts from 0.

typedef pair <llint, llint> edge;

vector <vector <edge > > adjacencyList;

// pair.first == weight, pair.second == target_vertex

llint prim(llint source, vector <vector <edge> > adjacencyList)
{
	vector <bool> included (adjacencyList.size(), false);
	// tracking whether vertex included

	multiset <edge> remaining_edges;
	remaining_edges.insert(make_pair(0, source));

	llint MST_size = 0;

	while (!remaining_edges.empty())
	{
		pair <llint, llint> nearest = *remaining_edges.begin();
		remaining_edges.erase(remaining_edges.begin());

		if (included[nearest.second])
			// if already considered
		{
			continue;
			// then skip that vertex
		};

		MST_size += nearest.first;

		included[nearest.second] = true;
		// include this vertex (i.e. use the current edge in the MST)

		for (pair <llint, llint> a: adjacencyList[nearest.second])
			// for each edge from this vertex
		{
			if (!included[a.second])
				remaining_edges.insert(a);
		}
	}
	return MST_size;
}

main()
{
	llint verticesCount; cin >> verticesCount;
	
	// prepare adjacency list
	adjacencyList.resize(verticesCount);

	for (llint i = 0 ; i <= verticesCount - 1 ; i++)
	{
		llint neighbour_count; cin >> neighbour_count;
		while (neighbour_count--)
		{
			// edge between vertex[i] and vertex[push.targetVertex] with weight = push.weight
			pair <llint, llint> a; cin >> a.second >> a.first;
			adjacencyList[i].push_back(a);
		};
	};
	cout << prim(0, adjacencyList);
}