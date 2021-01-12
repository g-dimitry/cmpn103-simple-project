#pragma once
#include <utility>
#include <vector>
#include <set>
#include <stack>
#include <iostream>
using namespace std;

#define ROW 47
#define COL 82

namespace AStar
{
  // Creating a shortcut for int, int pair type
  typedef pair<int, int> Pair;

  // Creating a shortcut for pair<int, pair<int, int>> type
  typedef pair<double, pair<int, int>> pPair;

  // A structure to hold the neccesary parameters
  struct cell
  {
    // Row and Column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
  };
  vector<Pair> getShortestPath(int grid[][82], Pair src, Pair dest);
} // namespace AStar