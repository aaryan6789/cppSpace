#include "_string.h"
/**
 * LeetCode M 
Length Of th Longest Substring with 2 Distinct Characters
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/

int lengthOfLongestSubstringTwoDistinct(string s) {
    if ( s.size() == 0)
        return 0;
    
    unordered_map<char, int> map;
    
    int start = 0;
    int end = 0;
    int counter = 0;
    int maxLen = 0;
    
    while(end < s.size()){
        char endChar = s[end];
        
        // Make a Table of Visited Chars
        map[endChar]++;
        if(map[endChar] == 1)
            counter++;
        
        end++;
        
        while(counter > 2){
            char stChar = s[start];
        
            if(map.count(stChar) == 1){
                map[stChar]--;
                if(map[stChar] == 0){
                    counter--;
                }
            }
            
            start++;
        }
        
        maxLen = max(maxLen, end - start);
    }
    
    return maxLen;
    
}