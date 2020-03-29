#include "_array.h"

/**
 * CTCI
 * find_peak_in_array - find the peak element in an array
 * Peak Element is that element in the array which is larger than its neighbors
 * A[] = 1 3 4 2 5
 * Peak element = 4
 */
/**
 * Solution Explanation for Binary Search:
 * https://leetcode.com/problems/find-peak-element/solution/
 */
// Modified Binary Search
int binarySearch(vector<int>& nums, int start, int end){
    // Base Case
    if(start == end){
        return start;
    }

    int mid = (start + end) / 2;

    if(nums[mid] > nums[mid+1]){
        return binarySearch(nums, start, mid);
    }
    else{
        return binarySearch(nums, mid+1, end);
    }
}

int findPeakElementR(vector<int>& nums) {
    return binarySearch(nums, 0, nums.size()-1);
}


// Iterative Binary Search
int findPeakElementI(vector<int>& nums) {
    int start = 0;
    int end = nums.size()-1;

    while(start != end) {
        int mid = start + (end-start)/2;
        if(nums[mid] > nums[mid+1]) {
            end = mid;
        }
        else {
            start = mid + 1;
        }
    }
    return start;
}

int findPeakElement(vector<int>& nums) {
    if(nums.size() == 1)
        return 0;
    int lo = 0, hi = nums.size() - 1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(mid == 0) {
            if(nums[mid] > nums[mid + 1])
                return mid;
            else
                lo = mid + 1;
        }
        else if(mid == nums.size() - 1) {
            if(nums[mid] > nums[mid - 1])
                return mid;
            else
                hi = mid - 1;
        }
        else {
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if(nums[mid] < nums[mid - 1])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
    }
    return -1;
}