#include "_string.h"
/** 767. Reorganize String | M  https://leetcode.com/problems/reorganize-string/
 * Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
 */


// Method 1 : Using Map and Interleaving String
// 1. Make a frequency map of the chars
// 2. Return false early if kv.second > Len/2 + 1
// 3. In case it is possible, arrange the most occuring character on even positions. Arrange the remaining characters on alternate remaining positions. This makes sure that no 2 same character occurs together.
string reorganizeString(string s) {
    unordered_map<char, int> map;
    int len = s.size();
    int maxFreq = -1;
    char maxChar;
    
    for(char ch : s){
        map[ch]++;
        
        if(map[ch] > maxFreq){
            maxFreq = map[ch];
            maxChar = ch;
        }
    }
    
    if(maxFreq > (len +1)/2){
        return "";
    }
    
    // Now lets make the string
    int i = 0;
    while(map[maxChar]){
        s[i] = maxChar;
        i = i+2;
        map[maxChar]--;
    }       
    
    for(auto kv : map){
        while(map[kv.first]){
            if(i>=len){
                i = 1;
            }
            
            s[i] = kv.first;
            map[kv.first]--;
            i = i+2;
        }            
    }

    return s;
}

// Method 2 : using a Heap