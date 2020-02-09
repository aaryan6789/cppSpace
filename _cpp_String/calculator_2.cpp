#include "_string.h"
/**
LeetCode M | 227 | Basic Calculator II
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators 
and empty spaces . The integer division should truncate toward zero.

Example 1: Input: "3+2*2"           Output: 7
Example 2: Input: " 3/2 "           Output: 1
Example 3: Input: " 3+5 / 2 "       Output: 5

Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

// init 1 stack
// init 1 buffer for number(cos it might have more than one digit)
// init 1 buffer for the last operator

// if the current character is an operator, 
//  i) operate the current number with the previous operator, 
// ii) put the result into the stack, 
//iii) set the current character as the next operator

// sum up all the numbers in the stack to get the result
int calculate2(string s) {
    stack<int> myStack;
    char sign = '+';
    int num = 0;
    
    for (unsigned int i = 0; i < s.size(); i++) {
        // If its a Digit then make the whole number
        if (isdigit(s[i]))
            num = 10*num + s[i]-'0';
        
        if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1) {
            // If a Negative number
            if (sign == '-'){
                myStack.push(-num);
            }
            // If a Positive number
            else if (sign == '+'){
                myStack.push(num);
            }
            else {
                int res;
                if (sign == '*' )
                    res = myStack.top() * num;
                else
                    res = myStack.top() / num;
                
                myStack.pop();
                myStack.push(res);
            } 
            sign = s[i];
            num = 0;
        }
    }

    int res = 0;
    // Perform the Addition and Subtraction now
    while (!myStack.empty()) {
        res += myStack.top();
        myStack.pop();
    }

    return res;
}