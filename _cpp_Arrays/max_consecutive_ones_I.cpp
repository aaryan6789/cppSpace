#include "_array.h"
/**
 * LeetCod E | 485 Max Consecutive Ones | Easy
 * Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
 */

int findMaxConsecutiveOnes2(vector<int>& nums) {
    int count = 0;
    int maxCnt = 0;
    for(int i = 0; i< nums.size(); i++){
        if(nums[i] == 1){
            count++;
            maxCnt = max(maxCnt, count);
        }
        else{
            count = 0;
        }
    }

    return maxCnt;
}
int findMaxConsecutiveOnes(vector<int>& nums) {
    int l = 0, r = 0;
    int ret = 0;
    while (l < nums.size()){
        while (l < nums.size() && nums[l] != 1){
            ++l;
        }
        r = l;

        while (r < nums.size() && nums[r] == 1){
            ++r;
        }

        ret = std::max(ret, r-l);
        l = r;
    }

    return ret;
}