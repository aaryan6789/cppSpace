#include "test.hpp"
#include <iostream>
/**
 * LeetCode Easy
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 * Input: 123
 * Output: 321
 *
 * Example 2:
 * Input: -123
 * Output: -321
 *
 * Example 3:
 * Input: 120
 * Output: 21
 *
 * Input : -2147483648
 * Output : 0
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1].
 * For the purpose of this problem, assume that your function returns 0 when the
 * reversed integer overflows.
 */
int reverse(int x) {
    int rev = 0;
    int rem;
    while(x != 0){
        rem = x%10;

        // For Checking the boundaries
        if(rev > INT_MAX/10 || rev < INT_MIN/10) {
            return 0;
        }

        rev = rev*10 + rem;
        x = x/10;
    }

    return rev;
}