#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
	LRUCache(const int& c): capacity(c) {}

	int get(const int& key) {
		int result(-1);
		if (this->CacheHashMap.count(key)) {
			result = this->CacheHashMap[key]->value;
			this->CacheList.splice(this->CacheList.begin(), this->CacheList, this->CacheHashMap[key]);
			this->CacheHashMap[key] = this->CacheList.begin();
		}
		return result;
	}

	void set(const int& key, const int& value) {
		if (this->CacheHashMap.count(key)) {
			this->CacheHashMap[key]->value = value;
			this->CacheList.splice(this->CacheList.begin(), this->CacheList, this->CacheHashMap[key]);
			this->CacheHashMap[key] = this->CacheList.begin();
		}
		else {
			if (this->CacheList.size() >= this->capacity) {
				this->CacheHashMap.erase(this->CacheList.back().key);
				this->CacheList.pop_back();
			}
			this->CacheList.push_front(CacheNode(key, value));
			this->CacheHashMap[key] = this->CacheList.begin();
		}
	}
private:
    // Data Structure to represent a Node in the Cache using Double Linked List
	struct CacheNode {
		int key;
		int value;
		CacheNode(const int& k, const int& v): key(k), value(v) {}
	};
	list<CacheNode> CacheList;
	unordered_map<int, list<CacheNode>::iterator> CacheHashMap;
	int capacity;
};

// Better then above

class LRUCache1 {
private:
    size_t capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> index;
public:
    LRUCache1(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (index.find(key) == index.end())
            return -1;

        list<pair<int, int>>::iterator itr = index[key];
        pair<int, int> p = *itr;

        cache.erase(itr);
        cache.push_front(p);
        index[key] = cache.begin();

        return p.second;
    }

    void put(int key, int value) {
        cache.push_front(make_pair(key, value));

        if (index.find(key) == index.end()) {
            if (cache.size() > capacity) {
                pair<int, int> p = cache.back();
                index.erase(p.first);
                cache.pop_back();
            }
        }
        else {
            cache.erase(index[key]);
        }

        index[key] = cache.begin();
    }
};

#include "cache.h"
// Better

