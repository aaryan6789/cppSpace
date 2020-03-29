#include "_array.h"

/**
 * Sorted Rotated Array
 * Find the minimum value in a sorted rotated array
 */

// Binary Search
int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(nums[mid] > nums[right]){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return nums[right];
}