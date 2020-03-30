

/**
 * Given a string s and an int k, return all unique substrings of s of size k with k distinct characters.

Example 1:

Input: s = "abcabc", k = 3
Output: ["abc", "bca", "cab"]
Example 2:

Input: s = "abacab", k = 3
Output: ["bac", "cab"]
Example 3:

Input: s = "awaglknagawunagwkwagl", k = 4
Output: ["wagl", "aglk", "glkn", "lkna", "knag", "gawu", "awun", "wuna", "unag", "nagw", "agwk", "kwag"]
Explanation: 
Substrings in order are: "wagl", "aglk", "glkn", "lkna", "knag", "gawu", "awun", "wuna", "unag", "nagw", "agwk", "kwag", "wagl" 
"wagl" is repeated twice, but is included in the output once.
Constraints:

The input string consists of only lowercase English letters [a-z]
0 ≤ k ≤ 26
 */
#include "_string.h"
int checkMap(unordered_map<char, int>& map, int k){
    int val = 0;
    for(auto kv : map){
        // cout << kv.first << " " << kv.second << endl;
        if(kv.second == 1){
            val++;
        }
    }

    if(val == k) return 1;
    else return 0;
}

unordered_set<string> kSubstring(string s, int k){
    cout << "\nFinding " << k << " distinct char Substring in " << s << endl;
    unordered_set<string> set;
    vector<string> result;
    unordered_map<char, int> map;

    for(int i = 0; i< k; i++){
        map[s[i]]++;
    }

    if(map.size() == k){
        set.insert(s.substr(0, k));
    }

    for(int i = k; i < s.length(); i++){
        // cout << "i " << i << " i-k " << i-k << endl;
        map[s[i-k]]--;      // Remove 1st char
        map[s[i]]++;       // add the new char

        if(checkMap(map, k)){
            // cout << "Insertingg " << s.substr(i-k+1, k) << endl;;
            set.insert(s.substr(i-k+1, k));
        }
    }

    cout << "Total = " << set.size() << endl;
    for(auto s : set){
        cout << s << endl;
    }

    return set;


}
