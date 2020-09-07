#include "_array.h"
/**
 * LEETCODE M | 34
 * PreReq : Binary Search API in C++ STL
 * Given an array of integers nums sorted in ascending order, find the
 * starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 */

// Since the Array is already sorted
vector<int> searchRange(vector<int>& nums, int target) {
    std::vector<int>::iterator i,j;
    i = lower_bound(nums.begin(), nums.end(), target);
    j = upper_bound(nums.begin(), nums.end(), target);

    int first = i - nums.begin();
    int last  = j - nums.begin();

    vector<int> res;
    if(first == last){
        res.push_back(-1);
        res.push_back(-1);
    }
    else{
        res.push_back(first);
        res.push_back(last-1);
    }


    return res;

}