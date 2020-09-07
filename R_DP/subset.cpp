#include "_r_dp.h"
#include <algorithm>

/**
 * LeetCode M | 78 | https://leetcode.com/problems/subsets/
 * Given a set of distinct integers, nums, return all possible subsets
 * (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */
#include <vector>
using namespace std;

// Recursion (BackTracking)
vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> path;
    dfs(nums, 0, path, res);
    return res;
}

void dfs(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& res) {
    res.push_back(path);
    for (unsigned int i = index; i < nums.size(); i++) {
        path.push_back(nums[i]);
        dfs(nums, i+1, path, res);
        path.pop_back();
    }
}












/**
 * Iterative

Using [1, 2, 3] as an example, the iterative process is like:

1. Initially, one empty subset [[]]
2. Adding 1 to []: [[], [1]];
3. Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
4. Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
 */

/// DP
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> dp;

    dp.push_back({});

    for (auto i = 0; i < nums.size(); i++) {
        auto size = dp.size();

        for (auto j = 0; j < size; j++) {
            auto v = dp[j];
            v.push_back(nums[i]);
            dp.push_back(v);
        }
    }
    return dp;
}