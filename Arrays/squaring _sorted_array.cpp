/**
 * Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number,
 * also in sorted non-decreasing order.
 * https://leetcode.com/problems/squares-of-a-sorted-array/
 *
 * Example 1:
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 *
 * Example 2:
 * Input: [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 *
 * Note:
 *
 * -> 1 <= A.length <= 10000
 * -> -10000 <= A[i] <= 10000
 * -> A is sorted in non-decreasing order.
 */
#include "_array.h"
using namespace std;

// Method 2 : 2 pointer Approach
vector<int> sortedSquares(vector<int>& A){
    vector<int> out(A.size(),0);

    int l = 0;
    int r = A.size()-1;
    int k = r;      // Starting from the end

    while(l <= r) {
        if(abs(A[l]) >= abs(A[r])) {
            out[k--] = A[l]*A[l];
            l++;
        } else {
            out[k--] = A[r]*A[r];
            r--;
        }
    }
    return out;

}

// Method 1: Using Squaring and Sorting
vector<int> sortedSquares2(vector<int>& A) {

    for(int i = 0; i< A.size() ; i++){
        A[i] = A[i] * A[i];
    }

    sort(A.begin(), A.end());

    return A;
}