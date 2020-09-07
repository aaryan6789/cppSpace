#include <vector>
using namespace std;

class Graph3 {
public:
    int num_v;  // Number of Vertices
    vector<vector<int>> adjList;     // Pointer to an array containing adjacency

public:
    // Constructor
    Graph3(int V){
        this->num_v = V;
        adjList.resize(V);
    }

    // Function to add an edge to a graph
    // An edge is directed from v-->w
    // So add w to v's list
    void addEdge(int v, int w){
        adjList[v].push_back(w);
    }

    // BFS traversal of the Graph from Source node s
    void BFS(int s);
};

int makingGraph3();