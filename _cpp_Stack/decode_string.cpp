#include <string>
#include <stack>
using namespace std;

/**
 * Algorithm: Using 2 Stacks
 * The idea is to use two stacks, one for integers and another for characters.
 * Now, traverse the string,
 * 
 * 1. Whenever we encounter any number, push it into the integer stack and 
 *    in case of any alphabet (a to z) or open bracket (‘[‘), 
 *    push it onto the character stack.
 * 
 * 2. Whenever any close bracket (‘]’) is encounter pop the character from the 
 *    character stack until open bracket (‘[‘) is not found in the character stack.
 *    Also, pop the top element from the integer stack, say n. 
 *    Now make a string repeating the popped character n number of time. 
 *    Now, push all character of the string in the stack.
 */
// Using 2 Stacks
string decodeString1(string s) {
    stack<string> chars;
    stack<int> nums;
    string res;
    int num = 0;
    
    for(char c : s) {
        if(isdigit(c)) {                    // If its a Integer
            num = num*10 + (c-'0');         // Convert into a number                      
        }
        else if(isalpha(c)) {
            res.push_back(c);
        }
        else if(c == '[') {
            chars.push(res);
            nums.push(num);
            res = "";
            num = 0;
        }
        else if(c == ']') {
            string tmp = res;
            for(int i = 0; i < nums.top()-1; ++i) {
                res += tmp;
            }
            res = chars.top() + res;
            chars.pop(); 
            nums.pop();
        }
    }
    return res;
}


// Using 1 Stack
string decodeString2(string s) {
    int n = s.size();
    stack<pair<string,int>> stk;
    
    int num = 0;
    string cur = "";
    
    for (int i = 0; i < n; ++i) {
        if (s[i] >= '0' && s[i] <= '9') { 
            num = num*10 + (s[i]-'0'); 
        }
        else if (s[i] == '[') {
            stk.push( {cur,num} );
            cur = "";
            num = 0;
        }
        else if (s[i] == ']') {
            string pre_s = stk.top().first;
            int pre_num = stk.top().second;
            stk.pop();
            
            for (int j = 0; j < pre_num; ++j) {
                pre_s += cur;
            }
            cur = pre_s;
        }
        else {
            cur += s[i];
        }
    }
    
    return cur;
}