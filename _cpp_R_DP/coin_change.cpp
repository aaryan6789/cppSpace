#include "_r_dp.h"

/** LeetCode M | 322 | CTCI
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins,
 * return -1.
 *
 * Example 1:
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 * Example 2:
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 */

// Readable
int coinChange(vector<int>& coins, int amount)
{
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for(int i = 0; i <= amount; ++i){
        for(int j = 0; j < coins.size(); ++j){
            if(coins[j] <= i)
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int coinChange2(vector<int>& coins, int amount) {
    vector<int> need(amount+1, amount+1);
    need[0] = 0;

    for (int i : coins)
        for (int j=i; j<=amount; j++)
            need[j] = min(need[j], need[j-i] + 1);

    return need.back() > amount ? -1 : need.back();
}