#include "_helper.h"
// Calculate the ARTICULATE POINTS IN A GRAPH


// A recursive function that find articulation points using DFS traversal 
// node         --> The vertex to be visited next 
// visited[]    --> keeps tract of visited vertices 
// disc[]       --> Stores discovery times of visited vertices 
// parent[]     --> Stores parent vertices in DFS tree 
// ap[]         --> Store articulation points
void DFS(int node, vector<bool>& visited, vector<int>& disc, vector<int>& low, int time,
                vector<int>& parent, vector<vector<int>>& graph, vector<bool>& ap){

    visited[node] = true;   // Mark the current node as visited
    
    // Count of children in DFS Tree
    int children = 0;

    disc[node] = low[node] = time;
    time++;

    // Go through all nodes adjacent to this node 
    for(auto neigh : graph[node]){
        if(!visited[neigh]){
            children++;
            parent[neigh] = node;
            DFS(neigh, visited, disc, low, time, parent, graph, ap);

            // Check if the subtree rooted with node has a connection to one of the ancestors of neigh
            low[neigh]  = min(low[neigh], low[node]); 

            // neigh is an AP in following cases
            // 1. neigh is root of DFS tree with 2 or more children
            if(parent[neigh] != -1 && low[node] >= disc[neigh])
                ap[neigh] = true;

            // 2. If neigh is not root and low value of one of its child is more 
            // than discovery value of neigh. 
            if (parent[neigh] != -1 && low[node] >= disc[neigh]) 
               ap[neigh] = true; 
        }
        // Update low value of neigh for parent function calls. 
        else if (node != parent[neigh]) 
            low[neigh]  = min(low[neigh], disc[node]);
    }
}

void critical_connections(int N, vector<vector<int>>& edges){
    cout << "critical_connections " << endl;
    // 5 arrays 
    vector<bool> visited(N+1, false);   // Mark all the vertices as not visited 
    vector<int> disc(N+1, -1);          // to store discovery time of vertices
    vector<int> low(N+1, -1);           // 
    vector<int> parent(N+1, 0);         // To keep the record of parent of each vertex
    vector<bool> ap(N+1, false);        // To Store Articulate Points

    int time = 0;

    // For this algorithm we need the graph to be represented as an adjacency list
    vector<vector<int>> graph;
    vector<vector<int>> result;

    for(auto e : edges){
        graph[e[0]].push_back(e[1]);        // 1-->2
        graph[e[1]].push_back(e[0]);        // 2-->1 same edge 
    }

    // Call the recursive DFS function to find articulation points 
    // in DFS tree rooted with vertex 'i'
    for(int i = 0; i< N; i++){
        if(!visited[i]){
            DFS(i, visited, disc, low, 1, parent, graph, ap);
        }
    }

    cout << "Articulation Points are " << endl;
    for(auto i : ap){
        if( i == true)
            cout << i << " ";
    }

}