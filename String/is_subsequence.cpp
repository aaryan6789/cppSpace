#include "_string.h"
// https://leetcode.com/problems/is-subsequence/
/**
 * Given a string s and a string t, check if s is subsequence of t.
 * You may assume that there is only lower case English letters in both s and t.
 * t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
 *
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters.
 * (ie, "ace" is a subsequence of "abcde" while "aec" is not).
 *
 * Example 1:
 * s = "abc", t = "ahbgdc"
 * Return true.
 *
 * Example 2:
 * s = "axc", t = "ahbgdc"
 * Return false.
 *
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want
 * to check one by one to see if T has its subsequence.
 * In this scenario, how would you change your code?
 */

// Returns true if s is a subsequence of t.
/**
 * 1. If the s is empty string, it will always be subsequence of t
 * 2. If s is longer than t, then it can never be subsequence of t
 * 3. Iterate j through length of s and i through t
 * 4. Whenever jth element of s matches ith element of t, we increase j by 1
 * 5. In the end, we check if j reaches to length of s or not, if yes return
 *    true otherwise false
 */
bool isSubsequence(string s, string t) {
    if(s.length() == 0) return true;
    if(s.length() > t.length()) return false;
    int m = s.size();
    int n = t.size();

    int j = 0; // For index of str1 (or subsequence

    // Traverse s and t, and compare current character of t with first unmatched
    // char of s, if matched then move ahead in str1
    for (int i=0; i<n && j<m; i++)
        if (s[j] == t[i])
            j++;

    // If all characters of s were found in t
    return (j==m);      // True or False
}




/* The idea is simple, we traverse both strings from one side to other side
 * (say from rightmost character to leftmost).
 *
 * If we find a matching character, we move ahead in both strings.
 * Otherwise we move ahead only in str2.
 */
bool isSubSequenceRecursive(string s, string t, int m, int n)
{
    // Base Cases
    if (m == 0)
    	return true;
    if (n == 0)
    	return false;

    // If last characters of two strings are matching then
    // check for the rest of the characters in both strings
    if (s[m-1] == t[n-1])
        return isSubSequenceRecursive(s, t, m-1, n-1);

    // If last characters are not matching then check for the rest of the characters in the
    // bigger string
    return isSubSequenceRecursive(s, t, m, n-1);
}

bool isSubsequence2(string s, string t) {
    isSubSequenceRecursive(s, t, s.size(), t.size());
}



bool isSubsequencePointers(char* s, char* t){
    if (*s == '\0')
        return true;

    char *p = s;
    // Iterate through the string s untill t becomes null
    while(*t != '\0') {
        // If the characters are matching then keep on iterating
        while (*p != '\0' && *t != '\0' && *p == *t){
            t++;
            p++;
        }
        // If all the characters in s matches then it would be null here
        if (*p == '\0')
            return true;

        // Else move on in t
        t++;
    }

    return false;

}
