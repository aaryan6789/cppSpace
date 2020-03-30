#include "_string.h"

/** LeetCode M | 49
 * Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
All inputs will be in lowercase.
The order of your output does not matter.
 */

#include <unordered_map>
/**
 * Use an unordered_map to group the strings by their sorted counterparts.
 * Use the sorted string as the key and all anagram strings as the value.
 * 
 * Time : O(n KlogK)        n = strs.size() and K = length of individual string
 * Space : O(nK) 
 */
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result{};
    
    if(strs.size() == 0){
        return result;
    }
    
    if(strs.size() == 1){
        result.push_back(strs);
        return result;
    }
    
    unordered_map<string, vector<string>> map;
    
    for(string& s : strs){
        string temp = s;
        sort(temp.begin(), temp.end());
        
        map[temp].push_back(s);
    }
    
    for(auto& it : map){
        result.push_back(it.second);
    } 
    
    return result;
}