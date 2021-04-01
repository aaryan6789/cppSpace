"""
LeetCode M | 49
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
All inputs will be in lowercase.
The order of your output does not matter.
"""

# Use a map/dictionary to group the strings by their sorted counterparts.
# Use the sorted string as the key and all anagram strings as the value.
 
# Time : O(n KlogK)        n = strs.size() and K = length of individual string
# Space : O(nK) 
from collections import defaultdict

def groupAnagrams(strs):
    """
    :type strs: List[str]
    :rtype: List[List[str]]
    """
    res = []
    
    if strs is None:
        return res
    
    map = defaultdict(list)     # str : List of Anagrams
    
    # In C++, we will store the key as a string, eg. code. 
    # In Python, we will store the key as a hashable tuple, eg. ('c', 'o', 'd', 'e')
    for s in strs:
        sortStr = tuple(sorted(s))
        # print(sortStr)
        map[sortStr].append(s)
        
    for v in map.values():
        res.append(v)
        
    return res
