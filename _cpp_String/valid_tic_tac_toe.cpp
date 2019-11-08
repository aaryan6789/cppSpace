#include <iostream>
#include <string>
#include <vector>

using namespace std;

/** Tic Tac Toe | Leetcode M | CTCI
 * A Tic-Tac-Toe board is given as a string array board.
 * Return True if and only if it is possible to reach this board position during
 * the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".
The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.

Example 1:
Input: board = ["O  ",
                "   ",
                "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX",
                " X ",
                "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX",
                "   ",
                "OOO"]
Output: false

Example 4:
Input: board = ["XOX",
                "O O",
                "XOX"]
Output: true

Note:
1. board is a length-3 array of strings, where each string board[i] has length 3.
2. Each board[i][j] is a character in the set {" ", "X", "O"}.
 */

bool iswin(vector<string> &board, char c) {
    return ((board[0][0] == c && board[0][1] == c && board[0][2] == c) ||
            (board[1][0] == c && board[1][1] == c && board[1][2] == c) ||
            (board[2][0] == c && board[2][1] == c && board[2][2] == c) ||
            (board[0][0] == c && board[1][0] == c && board[2][0] == c) ||
            (board[0][1] == c && board[1][1] == c && board[2][1] == c) ||
            (board[0][2] == c && board[1][2] == c && board[2][2] == c) ||
            (board[0][0] == c && board[1][1] == c && board[2][2] == c) ||
            (board[0][2] == c && board[1][1] == c && board[2][0] == c));
}

bool validTicTacToe(vector<string>& board) {
    int xcnt = 0, ocnt = 0;

    for(string s: board) {
        for(char c: s) {
            if(c == 'X')
                xcnt++;
            else if(c == 'O')
                ocnt++;
        }
    }

    if(xcnt != ocnt && xcnt != ocnt + 1)
        return false;           // X can have equal or only 1 more move than O

    if(iswin(board, 'X') && xcnt != ocnt + 1)
        return false;           // X will win by having one additional move

    if(iswin(board, 'O') && xcnt != ocnt)
        return false;           // since X played first, O can win only when both have made same number of moves

    return true;
}