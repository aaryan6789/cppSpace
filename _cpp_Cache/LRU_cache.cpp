// LRU Cache | https://leetcode.com/problems/lru-cache/
#include "cache.h"
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
// But To fetch the address of the key in the list using find() it takes O(N) time.
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

// Better Approach
// Data Structure Used = List
// Most recent key-value pair is in the fron tof the list
// A map for a Quick reference to the keys in the cache
class LRUCache2 {
public:
    int cap;                        // Capacity of the Cache
    list< pair<int,int> > li;       // Data Structure to keep cache data
    unordered_map<int, list<pair<int,int> >::iterator> mp;  // A map for quick reference
    // Iterator is useful in list splicing for moving the recently used pair to the fron of the list

    // Constructor
    LRUCache2(int capacity) {
        cap = capacity;
    }

    // Insert in the Cache
    void put(int key, int value) {
        std::cout << "Inserting " << key << " " << value << " in the cache" << endl;
        // If key is already present in the cache then update its value
        if(get(key) != -1){
            mp[key]->second = value;
            return;
        }
        // If Key is not in the cache
        // Then 1. Cache has space to insert another value
        //      2. Cache is Full and LRU Policy kicks in
        if(cap == mp.size()){
            int dkey = li.back().first;
            li.pop_back();
            mp.erase(dkey);
        }

        // 1. Cache has space to insert
        li.push_front({key, value});
        mp[key] = li.begin();       // Point to the first element in the cache
    }

    int get(int key) {
        // Cache Miss
        if(mp.find(key) == mp.end()){
            std::cout << "Key = " << key << " is not in the cache" << endl;
            return -1;
        }

        // cache-hit
        // Update Cache Record by moving accessed key to front of the list
        li.splice(li.begin(), li, mp[key]);     // mp[key] is {key, value}

        return mp[key]->second;
    }

};

/**
 * list::splice()
 * It is a built-in function in C++ STL which is used to transfer elements from
 *  one list to another.
 *
 * The splice() function can be used in three ways:
 *
 * 1. Transfer all the elements of list x into another list at some position.
 * 2. Transfer only the element pointed by i from list x into the list at some position.
 * 3. Transfers the range [first, last) from list x into another list at some position.
 *
 * Syntax:
 * list1_name.splice (iterator position, list2)
 *                 or
 * list1_name.splice (iterator position, list2, iterator i)
 *                 or
 * list1_name.splice (iterator position, list2, iterator first, iterator last)
 */

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

    LRUCache2 ca2(2);

    ca2.put(1, 1);
    ca2.put(2, 2);
    ca2.get(1);
    ca2.put(3, 3);
    ca2.get(2);




}

