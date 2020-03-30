#include "_helper.h"
/**
LEETCODE M | 127 | https://leetcode.com/problems/word-ladder/
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 */


// This problem has a nice BFS structure. Let's illustrate this using the example in the problem statement.
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]

// Since only one letter can be changed at a time, if we start from "hit", we can only 
// change to those words which have exactly one letter different from it (in this case, "hot"). 

// Putting in graph-theoretic terms, "hot" is a neighbor of "hit". 
// The idea is simply to start from the beginWord, then visit its neighbors, 
// then the non-visited neighbors of its neighbors until we arrive at the endWord. 
// This is a typical BFS structure

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<string> todo;
    
    if(dict.find(endWord) == dict.end())
        return 0;
    
    todo.push(beginWord);
    int len = 1;
    
    while(!todo.empty()){
        int size = todo.size();
        
        for(int i = 0; i< size; i++){
            string word = todo.front(); todo.pop();
            
            if(word == endWord){
                return len;
            }
            
            dict.erase(word);
            
            for(int j = 0; j< word.size(); j++){
                char c = word[j];
                for(char k = 'a'; k< 'z'; k++){
                    word[j] = k;
                    
                    if(dict.find(word) != dict.end()){
                        todo.push(word);
                        dict.erase(word);
                    }
                }
                word[j] = c;
            }
        }
        len++;
    }
    
    return 0;
}



int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
    wordDict.erase(beginWord);
    wordDict.erase(endWord);
    unordered_set<string> nextWords;
    unordered_set<string> prevWords;
    nextWords.insert(beginWord);
    prevWords.insert(endWord);
    int ladder = 2, len = beginWord.length();
    
    while (!nextWords.empty() && !prevWords.empty()) {
        if (nextWords.size() > prevWords.size())
            swap(nextWords, prevWords);
        unordered_set<string>::iterator itr = nextWords.begin();
        unordered_set<string> temp;
        for (; itr != nextWords.end(); itr++) {
            string word = *itr;
            for (int p = 0; p < len; p++) {
                char letter = word[p];
                for (int j = 0; j < 26; j++) {
                    word[p] = 'a' + j; 
                    if (prevWords.find(word) != prevWords.end())
                        return ladder;
                    if (wordDict.find(word) != wordDict.end()) {
                        temp.insert(word);
                        wordDict.erase(word);
                    }
                }
                word[p] = letter;
            }
        }
        swap(nextWords, temp);
        ladder++; 
    }
    return 0;
}