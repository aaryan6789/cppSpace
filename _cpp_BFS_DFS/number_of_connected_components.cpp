#include "_helper.h"
/**
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/
// Time complexity of above solution is O(V + E)
// Method 1 : DFS + RECURSION
void DFS(vector<vector<int>>& graph, int root, vector<int>& visited);
int countComponentsDFS(int n, vector<vector<int>>& edges) {
     vector<vector<int>>graph(n);
     vector<int>visited(n);
     for(auto edge: edges){
          int from = edge[0]; 
          int to   = edge[1];

          graph[from].push_back(to);
          graph[to].push_back(from);
     }

     int count = 0;
     for(int i = 0; i < n; i++){
          if(!visited[i]){
               count++;
               DFS(graph, i, visited);
          }
     }
     return count;
}

void DFS(vector<vector<int>>& graph, int root, vector<int>& visited){
     if(visited[root]) 
          return;
     
     // Mark Visited
     visited[root] = 1;
     
     // Check the Neighbours and trigger DFS on them too
     for(auto neigh: graph[root])
          if(!visited[neigh]) 
               DFS(graph, neigh, visited);
}

// Method 2 : Using DFS and Stack

int countComponents(int n, vector<vector<int>>& edges) {
     vector<bool> visited(n, false);
     vector<vector<int>> adjList(n, vector<int>(0));
     stack<int> dfs;
     
     int count = 0;
     int ans = 0;
     
     // building the graph's adjacency list
     for(auto edge : edges){
          int from = edge[0]; 
          int to   = edge[1];
          
          adjList[from].push_back(to);
          adjList[to].push_back(from);
     }
     
     // Print the Adjacency List
     for(int i = 0; i< adjList.size(); i++){
          cout << i << " " ;
          for( int j = 0; j< adjList[i].size(); j++){
               cout << adjList[i][j] << " " ;
          }
          cout << endl;
     }
     
     
     // dfs on nodes to find connected components
     for(int i = 0; i < n; i++){
          // for( int i = 0; i<n; i++){
          //     cout << visited[i] << " ";
          // }
          // cout << endl;
          
          if(!visited[i]){
               ans++;
               dfs.push(i);        // 1 . Push on Stack
               
               while(!dfs.empty()){
               int current = dfs.top();    // Pop Top
               dfs.pop();
               visited[current] = true;    // Mark Visited
               
               // Push unvisited neighbors on the stack
               for(int neighbour  : adjList[current]){
                    cout << "nei h " << neighbour << endl;
                    if(!visited[neighbour]) 
                         dfs.push(neighbour);
               }
               }
          }             
     }
     
     return ans;
}

// Method 3 : Using BFS and Queue

int countComponentsBFS(int n, vector<vector<int>>& edges) {
     vector<bool> visited(n, false);
     vector<vector<int>> adjList(n, vector<int>(0));
     queue<int> q;

     int count = 0;
     int ans = 0;

     // building the graph's adjacency list
     for(auto edge : edges){
          int from = edge[0]; 
          int to   = edge[1];

          adjList[from].push_back(to);
          adjList[to].push_back(from);
     }

     // Print the Adjacency List
     // for(int i = 0; i< adjList.size(); i++){
     //      cout << i << " " ;
     //      for( int j = 0; j< adjList[i].size(); j++){
     //           cout << adjList[i][j] << " " ;
     //      }
     //      cout << endl;
     // }


     // BFS on nodes to find connected components
     for(int i = 0; i < n; i++){
          // for( int i = 0; i<n; i++){
          //     cout << visited[i] << " ";
          // }
          // cout << endl;

          if(!visited[i]){
               ans++;
               q.push(i);        // 1 . Push on Stack

               while(!q.empty()){
                    int current = q.front();    // Pop Top
                    q.pop();
                    visited[current] = true;    // Mark Visited

                    // Push unvisited neighbors on the stack
                    for(int neighbour  : adjList[current]){
                         // cout << "nei h " << neighbour << endl;
                         if(!visited[neighbour]) 
                              q.push(neighbour);
                    }
               }
          }             
     }

     return ans;
}