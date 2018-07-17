#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;
typedef size_t ullint;

// Prim's algorithm to find the minimum spanning tree in a connected graph
// using adjacency list representation

const long long int MAX = 1e9 + 7;

// Note that the index of each vertex counts from 0.

typedef pair <llint, llint> edge;
// edge.first == weight, edge.second == target_vertex

typedef pair <llint, edge> extended_edge;
// extended.first == weight
// 			second.first == source
// 			second.destination == destination

vector <vector <edge > > adjacencyList;

edge make_edge_from_to(llint source, llint destination)
{
	return make_pair(source, destination)
	;
}

auto prim(llint source, vector <vector <edge> > adjacencyList)
{
	vector <bool> included (adjacencyList.size(), false);
	// tracking whether vertex included

	multiset <extended_edge> remaining_edges;
	// track unprocessed edges

	remaining_edges.insert(make_pair(0, make_edge_from_to(source, source)));
	// the distance from source -> source == 0

	vector <llint> parent (adjacencyList.size());

	// llint MST_size = 0;	// *

	while (!remaining_edges.empty())
	{
		auto	// i.e. the shortest unprocessed extended_edge
		nearest = *remaining_edges.begin();

		// and then erase it since processed
		remaining_edges.erase(remaining_edges.begin());

		if (included[nearest.second.second])
			// if already considered
			// i.e. if nearest.destination is included in the MST
		{
			continue;
			// then skip that vertex!
		};

		// MST_size += nearest.first;	// *


		parent[nearest.second.second]
		= nearest.second.first;

		included[nearest.second.second] = true;
		// include this vertex (i.e. use the current edge in the MST)

		for (pair <llint, llint> a: adjacencyList[nearest.second.second])
			// for each edge from this vertex
			// i.e. the "just included" vertex
		{
			if (!included[a.second])
				// if vertex (in adjacencyList) isn't included
				remaining_edges.insert(make_pair(a.first, make_edge_from_to(nearest.second.second, a.second)));
		}
	}

	// return MST_size;	// *

	// lines marked with a star are used to compute the size of the MST.
	// Uncomment to calculate. Alter the return object correspondingly.


	return parent;
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
	

	vector <llint> out = prim (0, adjacencyList);
	llint out_count = 0;
	for (auto &I : out) cout << "Parent of " << out_count++ << " is " << I << endl;
}

/*
Input specification:
number_of_vertex
number_of_edges edge1_other_vertex edge1_weight edge2_other_vertex edge2_weight ...
...

Output specification:
Parents of each vertex in the MST.
The MST's root has itself as its parent.

Test:
{input}
5
4 1 4 3 6 4 6 2 4
1 2 2 
3 1 2 0 4 3 8
3 0 6 2 8 4 9
2 0 6 3 9

{output}
Parent of 0 is 0
Parent of 1 is 0
Parent of 2 is 1
Parent of 3 is 0
Parent of 4 is 0
*/