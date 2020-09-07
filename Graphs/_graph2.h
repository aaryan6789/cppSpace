#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

// Another Way of Representing a Directed Graph
struct Edge{
    int src;
    int dest;

    // int weight;     // Add this if we want to add weight to this edge
};

class Graph2{
public:
    vector<vector<int>> adjList;

public:
    Graph2(const vector<Edge>& edges, int N){
        adjList.resize(N);

        for(auto& edge : edges){
            adjList[edge.src].push_back(edge.dest);

            // Uncomment below line for undirected graph
			// adjList[edge.dest].push_back(edge.src);
        }
    }
};

int MakingGraph2();