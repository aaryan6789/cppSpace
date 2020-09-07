#include "_r_dp.h"

/** LeetCode M | 322 | CTCI
 *
Suppose you are given the coins 1 cent, 5 cents, and 10 cents with N = 8 cents, 
what are the total number of permutations of the coins you can arrange to obtain 8 cents.

Input : N=8         Coins : 1, 5, 10
Output : 2

Explanation: 1 way: 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 8 cents.
             2 way: 1 + 1 + 1 + 5 = 8 cents.

Input : N = 10        Coins : 1, 5, 10
Output : 4
Explanation: 1 way: 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 10 cents.
             2 way: 1 + 1 + 1 + 1 + 1 + 5 = 10 cents.
             3 way: 5 + 5 = 10 cents.
             4 way: 10 cents = 10 cents.

*/
// https://www.geeksforgeeks.org/understanding-the-coin-change-problem-with-dynamic-programming/?ref=rp
int makeChange(vector<int>& coins, int amount) {
    int size = coins.size();
    
    vector<int> cache(amount + 1, 0);
    
    cache[0] = 1;
    
    for(int i = 0; i< size; i++){
        for(int j = 0; j<= amount; j++){
            if(coins[i] <= j){
                cache[j] += cache[ j - coins[i]]; // For Total Ways
            }
        }
    }
    
    return cache[amount];
    
    
}