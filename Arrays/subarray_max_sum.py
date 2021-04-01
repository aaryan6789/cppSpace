"""
LeetCode Easy | CTCI

    Max SubArray
    Given an integer array nums, find the contiguous subarray (containing at least one number)
    which has the largest sum and return its sum.

    Example:
    Input: [-2,1,-3,4,-1,2,1,-5,4],
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.

    Follow up:
    If you have figured out the O(n) solution,
    try coding another solution using the divide and conquer approach, which is more subtle.
"""

def maxSubArray1(nums):
    """
    :type nums: List[]
    :rtype:     
    """
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]
    
    max_till_here = 0
    max_so_far = float('-inf')

    for i in range(len(nums)):
        max_till_here += nums[i]

        max_till_here = max(max_till_here, nums[i])
        max_so_far = max(max_till_here, max_so_far)
    
    return max_so_far


# /* Algo:
#      1. Look for all the +ve contiguous segments of the array.
#      Keep track of the Max Sum contiguous segment among all positive segments.
#     
#      2. Each time we get a positive segment compare it with max so far and update max so far.
#      if its greater then max so far.
#     /
def maxSubArray(A):
    max_so_far = A[0]
    max_ending_here = A[0]
    start = 0
    end = len(A)
    s = 0

    for i in range(1, len(A), 1):
        max_ending_here = max_ending_here + A[i]

        # // If Max ending here is less then 0 then, set it to 0 and increment i
        if max_ending_here < A[i]:
            max_ending_here = max(max_ending_here, A[i])
            s = i+1

        # // If the max is changed to the new Max, then
        # if(max_ending_here > max_so_far):
        #     max_so_far = max_ending_here    
        #     start = s    
        #     end = i

        max_so_far = max(max_so_far, max_ending_here)

    return max_so_far
