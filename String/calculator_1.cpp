#include "_string.h"

/**
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), 
the plus + or minus sign -, non-negative integers and empty spaces .

Example 1: Input: "1 + 1"           Output: 2

Example 2: Input: " 2-1 + 2 "       Output: 3

Example 3: Input: "(1+(4+5+2)-3)+(6+8)"     Output: 23

Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

// calculate the numbers on the same level
// when we see a `(`, put the intermediate result into the stack, and start new calculation right after this `(`
// when we see a `)`, pop the add/minus the result with the last item in the stack


int calculate1(string s) {
    stack <int> nums, ops;
    int num = 0;
    int rst = 0;
    int sign = 1;
    for (char c : s) { 
        if (isdigit(c)) {
            num = num * 10 + c - '0';
        }
        else {
            rst += sign * num;
            num = 0;
            if (c == '+') sign = 1;
            if (c == '-') sign = -1;
            if (c == '(') {
                nums.push(rst);
                ops.push(sign);
                rst = 0;
                sign = 1;
            }
            if (c == ')' && ops.size()) {
                rst = ops.top() * rst + nums.top();
                ops.pop(); nums.pop();
            }
        }
    }
    rst += sign * num;
    return rst;
}