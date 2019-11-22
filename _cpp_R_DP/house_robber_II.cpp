#include "_r_dp.h"
    
/** LeetCode M | 213
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
 */

/**
 * Solution:
 * This problem is a little tricky at first glance.
 * However, if you have finished the House Robber problem, this problem 
 * can simply be decomposed into two House Robber problems.
 * 
 * Suppose there are n houses, since house 0 and n - 1 are now neighbors,
 * we cannot rob them together and thus the solution is now the maximum of
 * 
 * 1. Rob houses 0 to n - 2;
 * 2. Rob houses 1 to n - 1.
 * The code is as follows. Some edge cases (n < 2) are handled explicitly.
 */
int rob_2(vector<int>& nums) {
    if(nums.size() == 0){
        return 0;
    }
    
    if(nums.size() == 1){
        return nums[0];
    }

    if(nums.size() == 2){
        return std::max(nums[0], nums[1]);
    }
    
    vector<int>nums1(nums.begin(), nums.end() - 1);
    vector<int>nums2(nums.begin() + 1, nums.end());
    
    return max(rob(nums1), rob(nums2));
}