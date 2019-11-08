
#include "_string.h"
#include <map>

int lengthOfLongestSubstring(string s) {
    map<char, int> charMap;         // Like we had Visited Array in C
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