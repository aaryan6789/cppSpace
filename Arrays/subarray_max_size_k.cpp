/**
 * CTCI | LeetCode E | Sliding Window
 * maximum (or minimum) sum of a subarray of size k
 */
#include "_array.h"
using namespace std;

/**
 * Sliding Window Solution:
 * It is based on the fact that sum of a subarray (or window) of size k can be
 * obtained in O(1) time using sum of previous subarray (or window) of size k.
 * Except first subarray of size k, for other subarrays, we compute sum by
 * removing first element of last window and adding last element of current window.
 */
int maxSubArraySizeK(vector<int>& A, int k){
    int kSum = 0;
    int maxSum = 0;
    for(int i = 0; i< k; i++){
        kSum += A[i];
    }

    maxSum = kSum;

    // Now go through the array and keep updating the subarray sum
    for(int i = k; i< A.size(); i++){
        kSum = kSum + A[i] - A[i-k];
        maxSum = max(kSum, maxSum);
    }

    return maxSum;
}
// Time Complexity : O(n) // Auxiliary Space : O(1)