#include "_array.h"
/**
 * Given an array of integers, find the length of the longest subarray with sum equals to 0.
 *
 * Examples :
 * Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
 * Output: 5
 * The largest subarray with 0 sum is -2, 2, -8, 1, 7
 *
 * Input: arr[] = {1, 2, 3}
 * Output: 0
 * There is no subarray with 0 sum
 *
 * Input: arr[] = {1, 0, 3}
 * Output: 1
 */


using namespace std;


// Algorithm : Using Hashing : Time Complexity = O(n) Space = O(n)
// Data Structure Used = unordered_map to keep currSum as Key and the index as the value.

// 1. Iterate thrugh the array and for each element calculate the sum of elements from 0 to ith index.
// 2. If the currSum is 0 then max_len would be 1.
// 3. If the currSum is seen in the hashmap before then that measn there is a 0 SubArray.
// 4. Max Len can be found by getting the difference of current Index and the index of the currSum seen before.

int largest_zero_subarray(vector<int>& A){
    unordered_map<int, int> hash;       // HashMap (Key= CurrSum and Value = index)

    int currSum = 0;
    int max_len = 0;

    for(int i=0; i< A.size(); i++){
        currSum += A[i];

        if(A[i] == 0 && max_len == 0){
            max_len = 1;
        }

        // Look for the currSum in the hash map
        if (hash.find(currSum) != hash.end()){
            max_len = max(max_len, i-hash[currSum]);
        }
        else{
            hash[currSum] = i;
        }
    }
    cout << "Largest Subarray with 0 sum is of length " << max_len << endl;
    return max_len;
}
