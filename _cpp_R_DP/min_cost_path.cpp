#include "_r_dp.h"
/* Min Cost Path | Amazon
 * Given a cost matrix cost[][] and a position (m, n) in cost[][],
 * write a function that returns cost of minimum cost path to reach (m, n) from (0, 0).
 *
 * Each cell of the matrix represents a cost to traverse through that cell.
 * Total cost of a path to reach (m, n) is sum of all the costs on that path
 * (including both source and destination).
 *
 * You can only traverse down, right and diagonally lower cells from a given cell,
 * i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1)
 * can be traversed.
 *
 * You may assume that all costs are positive integers.
 *
 * Example:
 * Input: [
 * 		   [1,3,1],
 * 		   [1,5,1],
 * 		   [4,2,1]
 * 		  ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */

int minCostPathR(vector<vector<int>>& cost, int m, int n){
	int R = cost.size();
	int C = cost[0].size();
	// Base Case/ Terminating R Case
	if(m<0 || n<0)
		return INT_MAX;

	if(m == 0 && n == 0)		// Cell 0,0
		return cost[m][n];

	int minCost = cost[m][n] + min({
									minCostPathR(cost, m-1, n),
									minCostPathR(cost, m, n-1),
									minCostPathR(cost, m-1, n-1)
									});

	return minCost;
}

/* 2 : DP Solution
 *
 * Data Structure: 2D Array and of the order R+1 * C+1
 *
 *
 *
 */
int minCostPathDP(vector<vector<int>> cost, int m, int n){
	int R = cost.size();
	int C = cost[0].size();

	// vector<vector<int>> dp(R, vector<int>(C, 0));
	vector<vector<int>> dp;
	dp[0][0] = cost[0][0];

	// Populate the First Row
	for(int j = 1; j<= n; j++){
		dp[0][j] = dp[0][j-1] + cost[0][j];
	}

	// Populate the First Col
	for(int i = 1; i<= m; i++){
		dp[i][0] = dp[i-1][0] + cost[i][0];
	}

	//PS: Diagonal can not be populated as the other 2 moves can affect this calculated value

	// Populate the rest of the array
	for(int i=1; i<=m; i++){
		for(int j = 1; j<=n; j++){
			dp[i][j] = cost[i][j] + std::min({
											dp[i-1][j-1],
											dp[i-1][j],
											dp[i][j-1]
											});
		}
	}

	printf("Min Cost Path is with %d cost\n", dp[m][n]);
	return dp[m][n];
}
