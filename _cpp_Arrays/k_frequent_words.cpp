#include "_array.h"
#include <queue>

// Do this after the k frquent Numbers as this requires a special priority Queue

/** LeetCode M | K FreQuent Words
 * Given a non-empty list of words, return the k most frequent elements.
 * 
 * Your answer should be sorted by frequency from highest to lowest. 
 * If two words have the same frequency, then the word with the lower
 * alphabetical order comes first.
 * 
 * Example 1:
 * Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Output: ["i", "love"]
 * Explanation: "i" and "love" are the two most frequent words.
 *     Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * Example 2:
 * Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
 * Output: ["the", "is", "sunny", "day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
 *     with the number of occurrence being 4, 3, 2 and 1 respectively.
 * 
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Input words contain only lowercase letters.
 * 
 * Follow up:
 * Try to solve it in O(n log k) time and O(n) extra space. 
 */    


// DeclType
struct comp{
    bool operator() (pair<int, string>& p1, pair<int, string>& p2){
        if(p1.first == p2.first){
            return (p1.second > p2.second);
        }
        else {
            return (p1.first < p2.first);
        }
    }
};


vector<string> topKFrequent(vector<string>& words, int k) {
    // 1. Count the Frequency of each word in the vector 
    unordered_map<string, int> map;
    for(int i = 0; i< words.size(); i++){
        map[words[i]]++;
    }
    
    vector<string> result;
    
    // 2. Heap for storing all the top K words
    // priority_queue<pair<int, string>> maxHeap;      // This wont keep the order
    
    priority_queue<pair<int, string>, vector<pair<int, string>>, comp> maxHeap;

    for(auto it = map.begin() ; it != map.end() ; it++){
        maxHeap.push({it->second, it->first});
    }
    
    int i = 0;
    while(i < k){
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
        i++;
    }
    
    
    return result;
}

// Time Complexity = O(Nlogk), where N is the length of words. 
// We count the frequency of each word in O(N) time, then we 
// add N words to the heap, each in O(logk) time. 
// 
// Finally, we pop from the heap up to k times. 
// As k≤N, this is O(Nlogk) in total.
