#include "_r_dp.h"

/* Given a 2D array, find the total number of paths possible from top left cell
 * to bottom right cell if we are allowed to move only rightward and downward.
 *
 *
 */

/* This is very similar to the min Cost Path.
 *
 * 1. Recursive Solution:
 *
 * We start from the destination and move up.
 *
 * The cell (m,n) can be reached from 2 cells:
 * 1. The one above it : (m-1, n)
 * 2. The one on the left of it : (m, n-1)
 *
 * Suppose if there are P1 ways of reaching cell (m-1, n) and
 * P2 ways of reaching to the cell (m, n-1), then we can reach the cell (m,n)
 * in P1 + P2 unique ways via cell m-1, n and m, n-1.
 *
 * The terminating condition is when we hit the top row or leftmost column:
 * There is just one way to reach any cell in the top row.(Going Right Ward -->)
 * There is just one way to reach any cell in the left most col. ( Going downward)
 * The number of ways to reach 0,0 is zero as we are already here.
 *
 * Time Complexity : Exponential O(2^n)
 */

int totalPathCountR(int m, int n){
	// Base Case/ Terminating case
	if( m == 0 && n == 0)			// Cell 0,0
		return 1;

	if (m == 0 || n == 0){
		return 1;
	}

	int total = totalPathCountR(m-1, n) + totalPathCountR(m, n-1);
	return total;
}

/* 2. Dynamic Programming Solution : Bottom Up
 *
 * A data Structure : 2D array is used.
 * for the Matrix of m*n order Same as the given matrix.
 *
 * Each cell in the matrix will represent the total number of paths to reach
 * that cell from the top left cell. The last cell will hold the final value.
 *
 * 1. The terminating condition can be populated i.e the Top Row and the left most column
 * 2. The rest of the cells can be populated then:
 * 	  arr[i][j] = arr[i-1][j] + arr[i][j-1]
 *
 * 	Time Complexity: O(n2)
 * 	Space Complexity : O(m*n)
 */

int totalPathCountDP(int m, int n){
    // Make a Variable length 2D Array if the compiler allows it.
	// If not make it on the heap.
	int cache[m][n];

	cache[0][0] = 1;

    // Fill up first Row
	for(int j = 1; j<n; j++){			//<--- Not from 0 but with 1 pay attention here
		cache[0][j] = 1;
	}

    // Fill Up first Column
	for(int i = 1; i<m; i++){
		cache[i][0] = 1;
	}

	for(int i = 1; i<m; i++){
		for(int j = 1; j<n; j++){
			cache[i][j] = cache[i-1][j] + cache[i][j-1];
		}
	}

	printf("Total Path Ways to reach (%d , %d) from (0, 0) is %d\n", m, n, cache[m-1][n-1]);
	return cache[m-1][n-1];
}

// Returns count of possible paths to reach cell at row number m and column
// number n from the topmost leftmost cell (cell at 1, 1)
int  numberOfPaths(int m, int n)
{
   // If either given row number is first or given column number is first
   if (m == 1 || n == 1)
        return 1;

   // If diagonal movements are allowed then the last addition is required.
   return  numberOfPaths(m-1, n) + numberOfPaths(m, n-1);
           // + numberOfPaths(m-1,n-1);
}

// Next Problem: Follow Up: Robot In a Grid
/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish'
in the diagram below).

Now consider if some obstacles are added to the grids.
How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
 */


/**
 * Approach 1: Dynamic Programming
Intuition
The robot can only move either down or right. Hence any cell in the first row can
only be reached from the cell left to it.

And, any cell in the first column can only be reached from the cell above it.
For any other cell in the grid, we can reach it either from the cell to left of
it or the cell above it.

If any cell has an obstacle, we won't let that cell contribute to any path.
We will be iterating the array from left-to-right and top-to-bottom.
Thus, before reaching any cell we would have the number of ways of reaching the
predecessor cells.

This is what makes it a Dynamic Programming problem.
We will be using the obstacleGrid array as the DP array thus not utilizing any
additional space.

Note: As per the question, cell with an obstacle has a value 1.
We would use this value to make sure if a cell needs to be included in the path
or not. After that we can use the same cell to store the number of ways to reach
that cell.

Algorithm

1] If the first cell i.e. obstacleGrid[0,0] contains 1, this means there is an obstacle in the first cell. Hence the robot won't be able to make any move and we would return the number of ways as 0.
2] Otherwise, if obstacleGrid[0,0] has a 0 originally we set it to 1 and move ahead.
3] Iterate the first row. If a cell originally contains a 1, this means the current cell has an obstacle and shouldn't contribute to any path. Hence, set the value of that cell to 0. Otherwise, set it to the value of previous cell i.e. obstacleGrid[i,j] = obstacleGrid[i,j-1]
4] Iterate the first column. If a cell originally contains a 1, this means the current cell has an obstacle and shouldn't contribute to any path. Hence, set the value of that cell to 0. Otherwise, set it to the value of previous cell i.e. obstacleGrid[i,j] = obstacleGrid[i-1,j]
5] Now, iterate through the array starting from cell obstacleGrid[1,1]. If a cell originally doesn't contain any obstacle then the number of ways of reaching that cell would be the sum of number of ways of reaching the cell above it and number of ways of reaching the cell to the left of it.
 obstacleGrid[i,j] = obstacleGrid[i-1,j] + obstacleGrid[i,j-1]
6] If a cell contains an obstacle set it to 0 and continue. This is done to make sure it doesn't contribute to any other path.

 */

int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
	int row = obstacleGrid.size();
	int col = obstacleGrid[0].size();
	long long dp[row][col];
	for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) dp[i][j] = 0;
	dp[0][0] = 1;
	for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(!obstacleGrid[i][j]){
						if(i-1 >= 0) dp[i][j] += dp[i-1][j];
						if(j-1 >= 0) dp[i][j] += dp[i][j-1];
				}
				else dp[i][j] = 0;
			}
	}
	return dp[row-1][col-1];
}



int uniquePathsWithObstacles(int R, int C, int obstacleGrid[][C]) {
	// If the starting cell has an obstacle, then simply return as there would be
	// no paths to the destination.
	if (obstacleGrid[0][0] == 1) {
		return 0;
	}

	// Number of ways of reaching the starting cell = 1.
	obstacleGrid[0][0] = 1;

	// Filling the values for the first column
	for (int i = 1; i < R; i++) {
		obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
	}

	// Filling the values for the first row
	for (int i = 1; i < C; i++) {
		obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
	}

	// Starting from cell(1,1) fill up the values
	// No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
	// i.e. From above and left.
	for (int i = 1; i < R; i++) {
		for (int j = 1; j < C; j++) {
			if (obstacleGrid[i][j] == 0) {
				obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
			} else {
				obstacleGrid[i][j] = 0;
			}
		}
	}

	// Return value stored in rightmost bottommost cell. That is the destination.
	return obstacleGrid[R - 1][C - 1];
}



