#pragma once

#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
using namespace std;

void printMatrix(vector<vector<int>>& mat);

int numIslandsDFS(vector<vector<char>>& grid);
int numIslandsBFS(vector<vector<char>>& grid);

int maxAreaOfIsland(vector<vector<int>>& grid);
int treasure_island(vector<vector<char>>& grid);
int treasure_island_BFS(vector<vector<char>>& grid);
int treasure_island_II(vector<vector<char>>& grid);

int zombieMatrix(vector<vector<int>> grid);

void critical_connections(int N, vector<vector<int>>& edges);
int countDistinctIslands(vector<vector<int> >& grid);
vector<vector<int>> critConnections(int Nodes, vector<vector<int>>& edges);