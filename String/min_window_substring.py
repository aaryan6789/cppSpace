"""
MIN WINDOW SUBSTRING | LEETCODE H | 76
Concept : SLIDING WINDOW, STRING, MAP
Given a string S and a string T, 
find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
"""
from collections import defaultdict
# // SLIDING WINDOW CONCEPT
# // Time Complexity = O(n)
# // constant Space complexity


def minWindow(s, t):
    """
    :type s: str
    :type t: str
    :rtype: str
    """
    if len(s) == 0 or len(t) == 0 or len(t) > len(s):
        return ""

    # Make a Frequency Table
    map = defaultdict(int)
    
    for ch in t:
        map[ch] += 1
        
    # Initialize Sliding Window
    start = 0
    end = 0
    
    counter = len(map)
    minLen = float("inf")
    res = ""
    
    # Start the Sliding window : Expand
    while end < len(s):
        endChar = s[end]
        
        if endChar in map:
            map[endChar] -= 1
            if map[endChar] == 0:
                counter -= 1
        
        end += 1
        # print("end" , end, map)
        
        while counter == 0:
            if end - start < minLen:
                minLen = end-start
                res = s[start : start+minLen]

            stChar = s[start]

            if stChar in map:
                map[stChar] +=1
                if map[stChar] > 0:
                    counter += 1

            start += 1

    return res
