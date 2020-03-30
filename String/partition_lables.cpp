#include "_string.h"

/**
 * A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
 */

vector<int> partitionLabels(string s) {
    vector<int> last(26, 0);
    
    // First pass we record the last position for each letter. 
    
    for(int i = 0; i< s.length() ; i++){
        last[s[i] - 'a'] = i;
    }
    
    int j = 0;
    int anchor = 0;
    
    vector<int> res;
    // Second pass we keep the maximum position of the letters we have seen so far. 
    // If the pointer exceeds the maximum position, we found the part.
    for(int i = 0; i<s.length(); i++){
        j = max(j, last[s[i] - 'a']);
        
        if(i == j){
            res.push_back(i - anchor + 1);
            anchor = i+1;
        }
    }
    
    return res;
}

/**
 * Complexity Analysis

Time Complexity: O(N), where NN is the length of SS.

Space Complexity: O(N).
 */