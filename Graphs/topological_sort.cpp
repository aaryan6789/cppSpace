#include <stack>
#include "_graph.h"

// Topological Sort is like Modified DFS + Stack
// We modify DFS to find Topological Sorting of a graph. 
// In DFS, we start from a vertex, we first print it and then recursively call
// DFS for its adjacent vertices. 

// In topological sorting, we use a temporary stack. 
// We don’t print the vertex immediately, we first recursively call 
// topological sorting for all its adjacent vertices, 
// then push it to a stack. 
// Finally, print contents of stack. 

// Note that a vertex is pushed to stack only when all of its adjacent vertices 
// (and their adjacent vertices and so on) are already in stack.


void Graph::topoSortUtil(int v, vector<bool>& visited, stack<int>& st){
    visited[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i){
        if(!visited[*i]){
            topoSortUtil(*i, visited, st);
        }
    }

    st.push(v);
}

void Graph::topologicalSort(){
    stack<int> st;
    int v = getNumVertices();

    vector<bool> visited(v, false);

    for(int i = 0; i< v; i++){
        if(visited[i] == false){
            topoSortUtil(i, visited, st);
        }
    }
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

}