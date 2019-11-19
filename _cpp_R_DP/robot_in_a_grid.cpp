#include "_r_dp.h"

/* CTCI 6th 8.2 | Robot in a Grid:
 * Imagine a robot sitting on the upper left corner of grid with
 * r rows and c columns.
 * The robot can only move in two directions, right and down, but certain cells
 * are "off limits" such that the robot cannot step on them.
 *
 * If the matrix or the Grid is shown with 0s and 1s.
 * Then the 1 means its off limits.
 *
 * Design an algorithm to find a path for the robot from the top left to
 * the bottom right.
 *
 * Input:
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 *
 * Output: 2 or True
 *
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 *
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 */

int pathGrid(vector<vector<int>>& grid){
	int R = grid.size();
	int C = grid[0].size();

	int dp[R][C];		// Additional Data Structure
	dp[0][0] = 0;

	// Populate first Column
	for( int j = 1; j<=R; j++){
		if(grid[0][j] == 1)
			dp[0][j] = 0;
		else
			dp[0][j] = 1;
	}

	// Populate first Row
	for( int i = 1; i<=C; i++){
		if(grid[i][0] == 1)
			dp[i][0] = 0;
 		else
			dp[i][0] = 1;
	}

	// Populate other Cells
	for(int r = 1; r<=R; r++){
		for(int c = 1; c<=C; c++){
			if(grid[r][c] == 0){
				dp[r][c] = dp[r-1][c] + dp[r][c-1];
			}
			else{
				dp[r][c] = 0;
			}
		}
	}

	printf("Total Paths Possible from top to bottom right = %d\n", dp[R-1][C-1]);

	return (dp[R-1][C-1]);

	// just for something else
	char *p;
	printf("Size Of %lu , %lu\n", sizeof(p), sizeof(*p));
}
