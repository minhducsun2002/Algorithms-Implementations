//==============================
// Include Guard
#pragma once

#ifndef __ADJLIST_HPP_INCLUDED__
#define __ADJLIST_HPP_INCLUDED__

//==============================
// forward declare
template <typename __data_t>
class AdjList;

//==============================
// Include
#include <vector>

template <typename __data_t>
class adjList : public std::vector<std::vector<__data_t>>
{
  public:
    adjList(){};
    adjList(size_t nodes) { this->resize(nodes); };
};
#endif // __ADJLIST_HPP_INCLUDED__
