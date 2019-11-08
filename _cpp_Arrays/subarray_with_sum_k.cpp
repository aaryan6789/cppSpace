#include "_array.h"
#include <unordered_map>
using namespace std;

/**
 * Given an array of integers and an integer k, you need to find the total number of
 *  continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Note:
1. The length of the array is in range [1, 20,000].
2. The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 */

/** Algorthm1 - Using HashMap O(n) Time && O(n) Space
 *
 * An efficient solution is while traversing the array, store sum so far in currsum.
 * Also maintain count of different values of currsum in a map.
 * If value of currsum is equal to desired sum at any instance increment count of subarrays by 1.
 *
 * The value of currsum exceeds desired sum by currsum – sum.
 * If this value is removed from currsum then desired sum can be obtained.
 * From the map find number of subarrays previously found having sum equal to currsum - k.
 * Excluding all those subarrays from current subarray,
 * gives new subarrays having desired sum.
 * So increase count by the number of such subarrays.
 * Note that when currsum is equal to desired sum then also check number of subarrays previously
 * having sum equal to 0.
 * Excluding those subarrays from current subarray gives new subarrays having desired sum.
 * Increase count by the number of subarrays having sum 0 in that case.
 */
int subarraySum(vector<int>& A, int k) {
    if(A.empty()){
        return 0;
    }

    unordered_map<int, int> hash{(0,1)};
    int sum_till_here = 0;
    int count = 0;

    for (int i = 0; i< A.size(); i++){
        sum_till_here = sum_till_here + A[i];

        // If the sum of the current subarray is zero.
        if(sum_till_here == k){
            count++;
        }

        if (hash.find((sum_till_here - k)) != hash.end()){
            count = count + hash[sum_till_here - k];
        }

        // Insert sum in the set
        hash[sum_till_here]++;
    }

    // for(auto &item : hash){
    //     cout << item.first << " " << item.second << endl;
    // }

    return count;
}
