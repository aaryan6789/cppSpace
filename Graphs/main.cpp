#include "_graph.h"
#include "_graph2.h"
#include "_graph3.h"

int main() {
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);
    
    g1.BFS(2);

    cout << endl;
    g1.DFS(2);
    
    cout << endl;
    g1.topologicalSort();
    
    cout << endl;
    MakingGraph2();
    
    makingGraph3();
    
    
    
    return 0;
}