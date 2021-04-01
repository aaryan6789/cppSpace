
"""
    Leetcode Easy | 283 | Move Zeroes
    Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of
    the non-zero elements.

    Example:
    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]
    Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
"""

#   Approach #2 (Space Optimal, Operation Sub-Optimal) [Accepted]
#   This approach works the same way as above, i.e. , first fulfills one requirement and then another.
#   The catch? It does it in a clever way.
#   The above problem can also be stated in alternate way,
#   " Bring all the non 0 elements to the front of array keeping their relative order same".
#    
#   This is a 2 pointer approach.
#   The fast pointer which is denoted by variable "cur" does the job of processing new elements.
#   If the newly found element is not a 0, we record it just after the last found non-0 element.
#   The position of last found non-0 element is denoted by the slow pointer "lastNonZeroFoundAt"
#   variable. As we keep finding new non-0 elements, we just overwrite them at the "lastNonZeroFoundAt + 1" 'th index.
#   This overwrite will not result in any loss of data because we already processed what was there(if it were non-0,
#   it already is now written at it's corresponding index,or if it were 0 it will be handled later in time).
#    
#   After the "cur" index reaches the end of array, we now know that all the non-0 elements have been moved to
#   beginning of array in their original order.
#   Now comes the time to fulfil other requirement,
#   "Move all 0's to the end".
#   We now simply need to fill all the indexes after the "lastNonZeroFoundAt" index with 0.
#    
#   Complexity Analysis
#   Space Complexity : O(1). Only constant space is used.
#   Time Complexity: O(n).
#   However, the total number of operations are still sub-optimal.
#   The total operations (array writes) that code does is nn (Total number of elements).

def moveZeroes1(nums):
    """
    :type nums: List[int]
    :rtype: None Do not return anything, modify nums in-place instead.
    """
    j = 0

    for i in range(len(nums)):
        if nums[i] != 0:
            nums[j] = nums[i]
            j += 1
        
    while j != len(nums):
        nums[j] = 0
        j += 1


#   Approach #3 (Optimal) [Accepted]
#   The total number of operations of the previous approach is sub-optimal.
#   For example, the array which has all (except last) leading zeroes: [0, 0, 0, ..., 0, 1].
#   How many write operations to the array?
#   For the previous approach, it writes 0's n-1 times, which is not necessary.
#   We could have instead written just once. How? ..... By only fixing the non-0 element,i.e., 1.
#   The optimal approach is again a subtle extension of above solution.
#    
#   A simple realization is if the current element is non-0,
#   its' correct position can at best be it's current position or a position earlier.
#   If it's the latter one, the current position will be eventually occupied by a non-0 ,or a 0,
#   which lies at a index greater than 'cur' index.
#    
#   We fill the current position by 0 right away,so that unlike the previous solution,
#   we don't need to come back here in next iteration.
#    
#   In other words, the code will maintain the following invariant:
#   All elements before the slow pointer (lastNonZeroFoundAt) are non-zeroes.
#   All elements between the current and slow pointer are zeroes.
#   Therefore, when we encounter a non-zero element, we need to swap elements pointed by current and slow pointer,
#   then advance both pointers. If it's zero element, we just advance current pointer.
#   With this invariant in-place, it's easy to see that the algorithm will work.

def moveZeroes(nums):
    """
    :type nums: List[int]
    :rtype: None Do not return anything, modify nums in-place instead.
    """
    zero = 0
    
    for i in range(len(nums)):
        if nums[i] != 0:
            nums[zero], nums[i] = nums[i], nums[zero]
            zero += 1

# Complexity Analysis
# Space Complexity : O(1). Only constant space is used.
# Time Complexity: O(n). However, the total number of operations are optimal.
# The total operations (array writes) that code does is Number of non-0 elements.
# This gives us a much better best-case (when most of the elements are 0) complexity than last solution.
# However, the worst-case (when all elements are non-0) complexity for both the algorithms is same.
