#include <iostream>
#include <vector>
#include <climits>

typedef ssize_t llint;
typedef size_t ullint;

// Dijkstra's algorithm to find shortest path between two vertices in a graph,
// using adjacency list representation

const long long int MAX = INT64_MAX;

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

    for (llint currentVertex = 0; currentVertex < verticesCount; currentVertex++)
    {
        // for each vertex
        for (const edge &i : adjacencyList[currentVertex])
        {
            const int &vertex = i.targetVertex;
            const int &weight = i.weight;
            // if current neighbour is unvisited
            if (!traversed[vertex])
            {
                // then visit it!
                traversed[vertex] = true;
                // and also calculate the distance from current node
                distance[vertex] = distance[currentVertex] + weight;
                // overwriting traces
                backtrace[vertex] = currentVertex;
            }
            // and if visited
            else
            {
                // if path isn't optimal
                if (distance[vertex] > distance[currentVertex] + weight)
                {
                    // then make it optimal!
                    distance[vertex] = distance[currentVertex] + weight;
                    // and don't forget overwriting old traces
                    backtrace[vertex] = currentVertex;
                }
            }
        }
    }

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