#include "_graph.h"
/**
 * Given an undirected graph with n nodes labeled 1..n. 
 * 
 * Some of the nodes are already connected. 
 * The i-th edge connects nodes edges[i][0] and edges[i][1] together. 
 * Your task is to augment this set of edges with additional edges to connect 
 * all the nodes. 
 * Find the minimum cost to add new edges between the nodes such that all the
 * nodes are accessible from each other.

Input:
n, an int representing the total number of nodes.
edges, a list of integer pair representing the nodes already connected by an edge.
newEdges, a list where each element is a triplet representing the pair of nodes between which an edge can be added and the cost of addition, respectively (e.g. [1, 2, 5] means to add an edge between node 1 and 2, the cost would be 5).

Example 1:
Input: n = 6, edges = [[1, 4], [4, 5], [2, 3]], 
newEdges = [[1, 2, 5], [1, 3, 10], [1, 6, 2], [5, 6, 5]]
Output: 7
Explanation:
There are 3 connected components [1, 4, 5], [2, 3] and [6].
We can connect these components into a single component by connecting node 1 to node 2 and node 1 to node 6 at a minimum cost of 5 + 2 = 7.

Related problems:
Min Cost to Repair Edges
https://leetcode.com/problems/connecting-cities-with-minimum-cost (premium)
 */
#include <vector>
#include <algorithm>
using namespace std;


int _find(int x, vector<int>& parent) {
    if(x==parent[x]) {
        return parent[x];
    }
    parent[x] = _find(parent[x], parent);
    return parent[x];
}


void _union(int x,int y, vector<int>& parent, int& n) {
    int a = _find(x, parent);
    int b = _find(y, parent);
    
    if(a!=b){
        parent[b] = a;
        n--;
    }
}

int mincostToConnectAllNodes(int n, vector<vector<int>>& edges, 
                                    vector<vector<int>>& newedges){
    vector<int> parent(n+1, 0);

    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    //connect all the nodes
    for(auto &p : edges){
        if(_find(p[0], parent) != _find(p[1], parent))
        {
            _union(p[0],p[1], parent, n);
        }
    }
    
    sort(newedges.begin(),newedges.end(), [](vector<int>& p2,vector<int>& p1)
                                            {
                                                return p2[2]<p1[2];
                                            });
    int sum(0);
    
    //connect all the newedges
    for(auto &p : newedges){
        if(_find(p[0], parent) != _find(p[1], parent)){
            _union(p[0],p[1], parent, n);
            sum+=p[2];
        }
    }
    
    return n==1 ? sum: -1;
}

