#include "_string.h"
/**
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.
*/

int lengthOfLongestSubstringKDistinct(string s, int k) {
    if ( s.size() == 0 ||k==0)
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
        
        while(counter > k){
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