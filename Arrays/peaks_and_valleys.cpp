#include "_array.h"
#include <algorithm>


/**
 * WIGGLE SORT
 * LeetCode M | 280 | CTCI | https://leetcode.com/problems/wiggle-sort/
 * Given an unsorted array nums, reorder it in-place such that
 * nums[0] <= nums[1] >= nums[2] <= nums[3]....
 *
 * Example:
 * Input: nums = [3,5,2,1,6,4]
 * Output: One possible answer is [3,5,1,6,2,4]
 */
/** Algortithms:
 * 1. Sort the array
 * 2. Once the array is sorted that means the numbers are in a particular order. i.e increasing order.
 * 3. loop through this array starting from 1 jumping 2 values every time
 * 4. Swap the item from its previous value
 *
 * Unsorted Array --> Sorted Array
 *
 * small , medium, large, x large, xxlarge
 * medium , small, xlarge, large, xxlarge
 * peak , valley, peak, valley, peak
*/
void peaks_and_valleys(vector<int>& A){

    sort(A.begin(), A.end());

    for(int i = 1; i< A.size(); i = i+2){
        swap(A[i], A[i-1]);         // C++ Standard Library function
    }
}


void wiggleSort(vector<int>& nums) {
    vector<int> sorted(nums);       // Additional Array
    sort(sorted.begin(), sorted.end());
    int j = 0;
    for (int i=nums.size()-1, k=i/2+1; i>=0; i--)
        nums[i] = sorted[i&1 ? k++ : j++];
}