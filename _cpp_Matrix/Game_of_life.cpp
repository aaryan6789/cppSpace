#include "_matrix.h"

/** GAME OF LIFE | 289 LC M |https://leetcode.com/problems/game-of-life/
 * Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
 */

void gameOfLife(vector<vector<int>>& board) {
    vector<vector<int>> dirs {{0, 1}, {1, 1}, {0, -1}, {-1, -1}, {1, 0},{1, -1}, {-1, 0}, {-1, 1}};
    
    int R = board.size();
    int C = board[0].size();
    
    // Iterate thrugh the board Cell by cell
    for(int i=0; i<R; i++){
        for(int j = 0; j<C; j++){
            // For each cell count the number of live neighbors
            int live = 0;
            for(auto dir : dirs){
                int r = i + dir[0];
                int c = j + dir[1];
                
                if(r<0 || r>=R || c<0 || c>= C)
                    continue;
                
                // Calculate Live cells from 1 or -1 
                if(board[r][c] == 1 || board[r][c] == -1){
                    live++;
                }
            }
            
            // Apply Rules
            // Rule 1 or 3 : Live --> Dead
            if(board[i][j] == 1 && (live<2 || live>3)){
                // -1 : Live --> Dead
                board[i][j] = -1;
            }
            
            // Rule 4 : Dead --> Live
            if(board[i][j] == 0 && live == 3){
                board[i][j] = 2;    // 2 means Dead --> live
            }
        }
    }
    
    // Get the Final Representation of the board
    for(int i=0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(board[i][j] > 0){
                board[i][j] = 1;
            }
            else{
                board[i][j] = 0;
            }
        }
    }
}
/**
 * Complexity Analysis
 * Time Complexity: O(M×N), where M is the number of rows and N is the number of columns of the Board.
 * Space Complexity: O(1)
 */


// Extra Space for keeping the copy of the board
/** Algorithm:
1. Make a copy of the original board which will remain unchanged throughout the process.
2. Iterate the cells of the Board one by one.
3. While computing the results of the rules, use the copy board and apply the result in the original board.
**/
void gameOfLife2(vector<vector<int>>& board) {
    
    vector<vector<int>> dirs {{0, 1}, {1, 1}, {0, -1}, {-1, -1}, {1, 0},{1, -1}, {-1, 0}, {-1, 1}};
    
    int R = board.size();
    int C = board[0].size();
    
    // Create a Copy of the board
    vector<vector<int>> copy(R, vector<int>(C));
    for(int i= 0; i< R; i++){
        for(int j = 0; j<C; j++){
            copy[i][j] = board[i][j];
        }
    }
    
    // Iterate thrugh the board Cell by cell
    for(int i=0; i<R; i++){
        for(int j = 0; j<C; j++){
            // For each cell count the nuber of live neighbors
            int live = 0;
            for(auto dir : dirs){
                int r = i + dir[0];
                int c = j + dir[1];
                
                if(r<0 || r>=R || c<0 || c>= C)
                    continue;
                
                if(copy[r][c] == 1){
                    live++;
                }
            }
            
            // Check for the Rules now
            // Rule 1 and 3
            if(copy[i][j] == 1 && (live<2 || live > 3)){
                board[i][j] = 0;
            }
            
            // Rule 4
            if(copy[i][j] == 0 && live == 3){
                board[i][j] = 1;
            }
        }
    }
}