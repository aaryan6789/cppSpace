#include "_backtracking.h"
#include <string>

/* Letter COMBINATION | LeetCode M | 17 | 
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Given a string containing digits from 2-9 inclusive, return all possible 
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given 
 * below. Note that 1 does not map to any letters.
 * 
 * Example:
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 */

// Using Recursion (DFS + BackTracking)

// Declare the String Combinations
// For each digit, append its corresponding letters one at a time and 
// recursively append the remaining.
vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(string digits, int i, const string& str, vector<string>& res);
vector<string> letterCombinations(string digits) {
    vector<string> res{};
    
    if(digits.empty()){
        return res;
    }
    
    string str;
    dfs(digits, 0, str, res);
    
    return res;
}


void dfs(string digits, int i, const string& str, vector<string>& res){
    // If the pos reaches to the size of the digits then append it to the res
    if(i == digits.size()){
        res.push_back(str);
    }
    else{
        for(char c : dict[digits[i] - '0']){
            dfs(digits, i+1, str + c, res);
        }
    }
}

/**
 * Time complexity : O(3^N X 4^M) where N is the number of digits in the input 
 * that maps to 3 letters (e.g. 2, 3, 4, 5, 6, 8) and 
 * M is the number of digits in the input that maps to 4 letters 
 * (e.g. 7, 9), and N+M is the total number digits in the input.

 * Space complexity : O(3^N X 4^M) since one has to keep 3^N X 4^M solutions.
 */


// Iterative

// Suppose we have got the combinations for digits[0..i-1], for digits[i], 
// we just need to apppend each of its corresponding letters to the previous 
// combinations.

vector<string> letterCombinationsI(string digits) {
    if (digits.empty()) {
        return {};
    }
    
    vector<string> res = {""};
    for (char d : digits) {
        vector<string> temp;
        for (string comb : res) {
            for (char c : dict[d - '0']) {
                temp.push_back(comb + c);
            }
        }
        swap(res, temp);
    }
    return res;
}