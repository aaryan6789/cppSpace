#include "_array.h"
#include <unordered_set>
/**
 * LeetCode E | https://leetcode.com/problems/intersection-of-two-arrays/
 * Given two arrays, write a function to compute their intersection.
 * Example 1:
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 * Example 2:
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 *
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 */

// Using 1 Set
vector<int> intersection2(vector<int>& nums1, vector<int>& nums2){
    unordered_set<int> set1 (nums1.begin(), nums1.end());
    vector<int> res{};

    for(auto item : nums2){
        if(set1.find(item) != set1.end()){
            res.push_back(item);
            set1.erase(item);
        }
    }

    return res;
}

// Using 2 Sets
vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1 {nums1.begin(), nums1.end()};
    unordered_set<int> set2 (nums2.begin(), nums2.end());
    vector<int> res{};

    for(auto item : set1){
        if(set2.find(item) != set2.end()){
            res.push_back(item);
        }
    }

    return res;
}


// Using 2 Sets
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1;
    unordered_set<int> set2;
    vector<int> res{};
    for(const auto& item : nums1){
        set1.insert(item);
    }

    for(const auto& item : nums2){
        set2.insert(item);
    }

    for(auto item : set1){
        if(set2.find(item) != set2.end()){
            res.push_back(item);
        }
    }

    return res;
}