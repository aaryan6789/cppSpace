"""
PATTERN INTERVALS
LeetCode M 56 | https://leetcode.com/problems/merge-intervals/
Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

NOTE: input types have been changed on April 15, 2019. Please reset to default
code definition to get new method signature.


ALGORITHM
1. Sort the intervals based on increasing order of starting time.
2. Push the first interval on to a stack.
3. For each interval do the following
   a. If the current interval does not overlap with the stack
       top, push it.
   b. If the current interval overlaps with stack top and ending
       time of current interval is more than that of stack top,
       update stack top with the ending  time of current interval.
4. At the end stack contains the merged intervals.
"""


def merge(intervals):
    """
    :type intervals: List[List[int]]
    :rtype: List[List[int]]
    """
    
    res = []

    if len(intervals) == 0:
        return res

    # Sort the intervals based on the first item in the List
    intervals.sort(key=lambda x: x[0])

    res.append(intervals[0])

    # Loop through the List from the 1st element onwards
    for interval in intervals[1:]:
        if (res[-1][1] >= interval[0]):
            res[-1][1] = max(res[-1][1], interval[1])
        else:
            res.append(interval)

    return res
