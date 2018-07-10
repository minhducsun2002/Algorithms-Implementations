#include <iostream>
#include <string>
#include "dijkstra.hpp"

std::vector<std::vector<edge>> adjacencyList;

int main()
{
	llint verticesCount;
	std::cin >> verticesCount;
	// prepare traversal logging and adjacency list
	traversed.resize(verticesCount);
	adjacencyList.resize(verticesCount);

	for (llint i = 0; i < verticesCount; i++)
	{
		llint neighbour_count;
		std::cin >> neighbour_count;
		while (neighbour_count-- > 0)
		{
			// edge between vertex[i] and vertex[push.targetVertex] with weight = push.weight
			edge push;
			std::cin >> push.targetVertex >> push.weight;
			adjacencyList[i].push_back(push);
		}
	}
	std::vector<llint> out = dijkstra(0, 4, adjacencyList);
	for (const llint &i : out)
		std::cout << (i != MAX ? std::to_string(i) : std::string("MAX")) << " ";
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
4 3 1
*/
