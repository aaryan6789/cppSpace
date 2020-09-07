#include "_graph.h"

// BFS Traversal
// Source Node = s
void Graph::BFS(int s){
    // Mark all the nodes as Visited
    vector<bool> visited(num_v, false);

    // Create a Queue for BFS
    list<int> queue;

    // Mark the current node as visited
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty()){
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for(i = adj[s].begin(); i!= adj[s].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    } 
}

void Graph::DFSUtil(int v, vector<bool>& visited){
    visited[v] = true;      // Mark Visited
    cout << v << " ";

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i){
        if(!visited[*i]){
            DFSUtil(*i, visited);
        }
    }
}

// Depth First Traversal (or Search) for a graph is similar to DFS of a tree. 
// The only catch here is, unlike trees, graphs may contain cycles, so we may
// come to the same node again. 
// To avoid processing a node more than once, we use a boolean visited array.
// DFS traversal of the vertices reachable from v
void Graph::DFS(int v){
    // Mark all the nodes as Visited
    vector<bool> visited(num_v, false);

    DFSUtil(v, visited);

}

