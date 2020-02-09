
#include "_array.h"
/**
 * 448. Find All Numbers Disappeared in an Array | LeetCode Easy
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
 */

/**
 * Approach 2: O(1) Space InPlace Modification Solution
Intuition
We definitely need to keep track of all the unique numbers that appear in the 
array. However, we don't want to use any extra space for it. 

This solution that we will look at in just a moment springs from the fact that:
`` All the elements are in the range [1, N] ``

Since we are given this information, we can make use of the input array itself
 to somehow mark visited numbers and then find our missing numbers. 
 
Now, we don't want to change the actual data in the array but who's stopping
us from changing the magnitude of numbers in the array? 
That is the basic idea behind this algorithm.

We will be negating the numbers seen in the array and use the sign of each
of the numbers for finding our missing numbers. 
 
We will be treating numbers in the array as indices and mark corresponding 
locations in the array as negative.

Algorithm

1. Iterate over the input array one element at a time.
2. For each element nums[i], mark the element at the corresponding location negative if it's not already marked so i.e. nums[\; nums[i] \;- 1\;] \times -1nums[nums[i]−1]×−1 .
3. Now, loop over numbers from 1 \cdots N1⋯N and for each number check if nums[j] is negative. If it is negative, that means we've seen this number somewhere in the array.
4. Add all the numbers to the resultant array which don't have their corresponding locations marked as negative in the original array.
 */

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    for(int i = 0; i< nums.size(); i++){
        int idx = abs(nums[i]) - 1;
        nums[idx] = -1 * abs(nums[idx]);
    }
    
    for(int i = 0; i< nums.size(); i++){
        if(nums[i] > 0){
            res.push_back(i+1);
        }
    }
    
    return res;
    
    
}

/**
 * Time Complexity : O(N)O(N)
Space Complexity : O(1)O(1) since we are reusing the input array itself as a hash table and the space occupied by the output array doesn't count toward the space complexity of the algorithm.
 */