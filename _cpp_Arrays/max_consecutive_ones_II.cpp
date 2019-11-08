#include "_array.h"

/**
 * LeetCode M | CTCI
 * Given a binary array, find the maximum number of consecutive 1s in this array
 * if you can flip at most one 0.
 *
 * Example 1:
 * Input: [1,0,1,1,0]
 * Output: 4
 * Explanation:
 * Flip the first zero will get the the maximum number of consecutive 1s.
 * After flipping, the maximum number of consecutive 1s is 4.
 *
 * Note:
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 *
 * Follow up:
 * What if the input numbers come in one by one as an infinite stream?
 * In other words, you can't store all numbers coming from the stream as it's
 * too large to hold in memory.
 * Could you solve it efficiently?
 */

int findMaxConsecutiveOnesFlip(vector<int>& nums) {
    int res = 0;
    int currContOnes = 0;
    int prevContOnes = -1; // set to -1 to handle the case when the vectors starts with 1
    for (int num : nums) {
        if (num == 1) {
            currContOnes++; // increase curr continuous ones
        }
        else {
            if (currContOnes == 0) {
                prevContOnes = 0; // the two continuous 1's are apart by more than one 0's
            }
            else {
                prevContOnes = currContOnes;
                currContOnes = 0;
            }
        }
        res = max(res, currContOnes + prevContOnes + 1);
    }
    return res;
}



int findMaxConsecutiveOnesFlip2(vector<int>& nums) {
    int count_1 = 0; int count_2 = 0;
    int answer = 0; bool has_zero = false;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0){
            count_2 = count_1;
            count_1 = 0;
            has_zero = true;
        } else {
            count_1++;
        }
        answer = max(answer, count_1 + count_2 + (has_zero == true));
    }

    return answer;
}