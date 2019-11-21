#include "_r_dp.h"
#include <algorithm>
/** Leetcode E | https://leetcode.com/problems/min-cost-climbing-stairs/
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
 * 
 * Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
 * 
 * Example 1:
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
 * Example 2:
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
 * Note:
 * cost will have a length in the range [2, 1000].
 * Every cost[i] will be an integer in the range [0, 999].
 */

int minCostClimbingStairs1(vector<int>& cost) {
    int f1 = 0, f2 = 0;
    for (int i = cost.size() - 1; i >= 0; --i) {
        int f0 = cost[i] + min(f1, f2);
        f2 = f1;
        f1 = f0;
    }
    return min(f1, f2);
}

int minCostClimbingStairs2(vector<int>& cost) {
    int dp[cost.size() + 1];

    dp[0] = cost[0];
    dp[1] = cost[1];
    int c = 0;
    
    for(int i = 2; i <= cost.size(); i++) {    
        if(i >= cost.size()) {
            c = 0;
        }
        else {
            c = cost[i];
        }
        dp[i] = c + min(dp[i-1], dp[i-2]);
    }

    return dp[cost.size()];
}
