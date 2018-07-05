#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;
typedef size_t ullint;

// Dijkstra's algorithm to find shortest path between two vertices in a graph,
// using adjacency list representation

const long long int MAX = 1e9 + 7;

// Note that the index of each vertex counts from 0.

vector <bool> traversed;
// log if a specific vertex has been checked
// preventing infinite loop

struct edge
{
	llint weight, targetVertex;
	// for each vertex
	// its adjacency list entry will contain informations about its neighbour(s)
	// including the weight of the edge connecting them
};

vector <vector <edge> > adjacencyList;

vector <llint> dijkstra (llint source)
{
	llint verticesCount = adjacencyList.size();

	vector <llint> distance (adjacencyList.size(), MAX);
	// the distance between a vertex and itself == 0;
	traversed[source] = true;
	distance[source] = 0;

	for (llint currentVertex = 0; currentVertex <= verticesCount - 1 ; currentVertex++)
	{
		// for each vertex
		for (edge i : adjacencyList[currentVertex])
		{
			// if current neighbour is unvisited
			if (!traversed[i.targetVertex])
			{
				// then visit it!
				traversed[i.targetVertex] = true;
				// and also calculate the distance from current node
				distance[i.targetVertex] = distance[currentVertex] + i.weight;
			}
			// and if visited
			else
			{
				// if path isn't optimal
				if (distance[i.targetVertex] > distance[currentVertex] + i.weight) 
					// then make it optimal!
					distance[i.targetVertex] = distance[currentVertex] + i.weight;
			};
		};
	};
	return distance;
}

main()
{
	llint verticesCount; cin >> verticesCount;
	// prepare traversal logging and adjacency list
	traversed.resize(verticesCount);
	adjacencyList.resize(verticesCount);

	for (llint i = 0 ; i <= verticesCount - 1 ; i++)
	{
		llint neighbour_count; cin >> neighbour_count;
		while (neighbour_count--)
		{
			// edge between vertex[i] and vertex[push.targetVertex] with weight = push.weight
			edge push; cin >> push.targetVertex >> push.weight;
			adjacencyList[i].push_back(push);
		};
	};
	vector <llint> out = dijkstra(0);
	for (llint i : out) cout << (i != MAX ? to_string(i) : string ("MAX")) << " ";
}

/*
Input specification:
number_of_vertex
number_of_edges edge1_other_vertex edge1_weight edge2_other_vertex edge2_weight ...
...

Output specification:
distance from source (here I use 0) to each other vertex starting from vertex 0.
an output of MAX indicates that it is impossible to reach the corresponding vertex.

Test:
{input}
6
2 1 1 2 1
2 3 1 2 1
2 3 1 5 1
1 4 1
0
0
{output}
0 1 1 2 3 2 
*/