#include "_array.h"
using namespace std;

/**
 * CTCI | Leetcode Easy 121
 * Single Number
 * Given a non-empty array of integers, every element appears twice except for one.
 * Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 *
 * Example 1:
 * Input: [2,2,1]
 * Output: 1
 *
 * Example 2:
 * Input: [4,1,2,1,2]
 * Output: 4
 */

/**
 * 1. Using Unordered Map
 * O(n) + O(k) Extra Space
 * We use hash table to avoid the O(n) time required for searching the elements.
 *
 * 1. Iterate through all elements in nums
 * 2. Try if hash_table has the key for pop
 * 3. If not, set up key/value pair
 * 4. In the end, there is only one element in hash\_tablehash_table, so use popitem to get it
 */
int singleNumber(vector<int>& nums) {
    unordered_map<int, int> hash;

    // Go through the numbers in the array and popolate the hash map
    for(auto &num : nums){
        hash[num]++;
    }

    // Check in the hash map
    for(auto item: hash){
        if(item.second == 1){
            return item.first;
        }
    }

    return -1;
}

#include <unordered_set>
/**
 * Using Set Data Structure
 */
int singleNumberSet(vector<int>& nums) {
    unordered_multiset<int> set;

    // Go through the numbers in the array and popolate the hash map
    for(auto &num : nums){
        set.insert(num);
    }

    // Check in the hash map
    for(auto& item: set){
        cout << item << endl;
        if(set.count(item) == 1){
            // return item;
        }
    }

    return -1;
}

/**
 * Using XOR :
 * O(n)
 */

int singleNumberXOR(vector<int>& A) {
    if(A.size() == 1)
        return A[0];

    int res = A[0];

    for(int i = 1; i<A.size(); i++){
        res = res^A[i];
    }

    return res;
}
