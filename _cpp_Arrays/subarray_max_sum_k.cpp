#include "_array.h"
//
// Efficient Approach: Hash Map
// Initialize sum = 0 and maxLen = 0.
// Create a hash table having (sum, index) tuples.
// For i = 0 to n-1, perform the following steps:
// Accumulate arr[i] to sum.
// If sum == k, update maxLen = i+1.
// Check whether sum is present in the hash table or not. If not present, then add it to the hash table as (sum, i) pair.
// Check if (sum-k) is present in the hash table or not. If present, then obtain index of (sum-k) from the hash table as index. Now check if maxLen < (i-index), then update maxLen = (i-index).
// Return maxLen.
//
// NOTE:
// There may be multiple subarrays having Sum = sum.
// However, this is a maximisation problem. So, as soon as we
// come across any instance where both sum and (sum-k) have occured,
// then we only need to consider the leftmost or the first seen instance
// of (sum-k) for the maximum length window.
//
using namespace std;
int maxSubArrayLen(vector<int>& A, int k) {
        unordered_map<int, int> map;
        int currSum = 0;
        int maxLen = 0;

        for(int i = 0; i< A.size(); i++){
            currSum += A[i];

            // insert in the map if the CurrSum is not present (keeping only the left most index)
            if(!map.count(currSum)){
                map[currSum] = i;
            }

            if(currSum == k){
                maxLen = max(maxLen, i+1);
            }

            int temp = currSum - k;
            if(map.find(temp) != map.end()){
                maxLen = max(maxLen, (i - map[temp]));
            }

            // cout << currSum << " " << i << " " << (currSum - k) <<  " " << maxLen << endl;
        }

        return maxLen;
    }