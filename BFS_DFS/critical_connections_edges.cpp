#include "_helper.h"
/**
 * https://leetcode.com/problems/critical-connections-in-a-network/

Given an undirected connected graph with n nodes labeled 1..n. 
A bridge (cut edge) is defined as an edge which, when removed, makes the graph 
disconnected (or more precisely, increases the number of connected components 
in the graph). 

Equivalently, an edge is a bridge if and only if it is not contained in any 
cycle. 

The task is to find all bridges in the given graph. 
Output an empty list if there are no bridges.

Input:
- n, an int representing the total number of nodes.
- edges, a list of pairs of integers representing the nodes connected by an edge.

Example 1:
Input: n = 5, edges = [[1, 2], [1, 3], [3, 4], [1, 4], [4, 5]]

3 ------ 4 ------ 5
 \      /
  \    /
   \  /
     1 ------ 2

Output: [[1, 2], [4, 5]]
Explanation:
There are 2 bridges:
1. Between node 1 and 2
2. Between node 4 and 5
If we remove these edges, then the graph will be disconnected.
If we remove any of the remaining edges, the graph will remain connected.

Example 2:
Input: n = 6, edges = [[1, 2], [1, 3], [2, 3], [2, 4], [2, 5], [4, 6], [5, 6]]

 1          4 
|  \      /   \
|   \    /     \
|    \  /       \
|     2          6
|    /  \       /
|   /    \     /
|  /      \   /
 3          5

Output: []
Explanation:
We can remove any edge, the graph will remain connected.

Example 3:
Input: n = 9, edges = [[1, 2], [1, 3], [2, 3], [3, 4], [3, 6], [4, 5], [6, 7], [6, 9], [7, 8], [8, 9]]


Output: [[3, 4], [3, 6], [4, 5]]
**/

void dfs(int node, vector<bool>& visited, vector<int>& disc,vector<int>& low, int parent,int& time,vector<vector<int>>& adj, vector<vector<int>>& result) 
{ 
    // Mark the current node as visited 
    visited[node] = true; 
  
    // Initialize discovery time and low value 
    disc[node] = low[node] = ++time; 
  
    // Go through all vertices aadjacent to this 
    for (auto curNode : adj[node]) 
    { 
        // If v is not visited yet, then recur for it 
        if (!visited[curNode]) 
        { 
            dfs(curNode,visited,disc,low,node,time,adj,result); 
            
            // Check if the subtree rooted with v has a  
            // connection to one of the ancestors of u 
            low[node]  = min(low[node], low[curNode]); 
  
            // If the lowest vertex reachable from subtree  
            // under v is  below u in DFS tree, then u-v  
            // is a bridge 
            if (low[curNode] > disc[node]) 
            {
                result.push_back({node,curNode});
            }
        } 
  
        // Update low value of u for parent function calls. 
        else if (curNode != parent) 
            low[node]  = min(low[node], disc[curNode]); 
    } 
} 

vector<vector<int>> critConnections(int Nodes, vector<vector<int>>& edges)
{
    vector<vector<int>> adj(Nodes+1,vector<int>());
    vector<int> low(Nodes+1,-1);
    vector<int> disc(Nodes+1,-1);
    vector<bool> visited(Nodes+1,false);
    vector<vector<int>> result;
    int time = 0;
    //build the adj list
    for(auto x:edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    
    for(int x=1;x<=Nodes;x++)
    {
        if(!visited[x])
        {
            dfs(x,visited,disc,low,0,time,adj,result);
        }
    }
    return result;
    
}