#include "_r_dp.h"
/**
 * LeeTCODE M | https://leetcode.com/problems/minimum-path-sum/
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 * Input:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */

int minPathSum(vector<vector<int>>& grid) {
    int R = grid.size();
    int C = grid[0].size();

    int dp[R][C];
    dp[0][0] = grid[0][0];

    // Populate the 1st row
    for(int j = 1; j< C; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // Populate the 1st row
    for(int i = 1; i< R; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    // Populate the rest of the matrix
    for(int i = 1; i< R; i++){
        for(int j = 1; j< C; j++){
            dp[i][j] = grid[i][j] + min(dp[i-1][j],
                                        dp[i][j-1]);
        }
    }

    return dp[R-1][C-1];

}