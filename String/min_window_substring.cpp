#include "_string.h"
/** MIN WINDOW SUBSTRING | LEETCODE H | 76
 * Concept : SLIDING WINDOW, STRING, MAP
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 */

// SLIDING WINDOW CONCEPT
// Time Complexity = O(n)
// constant Space complexity
string minWindowMap(string s, string t) {
    unordered_map<char, int> map;
    for(char ch: t){
        map[ch]++;
    }
    
    int start = 0;
    int end = 0;
    int counter = map.size();
    int minLen = INT8_MAX;
    string res = "";
    
    while(end < s.size()){
        
        // cout << "start " << start << " end " << end << " minLen " << minLen <<  endl;
        
        char endChar = s[end];
        
        if(map.find(endChar) != map.end()){
            map[endChar]--;
            if(map[endChar] == 0)
                counter--;
        }
        
        end++;
        // start char could be in table or not, 
        // if not then good for us, as it was a wasteful char 
        // and we shortened the previously found substring.

        // if found in table increment count in table, as we 
        // are leaving it out of window and moving ahead, 
        // so it would no longer be a part of the substring marked by 
        // begin-end window
        // table only has count of chars required to make the present substring a valid candidate
        // if the count goes above zero means that the current window 
        // is missing one char to be an answer candidate
        while(counter == 0){
            if(end- start < minLen){
                minLen = end-start;
                res = s.substr(start, minLen);
            }
            char stChar = s[start];
            
            // Count elements with a specific key
            // Searches the container for elements whose key is k and returns 
            // the number of elements found. Because unordered_map containers do
            // not allow for duplicate keys, this means that the function actually
            // returns 1 if an element with that key exists in the container, and zero otherwise.
            if(map.count(stChar) == 1){
                map[stChar]++;
                if(map[stChar] > 0)
                    counter++;
                
            }
            
            start++;
        }
    }
    
    return res;
}