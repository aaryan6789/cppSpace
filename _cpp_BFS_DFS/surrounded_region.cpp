#include "_helper.h"

/**
 * 1. First, check the four border of the matrix. If there is a element is
 *     'O', alter it and all its neighbor 'O' elements to '1'.
 * 2. Then ,alter all the 'O' to 'X'
 * 3. At last,alter all the '1' to 'O'
 * 
 * For example:
 * 
 *     X X X X           X X X X             X X X X
 *     X X O X  ->       X X O X    ->       X X X X
 *     X O X X           X 1 X X             X O X X
 *     X O X X           X 1 X X             X O X X
 **/
void check(vector<vector<char>>& board, int i, int j);
void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int row = board.size(), col = board[0].size();
    for (int i = 0; i < row; ++i) {
        check(board, i, 0);             // first column
        check(board, i, col - 1);       // last column
    }
    for (int j = 1; j < col - 1; ++j) {
        check(board, 0, j);             // first row
        check(board, row - 1, j);       // last row
    }
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == '1') board[i][j] = 'O';
}

void check(vector<vector<char>>& board, int i, int j) {
    if (board[i][j] == 'O') {
        board[i][j] = '1';
        
        if (i > 1) 
            check(board, i - 1, j);
        
        if (j > 1) 
            check(board, i, j - 1);
        
        if (i + 1 < board.size()) 
            check(board, i + 1, j);
        
        if (j + 1 < board[0].size()) 
            check(board, i, j + 1);
    }
}