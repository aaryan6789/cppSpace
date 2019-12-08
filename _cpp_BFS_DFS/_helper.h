#pragma once
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

int numIslandsDFS(vector<vector<char>>& grid);
int numIslandsBFS(vector<vector<char>>& grid);

int maxAreaOfIsland(vector<vector<int>>& grid);

int treasure_island(vector<vector<char>>& grid);
int treasure_island_BFS(vector<vector<char>>& grid);