#include "_graph2.h"

// print adjacency list representation of graph
void printGraph2(const Graph2& graph, int N){
	for (int i = 0; i < N; i++){
		// print current vertex number
		cout << i << " --> ";

		// print all neighboring vertices of vertex i
		for (int v : graph.adjList[i])
			cout << v << " ";
		cout << endl;
	}
}

// Graph2 Implementation using STL
int MakingGraph2(){
	// vector of graph edges as per above diagram.
	// Please note that initialization vector in below format will
	// work fine in C++11, C++14, C++17 but will fail in C++98.
	vector<Edge> edges =
	{
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	// Number of nodes in the graph
	int N = 6;

	// construct graph2
	Graph2 g2(edges, N);

	// print adjacency list representation of graph
	printGraph2(g2, N);

	return 0;
}