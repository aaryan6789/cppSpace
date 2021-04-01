
#include "_array.h"

/*
Given n non-negative integers representing an elevation map where the width of 
each bar is 1, compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

   |
   |
   |                     |
   |         |  *  *  *  |  |  *  |
   | __|__*__|__|__*__|__|__|__|__|__|__ _
    0  1  0  2  1  0  1  3  2  1  2  1  0

Water - *

Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/


// Using 2 Pointers
int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() -1;
    
    int water = 0;
    int left_max = 0;
    int right_max = 0;
    
    while(left < right){
        if(height[left] <= height[right]){
            left_max = max(left_max, height[left]);
            water += (left_max - height[left]);
            left++;
            
        }
        else{
            right_max = max(right_max, height[right]);
            water += (right_max - height[right]);
            right--;
            
        }
    }
    return water;
}


/**
 * An element of the array can store water if there are higher bars on left and right. 
 * We can find the amount of water to be stored in every element by finding the 
 * heights of bars on left and right sides. 
 * 
 * The idea is to compute the amount of water that can be stored in every element of array. 
 * 
 * For example, 
 * consider the array {3, 0, 0, 2, 0, 4}, we can store three units of water 
 * at indexes 1 and 2, and one unit of water at index 3, and three units of water at index 4.
 */
/**
 * A Simple Solution is to traverse every array element and find the highest bars
 * on left and right sides. 
 * Take the smaller of two heights. 
 * The difference between the smaller height and height of the current element 
 * is the amount of water that can be stored in this array element. 
 * Time complexity of this solution is O(n2).
 */

/** Using 2 Arrays to compute left max and right max to that point
 * An Efficient Solution is to pre-compute highest bar on left and right of every
 *  bar in O(n) time. 
 * Then use these pre-computed values to find the amount of water in every array element.
 */

int findWater(int arr[], int n) 
{ 
    // left[i] contains height of tallest bar to the 
    // left of i'th bar including itself 
    int left[n]; 
  
    // Right [i] contains height of tallest bar to 
    // the right of ith bar including itself 
    int right[n]; 
  
    // Initialize result 
    int water = 0; 
  
    // Fill left array 
    left[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
        left[i] = max(left[i - 1], arr[i]); 
  
    // Fill right array 
    right[n - 1] = arr[n - 1]; 
    for (int i = n - 2; i >= 0; i--) 
        right[i] = max(right[i + 1], arr[i]); 
  
    // Calculate the accumulated water element by element 
    // consider the amount of water on i'th bar, the 
    // amount of water accumulated on this particular 
    // bar will be equal to min(left[i], right[i]) - arr[i] . 
    for (int i = 0; i < n; i++) 
        water += min(left[i], right[i]) - arr[i]; 
  
    return water; 
}

// Space Optimization in above solution: 
// Instead of maintaing two arrays of size n for storing left and right max of each element,
// just maintain two variables to store the maximum till that point. 
// Since water trapped at any element = min( max_left, max_right) – arr[i] 
// we will calculate water trapped on smaller element out of A[lo] and A[hi] 
// first and move the pointers till lo doesn’t cross hi.
int trap2(vector<int>& height) {
    if(height.size()<=2)
        return 0;

    // Vars to traverse the array
    int left = 0, right = height.size()-1;

    // maximum element on left and right
    int left_max = 0, right_max = 0;
    
    int tot = 0;
    while(left<right) {

        if(height[left] <= height[right]) {
            if(height[left]>left_max) {
                left_max = height[left];        // Update left max
            }
            else {
                tot += left_max - height[left];
            }
            left++;
        }
        else
        {
            if(height[right]>right_max){
                right_max = height[right];      // Update right max
            }
            else {
                tot += right_max - height[right];
            }

            right--;
        }
    }
    return tot;
}