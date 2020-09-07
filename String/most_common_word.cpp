#include "_string.h"

/** 
 * MOST COMMON WORD | 819 | LEETCODE E | AMAZON OA
 * 
 * Given a paragraph and a list of banned words, return the most frequent word 
 * that is not in the list of banned words. 
 * It is guaranteed there is at least one word that isn't banned, and that the
 * answer is unique.
 * 
 * Words in the list of banned words are given in lowercase, and free of punctuation.
 * Words in the paragraph are not case sensitive. 
 * The answer is in lowercase.
 * 
 * Example:
 * Input: 
 * paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
 * banned = ["hit"]
 * Output: "ball"
 * 
 * Explanation: 
 * "hit" occurs 3 times, but it is a banned word.
 * "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
 * Note that words in the paragraph are not case sensitive,
 * that punctuation is ignored (even if adjacent to words, such as "ball,"), 
 * and that "hit" isn't the answer even though it occurs more because it is banned.
 *  
 * 
 * Note:
 * 1 <= paragraph.length <= 1000.
 * 0 <= banned.length <= 100.
 * 1 <= banned[i].length <= 10.
 * 
 * The answer is unique, and written in lowercase (even if its occurrences in 
 * paragraph may have uppercase symbols, and even if it is a proper noun.)
 * paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
 * There are no hyphens or hyphenated words.
 * Words only consist of letters, never apostrophes or other punctuation symbols.
 */
string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int> map;
    int size = paragraph.size();
    int i = 0;
    
    // cout << "======" << endl;
    while( i < size){
        string s = "";
        // make a string from the paragraph untill a space is hit
        // isalpha will give you that 
        while( i < size && isalpha(paragraph[i])){
            // cout << s << endl;
            s.push_back(tolower(paragraph[i++]));
        }

        // Keep moving until you hit next word
        while( i < size && !isalpha(paragraph[i]))
            i++;
        
        map[s]++;   // Mak ethe frequency map
    }
    
    // If its a banned word then set it to zero
    for(auto x : banned)
        map[x] = 0;
    
    string res;
    int count = 0;
    
    for( auto kv : map){
        if(kv.second > count){
            res = kv.first;
            count = kv.second;
        }
    }
    
    return res;
}