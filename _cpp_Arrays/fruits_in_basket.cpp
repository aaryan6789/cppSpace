
/** LeetCode M | GOOG/AMZN
 * In a row of trees, the i-th tree produces fruit with type tree[i].
 *
 * You start at any tree of your choice, then repeatedly perform the following steps:
 *
 * 1. Add one piece of fruit from this tree to your baskets.
 *    If you cannot, stop.
 * 2. Move to the next tree to the right of the current tree.
 *    If there is no tree to the right, stop.
 *
 * Note that you do not have any choice after the initial choice of starting
 * tree: you must perform step 1, then step 2, then back to step 1, then step 2,
 * and so on until you stop.
 *
 * You have two baskets, and each basket can carry any quantity of fruit,
 * but you want each basket to only carry one type of fruit each.
 *
 * What is the total amount of fruit you can collect with this procedure?
 *
 * Example 1:
 *
 * Input: [1,2,1]
 * Output: 3
 * Explanation: We can collect [1,2,1].
 * Example 2:
 *
 * Input: [0,1,2,2]
 * Output: 3
 * Explanation: We can collect [1,2,2].
 * If we started at the first tree, we would only collect [0, 1].
 * Example 3:
 *
 * Input: [1,2,3,2,2]
 * Output: 4
 * Explanation: We can collect [2,3,2,2].
 * If we started at the first tree, we would only collect [1, 2].
 * Example 4:
 *
 * Input: [3,3,3,1,2,1,1,2,3,3,4]
 * Output: 5
 * Explanation: We can collect [1,2,1,1,2].
 * If we started at the first tree or the eighth tree, we would only collect 4 fruits.
 *
 *
 * Note:
 *
 * 1 <= tree.length <= 40000
 * 0 <= tree[i] < tree.length
 */

#include "_array.h"
// Sliding Window
/**
Algorithm:
1. You have two indexes, i and your index j (the end)
2. Store the frequency of elements in a hash map as you iterate
3. Any time the size (number of key/value pairs) in your hash map goes above 2,
    increment your start index "i" and remove elements from your hash map until the size is back to 2
4. Keep track of the maximum total fruits as you go
*/
// Time = O(N)
// Space = O(N)
int totalFruit(vector<int>& tree) {
    if(tree.size() == 0 || tree.size() == 1){
        return tree.size();
    }
    int ans = 0;
    // Sliding window
    unordered_map<int, int> count;
    int i = 0;
    int j = 0;

    while(j < tree.size()){
        count[tree[j]]++;
        j++;

        // If the Map size goes beyond 2 then
        while(count.size() > 2){
            count[tree[i]]--;

            if(count[tree[i]] == 0){
                count.erase(tree[i]);
            }
            i++;
        }

        ans = max(ans, j-i);
    }

    return ans;


}


int totalFruit2(vector<int>& tree) {
    if(tree.size() == 0 || tree.size() == 1){
        return tree.size();
    }
    int ans = 0;
    // Sliding window
    unordered_map<int, int> count;
    int i = 0;
    int j = 0;

    while(j < tree.size()){
        count[tree[j]]++;
        cout << "j " << j << " i " << i << " tree[j]" << tree[j] << " count[" << tree[j] << "] " << count[tree[j]] << endl;
        j++;


        if (count.size() > 2){
            count[tree[i]]--;

            if(count[tree[i]] == 0){
                count.erase(tree[i]);
            }
            i++;
        }
    }

    return tree.size() - i;
}



int totalFruit1(vector<int>& tree) {
    vector<int> fruits(tree.size());

    int lo = 0, hi = 0, maxFruit = 0, baskets = 2;
    while (hi < tree.size()){
        if (fruits[tree[hi]]++ == 0)
            baskets--;
        while (baskets < 0){
            maxFruit = max(hi-lo, maxFruit);
            if (--fruits[tree[lo++]] == 0)
                baskets++;
        }
        hi++;
    }
    return max(maxFruit, hi-lo);
}