"""
 * Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number,
 * also in sorted non-decreasing order.
 * https://leetcode.com/problems/squares-of-a-sorted-array/
 *
 * Example 1:
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 *
 * Example 2:
 * Input: [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 *
 * Note:
 *
 * -> 1 <= A.length <= 10000
 * -> -10000 <= A[i] <= 10000
 * -> A is sorted in non-decreasing order.
"""

# Method 2 : 2 pointer Approach
def sortedSquares(nums):
    """
    :type A: List[int]
    :rtype: List[int]
    """
    l = 0
    r = len(nums) - 1
    k = r
    
    # We have to declare the list of specific length first
    res = [0] * len(nums)
    
    while k >= 0:
        if abs(nums[l]) > abs(nums[r]):
            res[k] = nums[l] ** 2
            k -= 1
            l += 1
        elif abs(nums[l]) < abs(nums[r]):
            res[k] = nums[r] ** 2
            k -= 1
            r -= 1
        else:
            res[k] = nums[l] ** 2
            k -= 1
            l += 1
    
    return res
