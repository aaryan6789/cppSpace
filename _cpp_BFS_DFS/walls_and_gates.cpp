#include "_helper.h"

/**
 * WALLS AND GATES | LEETCODE M | 286 | https://leetcode.com/problems/walls-and-gates/
 * You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
 */



void dfs (vector<vector<int>>& rooms, int r, int c, int distance);
// Using DFS
void wallsAndGates(vector<vector<int>>& rooms) {
    int R = rooms.size();
    int C = R>0 ? rooms[0].size() : 0;
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (rooms[i][j] == 0) 
                dfs(rooms, i, j, 0);
        }
    }
    return;
}

void dfs (vector<vector<int>>& rooms, int r, int c, int distance) {
    // Terminating Condition
    // If the rooms[r][c] is less than the distance then we are already at the
    // nearest distance from one of the gates. So we can return early.
    if (r<0 || r>=rooms.size() || c<0 || c>=rooms[0].size() || rooms[r][c] < distance) 
        return;

    rooms[r][c] = distance;
    
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    for (int k=0; k<4; k++) {
        int i = r + dirs[k][0];
        int j = c + dirs[k][1];

        dfs(rooms, i, j, distance+1 );
    }

    return;
}


// BFS
// We initiate breadth-first search (BFS) from all gates at the same time. 
// Since BFS guarantees that we search all rooms of distance d before searching 
// rooms of distance d + 1, the distance to an empty room must be the shortest.

void wallsAndGatesBFS(vector<vector<int>>& rooms) {
    int R = rooms.size();
    if(R == 0) return;
    
    int C = rooms[0].size();
    
    queue<pair<int, int>> q;
    
    for( int i = 0; i< R; i++){
        for( int j = 0; j<C; j++){
            if(rooms[i][j] == 0){
                q.push({i, j});
            }
        }
    }
    vector<vector<int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        int row = temp.first;
        int col = temp.second;
        int dist = rooms[row][col];
        
        for(auto dir: dirs){
            int r = row + dir[0];
            int c = col + dir[1];
            
            // if x y out of range or it is obstasle, or has small distance aready
            if(r<0 || r>= R || c< 0 || c>= C || rooms[r][c] != INT_MAX){
                continue;
            }
            
            rooms[r][c] = dist + 1;
            q.push({r, c});
        }
        
    }
}

/**
 * Time complexity : O(R*C).
If you are having difficulty to derive the time complexity, start simple.

Let us start with the case with only one gate. 
The breadth-first search takes at most R×C steps to reach all rooms, 
therefore the time complexity is O(RC). 

But what if you are doing breadth-first search from kk gates?
Once we set a room's distance, we are basically marking it as visited, 
which means each room is visited at most once. 
Therefore, the time complexity does not depend on the number of gates and is O(mn)O(mn).

Space complexity : O(R*C). 
The space complexity depends on the queue's size. 
We insert at most R×C points into the queue.
 */