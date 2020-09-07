#include "_array.h"

/**
 * Leetcode M | 347
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */

#include <queue>
// Method 1 : the max-heap (priority_queue) based solutions
vector<int> topKFrequent1(vector<int>& nums, int k) {
    unordered_map<int,int> map;
    for(int num : nums){
        map[num]++;
    }

    vector<int> res;
    /** use the priority queue, like the max-heap , we will keep (size-k) smallest elements in the queue**/
    /** pair<first, second>: first is frequency,  second is number **/
    priority_queue<pair<int,int>> pq;
    for(auto it = map.begin(); it != map.end(); it++){
        pq.push(make_pair(it->second, it->first));
        /** once the size bigger than size-k, we will pop the value,
        which is the top k frequent element value **/

        if(pq.size() > (int)map.size() - k){
            res.push_back(pq.top().second);
            pq.pop();
        }
    }

    return res;
}

// Method 2 : C++ API : nth_element() to resort the array to left half and right half.

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    for (const auto& i : nums){
        ++ counts[i];
    }


    /** pair : (-frequency, key) **/
    vector<pair<int, int>> p;
    for (auto it = counts.begin(); it != counts.end(); ++ it){
        p.emplace_back(-(it->second), it->first);
    }

    /** nth_element() call will put the  (k-1)-th element on its position,
     * the left (k-1) element is smaller than the key, the right bigger **/
    nth_element(p.begin(), p.begin() + k - 1, p.end());
    vector<int> result;
    for (int i = 0; i < k; i++){
        result.emplace_back(p[i].second);
    }

    return result;
}

