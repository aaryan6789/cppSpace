/**
 * Given a matrix with r rows and c columns, find the maximum score of a path
 * starting at [0, 0] and ending at [r - 1, c - 1]. 
 * 
 * The score of a path is the minimum value in that path. 
 * For example, the score of the path 8 → 4 → 5 → 9 is 4.
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;


/**
 * Thought process:

Iterate over first row and column. The minimum value must be propagated all the way down the line.
Example:
6, 7, 8
5, 4, 2
8, 7, 6
The top row becomes 6, 6, 6 and the first column becomes 6, 5, 5. Resulting matrix:
6, 6, 6
5, 4, 2
5, 7, 6

Each of the internal elements in the grid will be the minimum of (1) itself, (2) the element above it in the grid, or (3) the element left of it in the grid. Therefore, we want to choose the maximum of two minimum comparisons. Example:
i = 1, j = 1, element = 4.
[i-1, j] = [0, 1] = 6
[i, j-1] = [1, 0] = 5
Therefore, we keep the element 4, since max(min(4, 6), min(4, 5)) == max(4, 4) == 4. For similar reasons, element [1, 2] will remain 2.

Element [2,1], however, will become 5. Note that position [2, 1] can be reached via 6 -> 5 -> 5 -> 7, so we select max(5, 4) and choose 5 as the new element:
i = 2, j = 1, element = 7.
[i-1, j] = [1, 1] = 4
[i, j-1] = [2, 0] = 5
max(min(7, 4), min(7, 5)) == max(4, 5) == 5.
For similar reasons, element [2, 2] will become 5.

We return the value in the bottom right. The answer is 5.

Edit: There is a minor error in this solution, please see the replies to this comment for potential fixes. (We are supposed to ignore the first and last element in the path, which we can achieve with only minor adjustments to this algorithm.)
 */


int maxScore(vector<vector<int> >& grid){
    if (grid.empty()) 
        return 0;

    int R = grid.size();;
    int C = grid[0].size();
    
    for (int i = 1; i < C; i++){
        grid[0][i] = min(grid[0][i], grid[0][i-1]);
    }

    for (int i = 1; i < R; i++){
        grid[i][0] = min(grid[i][0], grid[i-1][0]);
    }

    for (int i = 1; i < R; i++){
        for (int j = 1; j < C; j++){
            grid[i][j] = max(min(grid[i-1][j], grid[i][j]),
                             min(grid[i][j-1], grid[i][j]));
        }
    }

    return grid[R-1][C-1];
}
