#include "_string.h"


// C++ 0ms clean code based on expanding window
string longestPalindrome(string s) {

    // edge cases
    if(s.length() == 0 || s.length() == 1)
        return s;

    // to hold max len and its starting index
    int maxLenBeginIndex = 0;
    int maxLen = 1;

    int mid = 0;
    while(mid < s.length()){

        // calculating middle window
        int midBegin = mid;
        int midEnd = mid;

        // handling even length palindromes; the middlemost chars will trivially
        // match in even length case so expand the middle window as long as possible
        while( midEnd + 1 < s.length() && s[midEnd] == s[midEnd + 1]){
            midEnd++ ;
        }

        // for next iteration
        mid = midEnd + 1;

        // starting comparison in left and right windows

        // in case of odd len palindrome; both start from mid;
        // in case of even; midBegin and midEnd handles it all
        int leftWindow = midBegin;
        int rightWindow = midEnd;

        // expand the windows left and right simultaneously
        while(leftWindow - 1 >= 0 && rightWindow + 1 < s.length() && s[leftWindow - 1] == s[rightWindow + 1]){
                leftWindow--;
                rightWindow++;
        }

        // update maxLen is currLen > maxLen
        int currLen = rightWindow - leftWindow + 1;
        if( currLen  > maxLen ){
            maxLenBeginIndex = leftWindow;
            maxLen = currLen;
        }
    }

    return s.substr(maxLenBeginIndex, maxLen);
}


    // string longestPalindromeSubstring(string s) {
    //     if(s.length() == 0 ) return "";
 
    //     int longest = 0;
    //     int start = 0;
    //     int end = 0;
    //     vector<vector<bool>> table;
    //     table[0][0] = true;
 
    //     for (int i = 1; i < s.length(); i++) {
    //         //All single characters are palindrome in itself
    //         table[i][i] = true;
    
    //         //All two characters are palindrome if two characters are equal
    //         table[i - 1][i] = s.charAt(i - 1) == s.charAt(i);
    //         if(table[i-1][i] && longest <= 2){
    //             longest = 2;
    //             start = i-1;
    //             end = i;
    //         }
 
    //     }
 
    //     for (int L = 3; L <= s.length(); L++) {
    //         for (int i = 0; i <= s.length()-L; i++) {
    //             int j = i + L - 1;
    //             table[i][j] = table[i + 1][j - 1] 
    //                            && (s.charAt(i) == s.charAt(j));
 
    //             if(table[i][j] && longest <= L){
    //                 longest = L;
    //                 start = i;
    //                 end = j;
    //             }
    //         }
    //     }
 
    //     return s.substr(start, end+1);
 
    // }
