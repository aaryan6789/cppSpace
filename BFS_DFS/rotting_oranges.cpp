#include "_helper.h"

/** ROTTING ORANGES 
 * LEETCODE E/M | https://leetcode.com/problems/rotting-oranges/
 * In a given grid, each cell can have one of three values:
 * 
 * the value 0 representing an empty cell;
 * the value 1 representing a fresh orange;
 * the value 2 representing a rotten orange.
 * Every minute, any fresh orange that is adjacent (4-directionally) to a rotten
 * orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a fresh
 * orange.  If this is impossible, return -1 instead.
 * 
 * Example 1:
 * Input: [[2,1,1],
 *         [1,1,0],
 *         [0,1,1]]
 * Output: 4
 * 
 * Example 2:
 * Input: [[2,1,1],
 *         [0,1,1],
 *         [1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 *  rotten, because rotting only happens 4-directionally.
 * 
 * Example 3:
 * Input: [[0,2]]
 * Output: 0
 * Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 *  
 * 
 * Note:
 * 
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * grid[i][j] is only 0, 1, or 2.
 */

// You would think of doin git as Num Islands but look at the questions again.
// Its actually level order BFS.

// Level Order BFS Algo
// 1. We count the fresh oranges and store all rotted oranges by using a queue.
// 2. Iterating, scan through the queue and "rotting" the fresh neighbors, until there are no new rotted oranges.
// 3. During every scanning, if there are new rotted oranges, we count the minute.
// 4. If the queue is empty and there are no fresh oranges, return the minutes. Otherwise, -1

int orangesRotting(vector<vector<int>>& grid) {
    int R = grid.size();
    int C = grid[0].size();
    int fresh = 0;
    queue<pair<int, int>> q;
    
    for(int i = 0; i< R; i++){
        for(int j = 0; j< C; j++){
            
            if(grid[i][j] == 2){
                q.push({i, j});
            }
            
            // Calculate the number of Fresh Oranges
            if(grid[i][j] == 1){
                fresh++;
            }
        }
    }
    
    int minutes = 0;
    while(fresh != 0 && !q.empty()){            
        int size = q.size();
        for(int i = 0; i< size; i++){
            pair<int, int> rott = q.front();
            q.pop();
            
            int r = rott.first;
            int c = rott.second;
            
            if(r-1 >= 0 && grid[r-1][c] == 1){
                q.push({r-1, c});
                grid[r-1][c] = 2;
                fresh--;
            }
            
            if(r+1 < R && grid[r+1][c] == 1){
                q.push({r+1, c});
                grid[r+1][c] = 2;
                fresh--;
            }
            
            if(c-1 >= 0 && grid[r][c-1] == 1){
                q.push({r, c-1});
                grid[r][c-1] = 2;
                fresh--;
            }
            
            if(c+1 < C && grid[r][c+1] == 1){
                q.push({r, c+1});
                grid[r][c+1] = 2;
                fresh--;
            }
        }
        minutes++;
    }

    if(fresh != 0){
        return -1;
    }
    else{
        return minutes;
    }
}

// Time Complexity = O(N), where N is the number of cells in the grid.
