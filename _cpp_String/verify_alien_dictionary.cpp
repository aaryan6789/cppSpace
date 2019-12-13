#include "_string.h"

/** ALIEN DICTIONARY | LEETCODE E | 953 | https://leetcode.com/problems/verifying-an-alien-dictionary/
 * In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.



Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
 */

int dict[26] = {0};

bool compare(string& s1 , string& s2){
    int len1 = s1.size();
    int len2 = s2.size();
    cout << "Comparing " << s1 << " & " << s2 << endl; 
    
    int j;
    for (j = 0; j < s1.size() and j < s2.size(); j++) { // compare character by character.
        if (dict[s1[j] - 'a'] > dict[s2[j] - 'a']) 
            return false;                           // wrong order.
        else if (dict[s1[j] - 'a'] < dict[s2[j] - 'a'])
            break;                                  // correct order.
    }
    
    if (j == s2.size())
        return false;       // word1 is longer than word2
    
    return true;
}

bool isAlienSorted(vector<string>& words, string order) {
    if (words.size() <= 1) 
        return true; // base case.
    

    // make a Map of the Alien Order
    for(int i = 0; i< order.size(); i++){
        dict[order[i] - 'a'] = i;
    }
    
    for(auto& i : dict){
        cout << i << " ";
    }
    
    for(int i = 0; i< words.size() - 1; i++){
        if(!compare(words[i], words[i+1])){
            return false;
        }
    }
    
    return true;
}
