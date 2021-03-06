#include "_string.h"

/** https://leetcode.com/problems/reverse-words-in-a-string/
 * Reverse Words in a String | LC M | 151
 * Given an input string, reverse the string word by word.
Example 1:
Input: "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Note:
A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.

Follow up:
For C programmers, try to solve it in-place in O(1) extra space.
 */

string reverseWordsII(string s) {
    
    // Pre Processing the String 
    while (s[0] == ' ') {
        s.erase(s.begin());
    }
    // Reverse the Entire String
    reverse(s.begin(), s.end());
    
    // Process the String again
    while (s[0] == ' ') {
        s.erase(s.begin());
    }
    
    int front = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' || i == s.size() - 1) {
            // If More spaces
            while (s[i + 1] == ' ' && i + 1 < s.size()) {
                s.erase(s.begin() + i + 1);
            }
            
            // The Last Word
            if (i == s.size() - 1) {
                reverse(s.begin() + front, s.end());
            }
            else{ // All the other words
                reverse(s.begin() + front, s.begin() + i);
            }
            
            front = i + 1;
        }
    }
    return s;
}