#include "_helper.h"

/** 01 MATRIX | LEETCODE M | https://leetcode.com/problems/01-matrix/
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 
 * for each cell.
 * 
 * The distance between two adjacent cells is 1.
 * Example 1:
 * Input:
 * [[0,0,0],
 *  [0,1,0],
 *  [0,0,0]]
 * 
 * Output:
 * [[0,0,0],
 *  [0,1,0],
 *  [0,0,0]]
 * 
 * Example 2:
 * Input:
 * [[0,0,0],
 *  [0,1,0],
 *  [1,1,1]]
 * 
 * Output:
 * [[0,0,0],
 *  [0,1,0],
 *  [1,2,1]]
 *  
 * Note:
 * 1. The number of elements of the given matrix will not exceed 10,000.
 * 2. There are at least one 0 in the given matrix.
 * 3. The cells are adjacent in only four directions: up, down, left and right.
 */

// Method 1 : BFS + Extra Distance Matrix
/**
 * Time complexity: O(R * C).
 * Since, the new cells are added to the queue only if their current distance is greater than the  
 * calculated distance, cells are not likely to be added multiple times.
 * 
 * Space complexity: O(r⋅c). Additional O(R*C) for queue than in Approach #1
**/
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int R = matrix.size();
    if(R == 0) return matrix;
    int C = matrix[0].size();
    
    vector<vector<int>> dist(R, vector<int>(C));
    queue<pair<int, int>> q;    
    
    for( int i = 0; i< R; i++){
        for(int j = 0; j< C; j++){
            if( matrix[i][j] == 0){
                dist[i][j] = 0;
                q.push({i, j}); //Put all 0s in the queue.
            }
            else{
                dist[i][j] = INT_MAX;
            }
        }
    }
    
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        int dst = dist[x][y];
        
        // PArse the 4 directions now
        for(auto dir : dirs){
            int r = x + dir[0];
            int c = y + dir[1];
            
            if(r<0 || r>= R || c< 0 || c>= C || matrix[r][c] == 0){
                continue;
            }
            
            if(dist[r][c] > dst+1){
                dist[r][c] = dst + 1;
                q.push({r, c});
            }
        }
    }
    
    return dist;
}