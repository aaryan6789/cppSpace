#include <queue>
#include <iostream>
#include "_graph3.h"

int makingGraph3(){
    Graph3 g(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);

    g.addEdge(2, 3);

    g.BFS(0);
    return 0;
}

// BFS traversal of the Graph from Source node s
void Graph3::BFS(int s){
    // Mark all the nodes as Visited
    vector<bool> visited(num_v, false);

    // Create a Queue for BFS
    queue<int> q;

    // Mark the current node as visited
    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        s = q.front();
        cout << s << " ";
        q.pop();

        // for(auto i = adjList[s].begin(); i != adjList[s].end(); ++i){
        //     if(!visited[*i]){
        //         visited[*i] = true;
        //         q.push(*i);
        //     }
        // }
        
        for(auto i = 0; i < adjList[s].size(); ++i){
            int node = adjList[s][i];
            if(!visited[node]){
                visited[node] = true;
                q.push(node);
            }
        }
    }
}