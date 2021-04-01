#include <list>
#include <iostream>
#include <unordered_map>
using namespace std;
// Least Recently Used Cache
// Data Structure Iterator
using lru_it = list<pair<int, int>>::iterator;

class LRU {
private:
    int capacity;                   // Capacity of the LRU cache
    list<pair<int, int>> li;        // Key: Value Pair as the Node to LRU    
    unordered_map<int, lru_it> map; // A Map to keep track of the LRU node and its Key

public:
    LRU(int n){
        this->capacity = n;
    }

    // Get an item from the Cache if its present, if not then push the item to the front
    int get(int key){
        // 1. If key is not present in the Cache 
        if(map.find(key) == map.end()){
            return -1;
        }

        // 2. If the Key is present in the Cache then push it to the front
        li.splice(li.begin(), li, map[key]);

        return map[key]->second;        // Return the value
    }

    // Push items to LRU Cache
    void put(int key, int val){
        // 1. If key is present in the Cache, then update its Value
        if(get(key) != -1){
            map[key]->second = val;
            return;
        }

        // 2. If Cache is full then evict from the back and push the ney key to front
        if(capacity == map.size()){
            int dkey = li.back().first;
            li.pop_back();
            map.erase(dkey);
        }

        // Regardless push the key val pair to front
        li.push_front({key, val});
        map[key] = li.begin();
    }

    // Get an item from the Cache if its present, if not then push the item to the front
    // int get(int key){
    //     // 1. If key is not present in the Cache 
    //     if(map.find(key) == map.end()){
    //         return -1;
    //     }

    //     // 2. If the Key is present in the Cache then push it to the front
    //     li.splice(li.begin(), li, map[key]);

    //     return map[key]->second;        // Return the value
    // }
};



