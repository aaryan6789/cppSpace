
#include "_array.h"
/**
 * Leetcode M | CTCI | https://leetcode.com/problems/search-in-rotated-sorted-array/
 * 33. Search in Rotated Sorted Array
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its index,
 * otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 */

int search2(vector<int>& nums, int target) {
    if(nums.empty())
        return -1;

    int left=0;
    int right=nums.size()-1;

    while(left+1<right) {
        int mid = left+(right-left)/2;
        if(nums[mid]==target)
            return mid;

        if(nums[left]<nums[mid]) {
            if(nums[left]<= target && target<=nums[mid])
                right=mid;
            else
                left=mid;
        }
        else {
            //nums[mid]<nums[right]
            if(nums[mid]<=target && target<=nums[right])
                left=mid;
            else
                right=mid;
        }
    }

    if(nums[left]==target)
        return left;

    if(nums[right]==target)
        return right;

    return -1;
}

int search(vector<int>& nums, int target) {
    if(nums.empty())
        return -1;

    if(nums.size() == 1){
        if(target == nums[0]){
            return 0;
        }
        else{
            return -1;
        }
    }


    int left = 0;
    int right = nums.size() - 1;

    while(left < right){
        int mid = (left + right)/2;

        if(nums[mid] == target){
            return mid;
        }

        if(nums[left] <= nums[mid]){
            if(nums[left] <= target && target < nums[mid]){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        else{
            if(nums[mid] < target && target <= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
    }


    if((left == right) && (nums[left] == target)){
        return left;
    }
    else{
        return -1;
    }
}
