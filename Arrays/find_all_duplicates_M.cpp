#include "_array.h"
/**
 * LeetCode M | 442. Find All Duplicates in an Array | 
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
 */

// Algorithm: Using Negation Concept
// Since the Array contains the Vlaues from 1 to n
// This means that the Array element also indicates an index in the array.
// So we can use the concept of negation
// What we do is we go through the aaray and we get the index in the array from that
// Element and we make that index element negative.
// While doing so we will also see if any index element is negative, if yes that means
// we found a duplicate number.

// To understand this it will be helpful if you run it once.


vector<int> findDuplicates(vector<int>& nums) {        
    vector<int> res;
    for(int i = 0; i < nums.size(); i ++){
        cout << "nums[" << i << "] = " << nums[i];
        int idx = abs(nums[i])-1;
        
        cout << " idx = " << idx << endl;
        
        nums[idx] = -nums[idx];
        
        if(nums[idx] > 0) 
            res.push_back(idx+1);
    }
    return res;
}

vector<int> findDuplicates2(vector<int>& nums) {        
    vector<int> res;
    for(int i = 0; i < nums.size(); i ++){
        // cout << "nums[" << i << "] = " << nums[i];
        int idx = abs(nums[i])-1;
        
        // cout << " idx = " << idx << endl;
        if(nums[idx] < 0){
            res.push_back(idx+1);
        }
        nums[idx] = -nums[idx];
    }
    return res;
}


// Using Map

vector<int> findDuplicatesMap(vector<int>& nums) {
    unordered_map<int, int> map;
    vector<int> res{};
    for(auto& item : nums){
        map[item]++;
        if(map[item] == 2){
            res.push_back(item);
        }
    }
    
    return res;
}