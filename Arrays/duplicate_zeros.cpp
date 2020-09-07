#include "_array.h"
/**
 * LeetCode Easy | 1089
 * Duplicate Zeros
 * Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting
 * the remaining elements to the right.
 *
 * Note that elements beyond the length of the original array are not written.
 * Do the above modifications to the input array in place,
 * do not return anything from your function.
 *
 * Example 1:
 * Input: [1,0,2,3,0,4,5,0]
 * Output: null
 * Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
 *
 * Example 2:
 * Input: [1,2,3]
 * Output: null
 * Explanation: After calling your function, the input array is modified to: [1,2,3]
 *
 * Note:
 *
 * 1. 1 <= arr.length <= 10000
 * 2. 0 <= arr[i] <= 9
 */

/**
 * Using Vector PushBack
 * O(k) and O(K) Space and Time Complexity
 */
void duplicateZerosSTL(vector<int>& arr) {
    vector<int> q;
    for(int i = 0; i < arr.size(); ++i) {
        if(!arr[i]) {
            q.push_back(0);
            q.push_back(0);
        } else {
            q.push_back(arr[i]);
        }

        if(q.size()==arr.size()) {
            break;
        } else if(q.size() > arr.size()) {
            q.pop_back();
            break;
        }
    }
    arr = q;
}

/**
 * Same as Urlify concept
 * Inplace and O(n) Time Complexity
 */
void duplicateZeros(vector<int>& arr) {

    int n = arr.size();
    int countZero = 0;
    for(int i=0; i<n; i++)
        countZero += (arr[i] == 0 ? 1 : 0);

    int newLen = n + countZero - 1;
    for(int i=n-1; i>=0; i--)
    {
        if(arr[i] == 0)
        {
            if(newLen < n)
                arr[newLen] = 0;
            newLen--;

            if(newLen < n)
                arr[newLen] = 0;
            newLen--;
        }
        else
        {
            if(newLen < n)
                arr[newLen] = arr[i];
            newLen--;
        }
    }
}