#include "_r_dp.h"

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