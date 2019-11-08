
#include "_array.h"
/**
 * Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
 * Return the length of the longest (contiguous) subarray that contains only 1s.
 *
 * Example 1:
 * Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
 * Output: 6
 * Explanation:
 * [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1.
 * The longest subarray is underlined.
 * Example 2:
 *
 * Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
 * Output: 10
 * Explanation:
 * [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1.
 * The longest subarray is underlined.
 *
 *
 * Note:
 * 1. 1 <= A.length <= 20000
 * 2. 0 <= K <= A.length
 * 3. A[i] is 0 or 1
 */

/**
 * Sliding Window + 2 Pointer
 * 1. Our window is defined as [start, i]
 * 2. We use maxLen to track the maximum window size.
 * 3. If we encounter zero, we increase the number of count.
 * 4. If the count is greater than K, we move start past the first zero in the
 *  window.
 *
 * Time Complexity = O(n)
 */
int longestOnes(vector<int>& A, int K) {
    int start = 0;
    int count = 0;
    int maxLen = 0;

    for(int i = 0; i< A.size(); i++){
        if(A[i] == 0){  // Count the number of zeros
            count++;
        }
        cout << "A[" << i << "] " << A[i] << " count = " << count << " start =" << start << " maxLen " << maxLen << endl;

        // If there are more 0's move left point for current ending point.
        while(count > K){       // Go only in if the count is more than k
            if(A[start] == 0){
                count--;
            }
            start++;
        }

        maxLen = max(maxLen, i - start + 1);
    }

    return maxLen;
}