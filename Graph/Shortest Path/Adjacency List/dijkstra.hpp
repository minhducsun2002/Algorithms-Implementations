#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <utility>

typedef int32_t llint;
typedef size_t ullint;

// Dijkstra's algorithm to find shortest path between two vertices in a graph,
// using adjacency list representation

const llint MAX = INT32_MAX;

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

    std::multiset<std::pair<llint, llint>> vertices;
    // keeping a set of unprocessed edges
    vertices.insert({0, source});
    // the distance between a vertex and itself == 0, as stated above
    while (!vertices.empty())
    {
        llint currentVertex = vertices.begin()->second;
        if (currentVertex == target)
            // if the target vertex has been found, stop
            break;
        vertices.erase(vertices.begin());
        // remove already-processed edge
        for (const auto &child : adjacencyList[currentVertex])
            // for each child vertex of current vertex
            if (distance[child.targetVertex] > distance[currentVertex] + child.weight)
            {
                // if distance from source to this {child vertex} is greater than
                // the distance from source to current vertex plus from the current vertex to this {child vertex}
                // ==
                // also known as
                // ==
                // if there exists a shorter path to this {child vertex}
                vertices.erase({distance[child.targetVertex], child.targetVertex});
                // then remove that edge from the edge process queue
                distance[child.targetVertex] = distance[currentVertex] + child.weight;
                // and recalculate distance
                vertices.insert({distance[child.targetVertex], child.targetVertex});
                // afterward re-add the edge with shortened distance
                backtrace[child.targetVertex] = currentVertex;
                // and also don't forget updating path!
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
