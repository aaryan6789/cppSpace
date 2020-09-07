
#include <string>
#include "_string.h"
// https://leetcode.com/problems/longest-common-subsequence
int lcs_recur(string text1, string text2, int m, int n){
    // If any of the 2 strings are empty
    if(m ==0 || n == 0){
        return 0;
    }

    if(text1[m-1] == text2[n-1]){
        return 1 + lcs_recur(text1, text2, m-1, n-1);
    }
    else {
        return max(lcs_recur(text1, text2, m, n-1),
                    lcs_recur(text1, text2, m-1, n));
    }
}

// Time Limit Exceeded
int longestCommonSubsequence1(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    return lcs_recur(text1, text2, m, n);
}


// DP
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    // Make a Table of m+1 and n+1 length 2 D array
    int L[m+1][n+1];
    int i, j;

    /* Following steps build L[m+1][n+1] in bottom up fashion.
    * Note that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i=0; i<=m; i++) {
        for (j=0; j<=n; j++) {
            // Same as Base Case
            if (i == 0 || j == 0)
                L[i][j] = 0;

            // Recursive Case
            else if (text1[i-1] == text2[j-1])
                L[i][j] = L[i-1][j-1] + 1;

            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}