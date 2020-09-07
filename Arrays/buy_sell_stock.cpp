#include <vector>
using namespace std;
/// Exactly same as C
/** Best Time to Buy and Sell Stock | Leetcode Easy 121
 *
 * You have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction
 * (i.e., buy one and sell one share of the stock),
 * design an algorithm to find the maximum profit.
 *
 * Note that you cannot sell a stock before you buy one.
 *
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *              Not 7-1 = 6, as selling price needs to be larger than buying price.
 *
 * Example 2:
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */


int maxProfit(vector<int>& prices) {
    if(prices.size() == 0 || prices.size() == 1 )
        return 0;

    int min_so_far = prices[0];
    int max_profit = 0;
    int cur_profit = 0;

    for(int i = 1; i<prices.size(); i++ ){
        cur_profit = prices[i] - min_so_far;
        max_profit = max(cur_profit, max_profit);
        min_so_far = min(prices[i], min_so_far);
    }

    return max_profit;
}

/**
 * Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time
 * (i.e., you must sell the stock before you buy again).
 *
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 *              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 *
 * Example 2:
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 *              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 *              engaging multiple transactions at the same time. You must sell before buying again.
 *
 * Example 3:
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

int maxProfitMany(vector<int>& prices) {
	if(prices.size() == 0 || prices.size() == 1){
		return 0;
	}

	int maxProfit = 0;
	for(int i = 1; i<prices.size(); i++){
		if(prices[i] > prices[i-1]){
			maxProfit += (prices[i] - prices[i-1]);
		}
	}
	return maxProfit;

}
