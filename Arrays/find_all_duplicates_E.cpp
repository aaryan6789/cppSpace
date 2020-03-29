#include "_array.h"

/** Leetcode E | CTCI 
 * https://leetcode.com/problems/find-the-duplicate-number/
 * Given an array nums containing n + 1 integers where each integer is between 1 and n
 * (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Example 1:
 *
 * Input: [1,3,4,2,2]
 * Output: 2
 * Example 2:
 *
 * Input: [3,1,3,4,2]
 * Output: 3
 * Note:
 *
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 */
/**
 * Using HashMap
 * O(n) And O(K) Time and Space Complexity
 */

int findDuplicateE1(vector<int>& nums) {
    int len = nums.size();
    int hash[len];

    for(int i = 0; i< nums.size() ; i++){
        hash[nums[i]] += 1;

        if(hash[nums[i]] == 2){
            return nums[i];
        }
    }

    return -1;
}

int findDuplicateE2(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i] != i + 1) {
            if (nums[nums[i] - 1] == nums[i]) 
                return nums[i];
            
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    return 0;       // Return -1
}

int findDuplicate1(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    int finder = 0;
    
    // Slow = slow->next;
    // fast = fast->next->next
    // HEre fast -> next == nums[fast]
    // and fast-> next->next = nums[nums[fast]]
    while(1){
        slow = nums[slow];
        fast = nums[nums[fast]];
        cout << "slow = " << slow << "fast = " << fast << endl;
        // Detect a cycle/ aka if a duplicate exist or not
        if(slow == fast){
            cout << "Breaking at slow = " << slow << endl;
            break;
        }
    }
    
    while(1){
        finder = nums[finder];
        slow = nums[slow];
        
        if(finder == slow){
            return finder;
        }
    }
}