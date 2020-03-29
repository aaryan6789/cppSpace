#include "_array.h"
#include <unordered_set>
/**
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 *
 * Example 2:
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 *
 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 *
 * Follow up:
 * 1. What if the given array is already sorted? How would you optimize your algorithm?
 * 2. What if nums1's size is small compared to nums2's size? Which algorithm is better?
 * 3. What if elements of nums2 are stored on disk, and the memory is limited such
 *    that you cannot load all elements into the memory at once?
 */

// Using 1 Map
// Time: O(m + n)
// Space: O(m)
/**
 * Algorithm
1. If nums1 is larger than nums2, swap the arrays.

2. For each element in nums1:
- Add it to the hash map m.
- Increment the count if the element is already there.
4. Initialize the insertion pointer (k) with zero.

5 Iterate along nums2:
    If the current number is in the hash map and count is positive:
    Copy the number into nums1[k], and increment k.
    Decrement the count in the hash map.

6. Return first k elements of nums1.
 */
vector<int> intersect2_1(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;
    vector<int> res{};

    for(auto& item : nums1){
        map[item]++;
    }

    for(auto& item : nums2){
        if(map.find(item) != map.end()){
            if(map[item] > 0){
                res.push_back(item);
                map[item]--;
            }
        }
    }

    return res;
}

// Sort and two pointers Solution:
// Time: O(max(m, n) log(max(m, n)))
// Space: O(m + n)
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n1 = (int)nums1.size(), n2 = (int)nums2.size();
    int i1 = 0, i2 = 0;
    vector<int> res;
    while(i1 < n1 && i2 < n2){
        if(nums1[i1] == nums2[i2]) {
            res.push_back(nums1[i1]);
            i1++;
            i2++;
        }
        else if(nums1[i1] > nums2[i2]){
            i2++;
        }
        else{
            i1++;
        }
    }
    return res;
}

/**
Follow-up Questions
>> What if the given array is already sorted? How would you optimize your algorithm?
We can use either Approach 2 or Approach 3, dropping the sort of course. 
It will give us linear time and constant memory complexity.

>> What if nums1's size is small compared to nums2's size? Which algorithm is better?
Approach 1 is a good choice here as we use a hash map for the smaller array.

>> What if elements of nums2 are stored on disk, and the memory is limited such 
that you cannot load all elements into the memory at once?

If nums1 fits into the memory, we can use Approach 1 to collect counts for nums1
into a hash map. Then, we can sequentially load and process nums2.

If neither of the arrays fit into the memory, we can apply some partial processing strategies:
Split the numeric range into subranges that fits into the memory. 
Modify Approach 1 to collect counts only within a given subrange, 
and call the method multiple times (for each subrange).

Use an external sort for both arrays. Modify Approach 2 to load and 
process arrays sequentially.
 */