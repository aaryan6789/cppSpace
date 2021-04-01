#include <vector>
#include <iostream>
using namespace std;

/*** https://leetcode.com/problems/minesweeper/
 * Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 
'M' represents an unrevealed mine, 
'E' represents an unrevealed empty square, 
'B' represents a revealed blank square that has no adjacent 
(above, below, left, right, and all 4 diagonals) mines, 

digit ('1' to '8') represents how many mines are adjacent to this revealed square, 
and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed 
squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.

If an empty square ('E') with no adjacent mines is revealed, 
then change it to revealed blank ('B') and 
all of its adjacent unrevealed squares should be revealed recursively.

If an empty square ('E') with at least one adjacent mine is revealed, 
then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.
 

Example 1:

Input:          Click : [3,0]

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]


Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Example 2:

Input:          Click : [1,2] 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Note:
1. The range of the input matrix's height and width is [1,50].
2. The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
3. The input board won't be a stage when game is over (some mines have been revealed).
For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.
 */

class Minesweeper {
    vector<vector<char>> board;

public:

    Minesweeper(vector<vector<char>>& bd){
        board = bd;
    }

public:

    // Check if the cell is valid or not
    bool isValid(const vector<vector<char>>& board, int x, int y){
        int R = board.size();
        int C = board[0].size();
        
        if(x<0 || x >= R || y<0 || y>= C){
            return false;
        }

        return true;
    }

    // DFS Recursively to fill the adjacent nodes
    void dfs(vector<vector<char>>& board, int x, int y){
        if(!isValid(board, x, y))  
            return;
        
        // The 8 Cells its going to touch
        vector<vector<int>> dirs = {{ 1, 0} , {0, 1}, {-1, 0}, {0, -1},
                                    {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        
        // Count is the number of Mines adjacent to the clicked cell
        int count = 0;
        if(board[x][y] == 'E'){
            for(auto d : dirs){
                int r = d[0] + x;
                int c = d[1] + y;
                
                // If there is a MINE in the adjacent 8 cells then increment the count
                if(isValid(board, r, c) && board[r][c] == 'M'){
                    count++;
                }
            }
            
            // Update the value of the current cell by the count value
            if(count > 0){
                board[x][y] = '0' + count;
            }
            else {  // If not then the safe value is B
                board[x][y] = '_';
                
                // carry out the DFS from the adjacent cells also
                for(auto d : dirs){
                    int r = d[0] + x;
                    int c = d[1] + y;
                    
                    dfs(board, r, c);
                }
            }
        }        
    }
    
    // This is a DFS Problem.
    // What we do is we figure out the mine first and make it the Root node for DFS.
    // We update the adjacent cells from this root node and if there are more then we update the numbers incrementally.
    void updateBoard(vector<int>& click) {
        cout << "Update the Board" << endl;
        // Find out the click position
        int x = click[0];
        int y = click[1];
        
        // GAME OVER if the click is a mine
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return;
        }
        
        // IF NOT then do DFS with click to be the root node that is the cell that is clicked
        dfs(board, x, y);
        return;
    }

    // A Function to print the current gameplay board 
    void printBoard() { 
        int i, j; 

        for (i=0; i<board[0].size(); i++) {
            for (j=0; j<board[0].size(); j++) 
                printf ("%c ", board[i][j]); 
            printf ("\n");
        } 
        return; 
    }
};


int main() {
    vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'M', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'}};
    
    Minesweeper m(board);
    vector<int> move1 = {0, 0};

    // m.printBoard();
    // m.updateBoard(board, move1);
    m.updateBoard(move1);

    vector<int> move2 = {2, 2};

    m.updateBoard(move2);
    
    m.printBoard();
}