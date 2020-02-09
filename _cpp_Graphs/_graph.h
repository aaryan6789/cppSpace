#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Graph {
public:
    int num_v;  // Number of Vertices
    list<int> *adj;     // Pointer to an array containing adjacency

public:
    // Constructor
    Graph(int V){
        this->num_v = V;
        adj = new list<int>[V];
    }

    const int getNumVertices(){
        return num_v;
    }

    // Function to add an edge to a graph
    // An edge is directed from v-->w
    // So add w to v's list
    void addEdge(int v, int w){
        adj[v].push_back(w);
    }

    // BFS traversal of the Graph from Source node s
    void BFS(int s);

    void DFSUtil(int v, vector<bool>& visited);
    // DFS traversal of the Graph from Source node s
    void DFS(int s);

    // TOPOLOGICAL SORT OF A GRAPH
    void topoSortUtil(int v, vector<bool>& visited, stack<int>& st);
    void topologicalSort();

};






