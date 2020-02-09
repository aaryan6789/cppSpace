#include "_array.h"

/** Leetcode E | CTCI 
 * https://leetcode.com/problems/find-the-duplicate-number/
 * Given an array nums containing n + 1 integers where each integer is between 1 and n
 * (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Example 1:
 *
 * Input: [1,3,4,2,2]
 * Output: 2
 * Example 2:
 *
 * Input: [3,1,3,4,2]
 * Output: 3
 * Note:
 *
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 */
/**
 * Using HashMap
 * O(n) And O(K) Time and Space Complexity
 */

int findDuplicateE1(vector<int>& nums) {
    int len = nums.size();
    int hash[len];

    for(int i = 0; i< nums.size() ; i++){
        hash[nums[i]] += 1;

        if(hash[nums[i]] == 2){
            return nums[i];
        }
    }

    return -1;
}

int findDuplicateE2(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i] != i + 1) {
            if (nums[nums[i] - 1] == nums[i]) 
                return nums[i];
            
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    return 0;       // Return -1
}

/**
 * MEDIUM 442 https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array),
 * some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
 */

vector<int> findDuplicates1(vector<int>& nums) {
    unordered_map<int, int> map;
    vector<int> res{};
    for(auto& item : nums){
        map[item]++;
        if(map[item] == 2){
            res.push_back(item);
        }
    }

    return res;
}


    vector<int> findDuplicates2(vector<int>& nums) {        
        vector<int> res;
        for(int i = 0; i < nums.size(); i ++){
            int idx = abs(nums[i]) - 1;
            nums[idx] = -nums[idx];
            
            if(nums[idx] > 0) 
                res.push_back(idx+1);
        }
        return res;
    }