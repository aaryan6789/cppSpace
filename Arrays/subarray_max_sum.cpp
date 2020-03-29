/** LeetCode Easy | CTCI
 *
 * Max SubArray
 * Given an integer array nums, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 *
 * Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 * Follow up:
 * If you have figured out the O(n) solution,
 * try coding another solution using the divide and conquer approach, which is more subtle.
 */
#include <algorithm>
#include "_array.h"
using namespace std;

int maxSubArray(vector<int>& A){
    int max_till_here = 0;
    int max_so_far = INT_MIN;

    for(int i=0; i<A.size(); i++){
        max_till_here += A[i];

        max_till_here = max(max_till_here, A[i]);
        max_so_far = max(max_till_here, max_so_far);
    }

    return max_so_far;
}


/* Algo:
 * 1. Look for all the +ve contiguous segments of the array.
 * Keep track of the Max Sum contiguous segment among all positive segments.
 *
 * 2. Each time we get a positive segment compare it with max so far and update max so far.
 * if its greater then max so far.
 */
int maxSubArray2(vector<int>& A){
    int max_so_far = A[0];
    int max_ending_here = A[0];
    int start = 0;
    int end = A.size();
    int s = 0;

    for(int i=1; i<A.size(); i++){
        max_ending_here = max_ending_here + A[i];

        // If Max ending here is less then 0 then, set it to 0 and increment i
        if(max_ending_here < A[i]){
            max_ending_here = max(max_ending_here, A[i]);
            s = i+1;
        }

        // If the max is changed to the new Max, then
        if(max_ending_here > max_so_far){
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
    }

    cout << "Max of the array is = " << max_so_far << " from " << start << " to " <<  end << endl;
    return max_so_far;
}