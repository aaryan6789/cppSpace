/**
 * LeetCode M | Sliding Window | Rivian
 * Find k closest elements to a given value

Given a sorted array arr[] and a value X, find the k closest elements to X in arr[].
Examples:
Input: K = 4, X = 35
       arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56}
Output: 30 39 42 45
 */
#include "_array.h"
#include <algorithm>
using namespace std;
// Algorithm 1 = Binary Search and Find the values

vector<int> kClosestElementToVal(vector<int>& A, int val){
    // Since the array is already sorted to find the value first
    // const auto& mid = binary_search(A.begin(), A.end(), val);

    printArray(A);
    const auto mid = std::lower_bound(A.begin(), A.end(), val);

    cout << *mid << endl;

    vector<int> result{};
    return result;
}