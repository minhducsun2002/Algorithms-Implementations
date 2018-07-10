#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <utility>

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

std::vector<llint> dijkstra(llint source, llint target, std::vector<std::vector<edge>> adjacencyList)
{
    llint verticesCount = adjacencyList.size();

    std::vector<llint> distance(adjacencyList.size(), MAX);
    // the distance between a vertex and itself == 0;
    traversed[source] = true;
    distance[source] = 0;

    std::vector<llint> backtrace(adjacencyList.size(), MAX);
    // keep the shortest path

    std::set<std::pair<llint, llint>> vertices;
    vertices.insert({0, source});
    while (!vertices.empty())
    {
        llint currentVertex = vertices.begin()->second;
        if (currentVertex == target)
            break;
        vertices.erase(vertices.begin());
        for (const auto &child : adjacencyList[currentVertex])
            if (distance[child.targetVertex] > distance[currentVertex] + child.weight)
            {
                vertices.erase({distance[child.targetVertex], child.targetVertex});
                distance[child.targetVertex] = distance[currentVertex] + child.weight;
                vertices.insert({distance[child.targetVertex], child.targetVertex});
                backtrace[child.targetVertex] = currentVertex;
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