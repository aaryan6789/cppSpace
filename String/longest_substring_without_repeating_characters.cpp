/**
 * LeetCode M | 3 | CTCI
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 * Example 1:
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 * Example 2:
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 * Example 3:
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 *
 * Note that the answer must be a substring,
 * "pwke" is a subsequence and not a substring.
 */
#include "_string.h"
#include <unordered_set>
#include <string>

int lengthOfLongestSubstring(string s){
    unordered_set<char> set;

    int i = 0, j = 0, n = s.size(), ans = 0;

    while( i<n && j<n){
        if(set.find(s[j]) == set.end()) { //If the character does not in the set{
            set.insert(s[j++]); //Insert the character in set and update the j counter
            ans = max(ans, j-i); //Check if the new distance is longer than the current answer
        }
        else{
            set.erase(s[i++]);
            /*If character does exist in the set, ie. it is a repeated character,
            we update the left side counter i, and continue with the checking for substring. */
        }
    }

    return ans;
}


int lengthOfLongestSubstring2(string s){
    int maxlen = 0;
    int start = 0;
    vector<int> last(256, -1);      // Last index of the character  -1 init val
    last[s[0]] = 0;                 // 1st element

    for (int i = 1; i < s.length(); i++) {

        if (last[s[i]] > start) {
            start = last[s[i]];
        }

        last[s[i]] = i;

        maxlen = max(maxlen, i - start);
    }

    cout << "Length of the Longest unique string in " << s << " is " << maxlen << endl;
    return maxlen;
}

#include <map>
int lengthOfLongestSubstring3(string s) {
    map<char, int> charMap;
    int start = -1;
    int maxLen = 0;

    for (int i = 0; i < s.size(); i++) {
        if (charMap.count(s[i]) != 0) {
            start = max(start, charMap[s[i]]);
        }
        charMap[s[i]] = i;
        maxLen = max(maxLen, i-start);
    }

    return maxLen;
}