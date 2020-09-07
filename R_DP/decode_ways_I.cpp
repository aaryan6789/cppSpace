#include "_r_dp.h"

/** Decode Ways | Leetcode M 
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 */


// DP method:
// Similar to fibonacci number 

int numDecodings(string s){
    int n = s.size();
    if(s[0] == '0' || n == 0){
        return 0;
    }
    
    int dp[n+1];    // A table to store results of subproblems 
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i<= n; i++){
        dp[i] = 0;

        // If the last digit is not 0,  
        // then last digit must add to the number of words
        if(s[i-1] > '0'){
            dp[i] += dp[i-1];
        }
        
        // If second last digit is smaller
        // than 2 and last digit is smaller than 7, 
        // then last two digits form a valid character
        if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7')){
            dp[i] += dp[i-2];
        }
    }
    
    return dp[n];
    
}



int DFS(string s, int n){
    // If Empty Strnig or 1 Char string
    if(n == 0 || n == 1){
        return 1;
    }
    
    int count = 0;
    if(s[n-1] > '0'){
        count += DFS(s, n-1);
    }
    
    if(s[n-2] == '1' || s[n-2] == '2' && s[n-1] < '7'){
        count += DFS(s, n-2);
    }
    
    return count;
}



int numDecodingsR(string s) {
    if(s.size() == 0){
        return 0;
    }
    
    if(s[0] == '0'){
        return 0;
    }
    
    int n = s.size();
    return DFS(s, n);
}