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


// Pay Attention here as it is askign for the fewest number of combinations and
// NOT THE TOTAL NUMBER OF WAYS

// Approach - Using DP + Cache
// We make a Cache where we keep the amount as its index

// cache        0   1   2   3   4   5   6   7   8   9   10     11
//              0  12  12  12  12  12  12   12  12  12  12     12
// Coins    1   0   1   2   3   4   5   6   7   8   9   10     11
//          2   0   1   1   2   2   3   3   4   4   5   5      6
//          5   0   1   1   2   2   1   2   2   3   3   3      3

// Steps :
// 1. Make a cache and initialize it to amount+1
//    Each cell in this array is saying min amount of coins needed to make this amount
// 2. 2 Loops
//    1st loop : Go through all the indexes in the cache
//    2nd loop : Go through all the coins in the coins array
//           : If the Coin value is less than the current amount
//           : then the fewest ways would be the minimum of current value and (currAmnt - curr coin value) + 1


// Readable
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for(int currAmt = 0; currAmt <= amount; currAmt++){
        for(int j = 0; j < coins.size(); j++){
            if(coins[j] <= currAmt)
                dp[currAmt] = min(dp[currAmt], dp[currAmt - coins[j]] + 1);
        }
    }

    if(dp[amount] > amount){
        return -1;
    }
    
    return dp[amount];

    // In short this is the answer
    // return dp[amount] > amount ? -1 : dp[amount];
}