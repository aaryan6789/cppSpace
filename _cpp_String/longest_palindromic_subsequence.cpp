#include "_string.h"

    int longestPalindromeSubseq(string s) {
        return longestPalindromeSubseq(0,s.size()-1,s);
    }
    int longestPalindromeSubseq(int l, int r, string &s) {
        if(l==r) return 1;
        if(l>r) return 0;  //happens after "aa"
        return s[l]==s[r] ? 2 + longestPalindromeSubseq(l+1,r-1, s) :
            max(longestPalindromeSubseq(l+1,r, s),longestPalindromeSubseq(l,r-1, s));
    }


    int longestPalindromeSubseqDP(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n));

        for(int i=0;i<n;i++)
            dp[1][i]=1;

        for(int i=2;i<=n;i++) //length
            for(int j=0;j<n-i+1;j++) {//start index
                dp[i][j] = s[j]==s[i+j-1]?2+dp[i-2][j+1]:max(dp[i-1][j],dp[i-1][j+1]);
            }

        return dp[n][0];
    }