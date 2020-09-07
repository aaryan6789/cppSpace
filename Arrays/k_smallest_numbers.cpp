/**
 * CTCI Hard
 * 17.14 Smallest K:
 * Design an algorithm to find the smallest K numbers in an array.
 */
#include "_array.h"
#include <list>
using namespace std;

#include <queue>
#include <algorithm>

vector<int> smallestK(vector<int>& nums, int k){
    cout << "Smallest " << k << " numbers in " << endl;
    printArray(nums);

    // priority_queue<int, deque<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(auto& item : nums){
        minHeap.push(item);
    }

    vector<int> res{};

    for(int i = 0; i< k; i++){
        auto item = minHeap.top();
        res.push_back(item);
        minHeap.pop();
    }

    printArray(res);
    return res;
}