#include "_array.h"

/**
 * CTCI | Leetcode M
 * Find if there is a subarray with 0 sum
 *
 * Given an array of positive and negative numbers, find if there is a subarray (of size at-least one) with 0 sum.
 *
 * Examples :
 * Input: {4, 2, -3, 1, 6}
 * Output: true
 * There is a subarray with zero sum from index 1 to 3.
 *
 * Input: {4, 2, 0, 1, 6}
 * Output: true
 * There is a subarray with zero sum from index 2 to 2.
 *
 * Input: {-3, 2, 3, 1, 6}
 * Output: false
 * There is no subarray with zero sum.
 */
using namespace std;
#include <unordered_set>
/**
 * Algorithm: Using Hashing (Set Data Structure from STL)
 *
 * If we consider all prefix sums, we can notice that there is a subarray with 0
 * sum when :
 * 1) Either a prefix sum repeats or
 * 2) Or prefix sum becomes 0.
 *
 * Time Complexity = O(n)
 * Space Compexity = O(n)
 */
bool checkZeroSubArray(vector<int>& A){
    unordered_set<int> sumSet {};
    int sum_till_here;

    for (int i = 0; i< A.size(); i++){
        sum_till_here = sum_till_here + A[i];

        // If the sum of the current subarray is zero.
        if( (sum_till_here == 0) ||
            (sumSet.find(sum_till_here) != sumSet.end())){
            return true;
        }

        // Insert sum in the set
        sumSet.insert(sum_till_here);
    }

    return false;
}

/** NOTE:
 * 1. Unordered Set doesnt guarantee the order in which the sum_till_here is stored.
 * 2. SumSet only is for book keeping that somewhere there is a sum that exist here.
 * 3. if the sum exist before that means its a subarray with zero sum.
 */

/// Follow UPs:
/// 1. Largest zero Subarray
/// 2. Count number of zero Subarrays
/// 3. Print all the zero subarrays

/**
 * Print all the zero Subarrays
 * Extending the above functionality with Map in which we can also store the
 * indices of the
 * preSum.
 *
 * Do following for each element in the array
 *
 * 1. Maintain sum of elements encountered so far in a variable (say sum).
 * 2. If current sum is 0, we found a subarray starting from index 0 and ending
 * at index current index i.
 *
 * 3. Check if current sum exists in the hash table or not.
 *      - If current sum already exists in the hash table then it indicates
 *       that this sum was the sum of some sub-array elements arr[0]…arr[i] and
 *       now the same sum is obtained for the current sub-array arr[0]…arr[j] which
 *       means that the sum of the sub-array arr[i+1]…arr[j] must be 0.
 *
 * 4. Insert current sum into the hash table
 */

static void printArrayI(vector<int>& A, int start, int end){
    for(int i = start; i<=end; i++){
        cout << A[i] << " " ;
    }
    cout << endl;
}

void printZeroSumSubArray(vector<int>& A){
    cout << " Zero Sum Subarrays " << endl;
    // Make a MAP { Key = preSum : Val = Indices}
    unordered_map<int, vector<int>> sumMap;
    int preSum = 0;

    for(int i = 0; i< A.size(); i++){
        preSum += A[i];

        if(preSum == 0){
            printArrayI(A, 0, i);
        }

        // If the Presum is found in the map
        if (sumMap.find(preSum) != sumMap.end()){
            // map[preSum] stores starting index of all subarrays
            vector<int> index = sumMap[preSum];
            printArrayI(A, index.back(), i);
            // index.pop_back();        // Not Needed as we can keep the elements
        }

        // Insert preSum in the map             <----- Because its value is a Vector so push_back
        sumMap[preSum].push_back(i);
    }

    for (auto& x : sumMap){
        cout << x.first << " -> " << endl;
    }
}


