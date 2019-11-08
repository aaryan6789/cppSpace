// LRU Cache | https://leetcode.com/problems/lru-cache/

/**
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 *            exists in the cache, otherwise return -1.
 *
 * put(key, value) - Set or insert the value if the key is not already present.
 *
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 *
 * The cache is initialized with a positive capacity.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 * Example:
 * LRUCache cache = new LRUCache( 2 // capacity  );
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 */

// Geeks For Geeks
// Data Structures Used:
// STL container list as a Double Ended Queue to store cache Keys.
// Descending Time of Reference from front to back and a set container to check
// the presence of a key.
// To fethc the address of the key in the list using find() it takes O(N) time.
// It can be optimized by storing a reference to each key in a Hash map.

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    list<int> dq;                                   // Store keys of cache
    unordered_map<int, list<int>::iterator> map;    // Store references of key in cache
    int csize;                                      // Max Capacity of cache

public:
    LRUCache(int);
    void refer(int);
    void display();
};

// Declare the Size of the cache
LRUCache::LRUCache(int n){
    csize = n;
}

void LRUCache::refer(int x){
    // Page number not present in the cache
    if(map.find(x) == map.end()){
        // 1. If Cache is Full
        if(dq.size() == csize){
            int last = dq.back();       // Delete least recently used page
            dq.pop_back();
            map.erase(last);            // Erase the page from the map
        }
    }
    else{   // Page is present in the cache
        dq.erase(map[x]);
    }

    // Put this newly referred page in the front.
    // And update the Hash Map
    dq.push_front(x);
    map[x] = dq.begin();
}

// Function to display contents of cache
void LRUCache::display(){
    // Iterate in the deque and print all the elements in it
    for (auto it = dq.begin(); it != dq.end(); it++){
        cout << (*it) << " ";
    }

    cout << endl;
}

int main(){
    LRUCache ca(4);

    ca.refer(1);
    ca.refer(2);
    ca.display();
    ca.refer(3);
    ca.refer(1);
    ca.display();
    ca.refer(4);
    ca.refer(5);
    ca.display();

}

