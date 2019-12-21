#include "_string.h"
#include <unordered_map>
#include <vector>

/**
 * Check Permutation aka AnaGrams
 * [CTCI 6th 1.2]
 *
 * Anagrams: Check if 2 strings are anagrams of each other or not.
 * Anagrams are words who have the same characters but in different orders.
 */


/* Method 1 -- Count the number of distinct characters in both the strings.
* 1. Create count arrays of size 256 (number of chars) for both strings.
* 		Initialize all the values in the count array to 0. <as not populated>
* 2. Iterate through every character of both strings and
* 		increment the count of character in the corresponding count arrays.
* 2. Compare the count arrays. If the values matches then yes they are anagrams.
* e.g: acre and care
*/

/* Method 2 -- Optimized from Method 1 |
* Count the number of distinct characters in both the strings.
* 1. Create only 1 count array of size 256 (number of chars) for both strings.
* 		Initialize all the values in the count array to 0. <as not populated>
* 2. We can increment the value in count array for characters in str1 and
* 		decrement for characters in str2.
* 2. If all count values are 0, then the two strings are anagram of each other.
* e.g: acre and care
*/
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> letters(26);
    for (int i = 0; i < s.size(); i++){
        letters[s[i]-'a']++;
        letters[t[i]-'a']--;
    }
    for (int i = 0; i < 26; i++){
        if (letters[i] != 0) return false;
    }

    return true;
}


bool isAnagram2(string s, string t) {
    int slen = s.size();
    int tlen = t.size();

    if(slen != tlen){
        return false;
    }

    unordered_map<char, int> map;
    for(int i = 0; i< slen; i++){
        map[s[i]]++;
        map[t[i]]--;
    }

    for(auto& item : map){
        if(item.second != 0){
            return false;
        }
    }

    return true;

}