#include <iostream>
#include <vector>

typedef ssize_t llint;
typedef size_t ullint;

// Dijkstra's algorithm to find shortest path between two vertices in a graph,
// using adjacency list representation

const long long int MAX = 1e9 + 7;

// Note that the index of each vertex counts from 0.

std::vector<bool> traversed;
// log if a specific vertex has been checked
// preventing infinite loop

struct edge
{
	llint weight, targetVertex;
	// for each vertex
	// its adjacency list entry will contain informations about its neighbour(s)
	// including the weight of the edge connecting them
};

std::vector<std::vector<edge>> adjacencyList;

std::vector<llint> dijkstra(llint source, llint target)
{
	llint verticesCount = adjacencyList.size();

	std::vector<llint> distance(adjacencyList.size(), MAX);
	// the distance between a vertex and itself == 0;
	traversed[source] = true;
	distance[source] = 0;

	std::vector<llint> backtrace(adjacencyList.size(), MAX);
	// keep the shortest path

	for (llint currentVertex = 0; currentVertex <= verticesCount - 1; currentVertex++)
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
				// overwriting traces
				backtrace[i.targetVertex] = currentVertex;
			}
			// and if visited
			else
			{
				// if path isn't optimal
				if (distance[i.targetVertex] > distance[currentVertex] + i.weight)
				{
					// then make it optimal!
					distance[i.targetVertex] = distance[currentVertex] + i.weight;
					// and don't forget overwriting old traces
					backtrace[i.targetVertex] = currentVertex;
				}
			};
		};
	};

	std::vector<llint> path;
	// trace back to source
	llint current_head = target;
	while (current_head != source)
	{
		path.push_back(current_head);
		current_head = backtrace[current_head];
	}
	// in case
	// the path is wanted in order source -> destination then uncomment the line below
	// reverse (path.begin(), path.end());
	return path;
	// in case the shortest distance to each node is wanted (instead of shortest path),
	// then
	// ```
	// return distance;
	// ```
	// instead.
}