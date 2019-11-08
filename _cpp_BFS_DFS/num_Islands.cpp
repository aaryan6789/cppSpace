#include "_helper.h"
using namespace std;

/**
 * https://leetcode.com/problems/number-of-islands/
 * LeetCode M | Number of Islands
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 *
 * Example 2:
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 */

/** Using DFS:
 * 1. Parse through the Matrix and Whenever you see a 1 you trigger the DFS.
 * 2. In the DFS function we check the top, left, right, bottom neighbors and
 *    mark them visited if its reached from the root node.
 */
static void helper(vector<vector<char>>& grid, int r, int c){
    int R = grid.size();
    int C = grid[0].size();

    if(r>=R || c>=C || r<0 || c<0 || grid[r][c] == '0'){
        return;
    }

    grid[r][c] = '0';

    helper(grid, r, c+1);
    helper(grid, r, c-1);
    helper(grid, r+1, c);
    helper(grid, r-1, c);
}

// Classic DFS Problem
int numIslandsDFS(vector<vector<char>>& grid) {
    if(grid.empty()){
        return 0;
    }

    int R = grid.size();
    int C = grid[0].size();
    int count = 0;
    for(int i = 0; i<R; i++){
        for(int j = 0; j< C; j++){
            if(grid[i][j] == '1'){
                count++;
                helper(grid, i, j);
            }
        }
    }

    return count;
}

/**
 * Using BFS
 * 1. Linear scan the 2d grid map, if a node contains a '1', then it is a root
 *    node that triggers a Breadth First Search.
 * 2. Put it on the Queue and set its value to 0 to mark it visited.
 * 3. Iteratively search the neighbors of enqueued nodes until the queue becomes
 *    empty.
 */
int numIslandsBFS(vector<vector<char>>& grid){
    int R = grid.size();
    int C = grid[0].size();

    int numIslands = 0;
    queue<pair<int, int>> q;

    for(int i = 0; i< R; i++){
        for(int j = 0; j< C; j++){
            if(grid[i][j] == '1'){
                numIslands++;
                grid[i][j] = '0';
                q.push({i, j});         // Push the Root Node on the Queue

                while(!q.empty()){      // Check for the Neighbors
                    auto& rc = q.front();
                    q.pop();

                    int r = rc.first;
                    int c = rc.second;

                    if(r-1 >= 0 && grid[r-1][c] == '1'){
                        q.push({r-1, c});
                        grid[r-1][c] = '0';
                    }

                    if(r+1 < R && grid[r+1][c] == '1'){
                        q.push({r+1, c});
                        grid[r+1][c] = '0';
                    }

                    if(c-1 >= 0 && grid[r][c-1] == '1'){
                        q.push({r, c-1});
                        grid[r][c-1] = '0';
                    }

                    if(c+1 < C && grid[r][c+1] == '1'){
                        q.push({r, c+1});
                        grid[r][c+1] = '0';
                    }
                }
            }
        }
    }

    return numIslands;
}

//Complexity Analysis
//Time complexity : O(M×N) where MM is the number of rows and NN is the number of columns.
//Space complexity : O(min(M,N)) because in worst case where the grid is filled with lands,
//  the size of queue can grow up to min(M,NM,N).
