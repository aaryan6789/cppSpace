#include "_array.h"
// https://leetcode.com/problems/find-median-from-data-stream/solution/
class MedianFinder {
public:
    priority_queue<int> low;      // Max Heap
    priority_queue<int, vector<int>, greater<int>> high;  // MinHeap
    
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    // Low Heap stores one more element than high heap
    // i.e  low --> n+1 elements
    //      high --> n elements
    void addNum(int num) {
        low.push(num);
        
        // Balance the Heaps
        high.push(low.top());
        low.pop();
        
        // Number of elements property
        if(low.size() < high.size()){
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        if(low.size() > high.size()){
            return low.top();
        }
        else{
            return (low.top() + high.top())*0.5;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


class MedianFinderSort {
public:
    vector<int> store;
    
    /** initialize your data structure here. */
    MedianFinderSort() {
        store.clear();
    }
    
    
    void addNum(int num) {
        if(store.empty()){
            store.push_back(num);
        }
        else{
            store.insert(lower_bound(store.begin(), store.end(), num), num);
        }
        
    }
    
    double findMedian() {
        int n = store.size();
        
        // If odd numbers then return the middle value
        if(n%2 != 0){
            return store[n/2];
        }
        else{   // else return averag of middle 2
            return (store[n/2 - 1] + store[n/2])*0.5;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */