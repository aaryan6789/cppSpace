#include "_string.h"
/* FIND ALL ANAGRAMS | LEETCODE M | https://leetcode.com/problems/find-all-anagrams-in-a-string/
   SLIDING WINDOW CONCEPT

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

Example 1:
Input: s: "cbaebabacd" p: "abc"
Output: [0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

// Same as MIN WINDOW SUBSTRING SLIDING WINDOW CONCEPT
vector<int> findAnagrams(string s, string p) {
    vector<int> res = {};
    if(s.size() < p.size() || p.size() == 0) 
        return res;
    
    unordered_map<char, int> map;
    for(char ch : p){               // Make the Frequency Map of the anagram string
        map[ch]++;
    }

    int start = 0;
    int end = 0;
    int counter = map.size();
    int word_size = p.size();

    // Sliding the Window now
    while(end < s.size()){
        char endChar = s[end];
        // if(map.find(endChar) != map.end()){
        //     map[endChar]--;
        //     if(map[endChar] == 0)
        //         counter--;
        // }
        
        map[endChar]--;
        if(map[endChar] == 0)
            counter--;

        end++;
        
        while(counter == 0){
            if(end - start == word_size){
                res.push_back(start);
            }
            
            char stChar = s[start];
            if(map.count(stChar) == 1){
                map[stChar]++;
                if(map[stChar] > 0)
                    counter++;
            }
            
            start++;    // Contracting the Window
        }
    }

    return res;
}