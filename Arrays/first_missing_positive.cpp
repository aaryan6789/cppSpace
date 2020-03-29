#include "_array.h"
/**
 * LeetCode Hard | 41 | Frst missing positive
 * Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/
/**
Algorithm:
Put each number in its right place.
For example:
When we find 5, then swap it with A[4].
At last, the first place where its number is not right, return the place + 1. 
*/
int firstMissingPositive(int A[], int n) {
    for(int i = 0; i < n; ++ i)
        while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
            swap(A[i], A[A[i] - 1]);
    
    for(int i = 0; i < n; ++ i)
        if(A[i] != i + 1)
            return i + 1;
    
    return n + 1;
}