#include "_array.h"
/**
 *  LeetCode M
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color
 * red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * Example:
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 *
 * Follow up:
 * 1. A rather straight forward solution is a two-pass algorithm using counting
 * sort. First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 *
 * 2. Could you come up with a one-pass algorithm using only constant space?
 */

/// Counting Sorting
/// 1. Iterate through the array and count the number of 0s 1s and 2s.
/// 2. In the second pass just put the elements
void sortColors(vector<int>& arr, int n){
    // Variables to maintain the count of 0's, 1's and 2's in the array
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count0++;
        if (arr[i] == 1)
            count1++;
        if (arr[i] == 2)
            count2++;
    }

    // Putting the 0's in the array in starting.
    for (int i = 0; i < count0; i++)
        arr[i] = 0;

    // Putting the 1's in the array after the 0's.
    for (int i = count0; i < (count0 + count1); i++)
        arr[i] = 1;

    // Putting the 2's in the array after the 1's
    for (int i = (count0 + count1); i < n; i++)
        arr[i] = 2;

    return;
}


// ONE pass
/**
Let's use here three pointers to track the rightmost boundary of zeros,
the leftmost boundary of twos and the current
element under the consideration.

The idea of solution is to move curr pointer along the array,
if nums[curr] = 0 - swap it with nums[p0],
if nums[curr] = 2 - swap it with nums[p2].

Algorithm
1. Initialize the rightmost boundary of zeros : p0 = 0.
    During the algorithm execution nums[idx < p0] = 0.

2. Initialize the leftmost boundary of twos : p2 = n - 1.
    During the algorithm execution nums[idx > p2] = 2.

3. Initialize the index of current element to consider : curr = 0.
    While curr <= p2 :
    If nums[curr] = 0 : swap currth and p0th elements and move both pointers to the right.
    If nums[curr] = 2 : swap currth and p2th elements. Move pointer p2 to the left.
    If nums[curr] = 1 : move pointer curr to the right.
*/
void sortColors2(vector<int>& nums) {
    int p0 = 0;     // Pointing to the 1st element that is going to be 0
    int curr = 0;   // curr is an index of element under consideration
    int p2 = nums.size() - 1;   // pointing to the position of the last 2

    while(curr <= p2){
        if(nums[curr] == 0){
            swap(nums[curr], nums[p0]);
            curr++;
            p0++;
        }
        else if(nums[curr] == 2){
            swap(nums[curr], nums[p2]);
            p2--;
        }
        else{
            curr++;
        }
    }
}
