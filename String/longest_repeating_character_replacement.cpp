/**
 * Longest Repeating Character Replacement
 * Given a string s that consists of only uppercase English letters,
 * you can perform at most k operations on that string.
 *
 * In one operation, you can choose any character of the string and
 * change it to any other uppercase English character.
 *
 * Find the length of the longest sub-string containing all repeating
 * letters you can get after performing the above operations.
 *
 * Note:
 * Both the string's length and k will not exceed 104.
 *
 * Example 1:
 * Input: s = "ABAB", k = 2   --- Output: 4
 * Explanation: Replace the two 'A's with two 'B's or vice versa.
 *
 * Example 2:
 * Input: s = "AABABBA", k = 1 --- Output: 4
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 */
#include <string>
using namespace std;

// Sliding window and same as atmost k unique chars
int characterReplacement(string s, int k) {
    int map[128];
    int res = 0;
    for (char& ch : s)          // Make a Frequency Map
        map[ch]++;

    for (int i = (int)'A'; i <= (int)'Z'; i++) {
        if (map[i] == 0)
            continue;

        int start = 0;
        int end = 0;
        int count = 0;
        
        while (end < s.length()) {
            if (s[end++] != i)
                count++;
            
            while (count > k) {
                if (s[start++] != i) {
                    count--;
                }
            }
            
            res = max(res, end - start);
        }
    }
    return res;
}