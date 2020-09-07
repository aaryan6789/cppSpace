
#include "_string.h"
/**
 * Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of A.

 

Example 1:

Input: A = [1,2,1,2,3], K = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:

Input: A = [1,2,1,3,4], K = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Note:

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length
 */

int subarraysWithKDistinct(vector<int>& A, int k) {
    int n = A.size();
    int ans = 0;
    
    vector<int> hash(n+1, 0);
    int left = 0;
    int right = 0; 
    int uniqueCnt = 0;
    int duplicates = 0;;
    
    // for(right = 0; right<n; right++){
    while(right < n){
        // if its the 1st time then increment the unique count
        if(hash[A[right]] == 0){
            hash[A[right]] = 1;
            uniqueCnt++;
        }
        else{
            // Keep Track of the duplicates 
            hash[A[right]]++;    
        }
        
        // If unique numbers more than k, then Contract Sliding window
        // i.e 1st unique element from left needs to be moved out of the window 
        while(uniqueCnt>k){
            hash[A[left]] = 0;
            left++;
            duplicates = 0;
            uniqueCnt--;
        }
        
        // Collect all the duplicates count which is collected in the previous variable
        while(hash[A[left]] > 1){
            cout << "duplicate found" << endl;
            duplicates++;
            hash[A[left]]--;
            left++;
        }
        
        if(uniqueCnt == k){
            ans = ans + duplicates + 1;
        }
        
        right++;
    }
    
    return ans;
}