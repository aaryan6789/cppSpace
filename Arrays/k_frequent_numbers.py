"""
Leetcode M | 347

Given a non-empty array of integers, return the k most frequent elements.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
"""

from collections import defaultdict, Counter
import heapq

# Method 1 : using min-heap (priority_queue) based solutions


def topKFrequent(nums, k):
    """
    :type nums: List[int]
    :type k: int
    :rtype: List[int]
    """
    map = defaultdict(int)
    res = []

    if len(nums) == 0:
        return res

    for i in nums:
        map[i] += 1

    maxHeap = []        # (freq, num)
    for key in map:
        heapq.heappush(maxHeap, [-map[key], key])

    for i in range(k):
        freq, item = heapq.heappop(maxHeap)
        # print(k, i, item)
        res.append(item)
        # i += 1
        
    return res


def topKFrequent2(nums, k):
    """
    :type nums: List[int]
    :type k: int
    :rtype: List[int]
    """
    res = []

    if len(nums) == 0:
        return res

    freqMap = Counter(nums)

    maxHeap = []        # (freq, num)
    for key in freqMap:
        heapq.heappush(maxHeap, [-freqMap[key], key])

    for i in range(k):
        freq, item = heapq.heappop(maxHeap)
        # print(k, i, item)
        res.append(item)
        # i += 1
        
    return res
