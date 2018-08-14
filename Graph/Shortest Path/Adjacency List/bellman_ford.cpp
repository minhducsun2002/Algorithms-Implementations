#include <vector>
#include <pair>

#include <iostream>
// not required

typedef long long int llint;

// Richard Bellman & Lester Ford, Jr.'s algorithm to find shortest path between two vertices in a graph,
// using adjacency list representation

const llint MAX = 1e9 + 7;

// Note that the index of each vertex counts from 0.

struct edge
{
	llint weight, targetVertex;
	// for each vertex
	// its adjacency list entry will contain informations about its neighbour(s)
	// including the weight of the edge connecting them
};

std::vector <std::vector <edge> > adjacencyList;

std::pair <vector <llint>, bool> bellman_ford(llint source)
{
    std::vector <llint> distance (adjacencyList.size(), MAX);
    // the distance from a vertex to itself always = 0
    distance[source] = 0;

    std::vector <llint> path (adjacencyList.size());


    // repeatedly shorten edges
    for (llint i = 0 ; i <= adjacencyList.size() - 2 ; i++)
    {
        for (llint start = 0 ; start <= adjacencyList.size() - 1 ; start++)
        // for each source vertex 
        {
            for (edge connection : adjacencyList[start])
            // for each edge i.e for each destination vertex
            {
                llint end = connection.targetVertex;
                llint weight = connection.weight;

                // if optimization is possible i.e. there exists a shorter path
                if (distance[start] + weight < distance[end])
                {
                    // then optimize it!
                    distance[end] = distance[start] + weight;
                    // and don't forget updating path
                    path[end] = start;
                }
            }
        }
    }

    // negative-weight cycle detection

    // for each source vertex 
    for (llint start = 0 ; start <= adjacencyList.size() - 1 ; start++)
    {
        for (edge connection : adjacencyList[start])
        // for each edge i.e for each destination vertex
        {
            llint end = connection.targetVertex;
            // if "optimization" is further possible
            if (distance[start] + connection.weight < distance[end])
            {
                // then it is surely a negative-weight cycle
                return {distance, true};
                // 'true' implies there exists a negative cycle
            }
        }
    };
    // 'false' implies there doesn't exist a negative cycle
    return {distance, false};
}

main()
{
	llint verticesCount; std::cin >> verticesCount;
	// prepare traversal logging and adjacency list
	adjacencyList.resize(verticesCount);

	for (llint i = 0 ; i <= verticesCount - 1 ; i++)
	{
		llint neighbour_count; std::cin >> neighbour_count;
		while (neighbour_count--)
		{
			// edge between vertex[i] and vertex[push.targetVertex] with weight = push.weight
			edge push; std::cin >> push.targetVertex >> push.weight;
			adjacencyList[i].push_back(push);
		};
	};
	std::vector <llint> out = bellman_ford(0).first;
	for (llint i : out) std::cout << (i != MAX ? to_string(i) : string ("MAX")) << " ";
    if (bellman_ford(0).second) std::cout << "Error :: Negative cycle found.";
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
11
2 1 16 2 0
1 2 -32
2 3 8 4 0
1 4 -16
2 5 4 6 0
1 6 -8
2 7 2 8 0
1 8 -4
2 9 1 10 0
1 10 -2
0
{output}
0 16 -16 -8 -24 -20 -28 -26 -30 -29 -31 
*/
