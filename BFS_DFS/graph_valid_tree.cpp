#include "_helper.h"

/** GRAPH VALID TREE | LEETCODE M | 210
 * PreReq : Graph, BFS, DFS, Connectivity, Cycles
 * Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
 */


// A Graph is a Valid Tree iff
// 1. It has no cycles.
// 2. It is Connected.

// just check for cycle and connectedness in the graph. 
// Both of these can be done via DFS.
bool hasCycle(vector<vector<int>>& neighbors, int kid, int parent, vector<bool>& visited);
bool validTree(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> neighbors(n);
    for (auto e : edges) {
        neighbors[e.first].push_back(e.second);
        neighbors[e.second].push_back(e.first);
    }
    vector<bool> visited(n, false);
    if (hasCycle(neighbors, 0, -1, visited))
        return false;
    for (bool v : visited)
        if (!v) return false; 
    return true;
} 

bool hasCycle(vector<vector<int>>& neighbors, int kid, int parent, vector<bool>& visited) {
    if (visited[kid]) return true;
    visited[kid] = true;
    for (auto neigh : neighbors[kid])
        if (neigh != parent && hasCycle(neighbors, neigh, kid, visited))
            return true;
    return false;
}
