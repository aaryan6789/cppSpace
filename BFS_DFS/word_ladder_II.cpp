#include "_helper.h"
/** 126 | Word Ladder II | LC Hard

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 */

/*
    The idea is to run a BFS from beginWord to endWord, while keeping track of the path.
    Once the currWord == endWord, we have found the shortest path.
    The nextLevel keeps track of all the words reachable from currLevel.
    All words in nextLevel should be erased from dict to avoid loops.( This is slight modification to the usual BFS ).

*/
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    dict.erase( beginWord );
    queue<vector<string>> q;
    vector<vector<string>> result = {};
    q.push({beginWord});
    
    if(dict.find(endWord) == dict.end()){
        return result;
    }
    
    bool found = false;
    
    while( !q.empty() ) {
        int size = q.size();
        unordered_set<string> nextLevel;

        for( int i = 0 ; i < size ; ++i ) {
            vector< string > currLevel = q.front();
            q.pop();
            string currWord = currLevel.back();
            if( currWord == endWord ) {
                found = true;
                result.push_back( currLevel );
            } 
            else {
                for( int i = 0 ; i < currWord.size() ; ++i ) {
                    char orig = currWord[ i ];
                    for( char ch = 'a' ; ch <= 'z' ; ++ch ) {
                        if( ch == orig ) continue;
                        currWord[ i ] = ch;
                        if( dict.find( currWord ) != dict.end() ) {
                            nextLevel.insert( currWord );
                            q.push( currLevel );
                            q.back().push_back( currWord );
                        }
                    }
                    currWord[ i ] = orig;
                }
            }
        }
        if(found) 
            break;
        
        for( auto n : nextLevel ) {
            dict.erase(n);
        }
    }
    return result;
}

/**
 * [Analysis]
The problem is about to find all possible paths between two nodes in a graph. To get the paths, it is normal to use DFS (Depth First Search). The drawback to apply DFS is, unlike tree, there exist many circles in a graph. Most depth first routes will not reach the target and will be extremely time-consuming.

Meanwhile, BFS (Breadth First Search) will help to reach the target quickly (i.e. find the shortest path from start to end), like what we have seen in Word Ladder question. However, BFS visits nodes layer by layer and does not maintain the paths of nodes from start to end.

The idea is to combine the benefits of BFS and DFS together:
Apply BFS to reach target starting from "start" layer by layer. So that we can know by the number of steps in the shortest path from start to end. Any nodes outside the visited nodes during this procedure need no further consideration.
During the above BFS procedure, we construct a (directional) sub-graph where each node A in layer i+1 points to the connected nodes (where A comes from) in layer i. If A is the target ("end"), we know back-trace to the start using the path in this sub-graph. Any nodes outside this sub-graph are irrelevant to the shortest path from "start" to "end". 
Apply DFS starting from "end" using the sub-graph above. All shortest paths will be generated.
It is interesting to consider the data structure to use for the algorithm. For the BFS, queue is not a fit in this case because all connections between layer i and layer i+1 need to be collected. Queue-based BFS like in Word Ladder question actually will lose those information. It is recommended to use set in this case.
 */

/**
 * The idea is to first use BFS to search from beginWord to endWord and generate the word-to-children mapping at the same time. Then, use DFS (backtracking) to generate the transformation sequences according to the mapping.
 */
// Finds endWord by BFS and create parent->children word relations
bool findEndWordByBFS(const string& beginWord, 
                        const string& endWord,
                        const vector<string>& wordList,
                        unordered_map<string, vector<string>>& children) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    unordered_set<string> current;
    unordered_set<string> next;
    current.insert(beginWord);
    
    while (true) {
        for (string word : current) {
            dict.erase(word);
        }
        
        for (string word : current) {
            string parent = word;
            for (int i = 0; i < word.size(); i++) {
                char t = word[i];
                for (int j = 0; j < 26; j++) {
                    word[i] = 'a' + j;
                    if (dict.find(word) != dict.end()) {
                        next.insert(word);
                        children[parent].push_back(word);
                    }
                }
                word[i] = t;
            }
        }
        
        if (next.empty())
            return false;
        
        if (next.find(endWord) != next.end())
            return true;
        
        current.clear();
        swap(current, next);
    } 
    
    return false;
}

//  Use DFS (backtracking) to generate the transformation sequences according to the mapping
void buildLadders(const string& beginWord,
                    const string& endWord,
                    vector<string>& ladder,
                    vector<vector<string>>& ladders,
                    unordered_map<string, vector<string>>& children) {
    if (beginWord == endWord) {
        ladders.push_back(ladder);
    } 
    else {
        for (string word : children[beginWord]) {
            ladder.push_back(word);
            buildLadders(word, endWord, ladder, ladders, children);
            ladder.pop_back();
        }
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end())
        return {};
    unordered_map<string, vector<string>> children;
    if (!findEndWordByBFS(beginWord, endWord, wordList, children))
        return {};
    vector<vector<string>> ladders;
    vector<string> ladder;
    ladder.push_back(beginWord);
    buildLadders(beginWord, endWord, ladder, ladders, children);
    return ladders;
}

/**
 * After reading some solutions, I wrote the following one, which was mainly inspired by this one. 
 * The difference is that the previous solution maps children to parents while 
 * I map from parents to children (this makes the DFS more natural). 
 * The idea is to first use BFS to search from beginWord to endWord and generate
 *  the word-to-children mapping at the same time. 
 * Then, use DFS (backtracking) to generate the transformation sequences according to the mapping.
 */
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    unordered_set<string> current;
    unordered_set<string> next;
    if (dict.find(endWord) == dict.end()) {
        return {};
    }

    unordered_map<string, vector<string>> children;
    vector<vector<string>> ladders;
    vector<string> ladder;
    
    current.insert(beginWord);
    ladder.push_back(beginWord);
    
    while (true) {
        // Erase the Word from the Dictionary first
        for (string word : current) {
            dict.erase(word);
        }
        // Find the words 1 alphabet away from the current word
        for (string word : current) {
            findChildren(word, next, dict, children);
        }

        // If no next level then come out of the loop
        if (next.empty()) {
            break;
        }

        // If the end word is found in the next level then generate the ladders
        if (next.find(endWord) != next.end()) {
            genLadders(beginWord, endWord, children, ladder, ladders);
            break;
        }

        // Clear the Current 
        current.clear();

        // Now next becomes our current level
        swap(current, next);
    }

    return ladders;
}

// Generae 
void findChildren(string word, unordered_set<string>& next, unordered_set<string>& dict, 
                  unordered_map<string, vector<string>>& children) {

    string parent = word;
    for (int i = 0; i < word.size(); i++) {
        char t = word[i];
        for (int j = 0; j < 26; j++) {
            word[i] = 'a' + j;
            if (dict.find(word) != dict.end()) {
                next.insert(word);
                children[parent].push_back(word);
            }
        }
        word[i] = t;
    }
}

// DFS Step to backtrack and generate the ladder
// Generate the Ladders from the Map
void genLadders(string beginWord, string endWord, unordered_map<string, vector<string>>& children, vector<string>& ladder, vector<vector<string>>& ladders) {
    if (beginWord == endWord) {
        ladders.push_back(ladder);
    } 
    else {
        for (string child : children[beginWord]) {
            ladder.push_back(child);
            genLadders(child, endWord, children, ladder, ladders);
            ladder.pop_back();
        }
    }
}