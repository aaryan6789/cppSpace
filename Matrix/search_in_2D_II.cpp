#include "_matrix.h"
/** 240. Search a 2D Matrix II | LEETCODE M | 
 * Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * Example:
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 */

/** BINARY SEARCH + TOP RIGHT ELEMENT as the mid
 * Search from the top-right element and reduce the search space by one row or column at each time.

[[ 1,  4,  7, 11, 15],
 [ 2,  5,  8, 12, 19], 
 [ 3,  6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]]
Suppose we want to search for 12 in the above matrix. 
compare 12 with the top-right element nums[0][4] = 15. 

Since 12 < 15, 12 cannot appear in the column of 15 since all elements in that
column are greater than or equal to 15. 

Now we reduce the search space by one column (the last column).
We further compare 12 with the top-right element of the remaining matrix, 
which is nums[0][3] = 11. Since 12 > 11, 12 cannot appear in the row of 11 since
all elements in this row are less than or equal to 11 (the last column has been discarded). 

Now we reduce the search space by one row (the first row).

We move on to compare 12 with the top-right element of the remaining matrix, 
which is nums[1][3] = 12. 
Since it is equal to 12, we return true.
 */
bool searchMatrixI(vector<vector<int>>& matrix, int target) {
    // TOP_RIGHT ELEMENT COMPARISON + BINARY SEARCH
    
    int R = matrix.size();
    if(R == 0) return false;
    int C = matrix[0].size();
    
    int r = 0;
    int c = C - 1;
    
    while(r < R && c>=0){
        if(target == matrix[r][c]){
            return true;
        }
        else if(target < matrix[r][c]){
            c--;
        }
        else{
            r++;
        }
    }
    
    return false;
}

/**
 * Time complexity : O(n+m)

The key to the time complexity analysis is noticing that, on every iteration 
(during which we do not return true) either row or col is is decremented/incremented exactly once. 
Because row can only be decremented m times and col can only be incremented n times 
before causing the while loop to terminate, the loop cannot run for more than n+m iterations. 

Because all other work is constant, the overall time complexity is linear in 
the sum of the dimensions of the matrix.

Space complexity : O(1)

Because this approach only manipulates a few pointers, its memory footprint is constant.
 */