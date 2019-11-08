#include "_r_dp.h"
/**
 * 22 LeetCode M | String | BackTracking | https://leetcode.com/problems/generate-parentheses/
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 *
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 */

/// Recusrive Solution

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string paren;
    generate(n, 0, 0, paren, result);
    return result;
}

void generate(int n, int l, int r, string paren, vector<string>& result) {
    if (l == n && r == n) {
        result.push_back(paren);
    }
    else {
        if (l < n) {
            generate(n, l + 1, r, paren + '(', result);
        }

        if (r < l) {
            generate(n, l, r + 1, paren + ')', result);
        }
    }
}

// recursive DFS

vector<string> generateParenthesis2(int n) {
    vector<string> result;
    string paren_str;

    dfs(result, paren_str, n, 0, 0);

    return result;
}

void dfs(vector<string> & result, string & paren_str, int n, int left, int right) {
    if (paren_str.size() == n * 2) {
        result.push_back(paren_str);
        return;
    }

    if (left < n) {
        paren_str += '(';
        dfs(result, paren_str, n, left + 1, right);
        paren_str.pop_back();
    }

    if (left > right) {
        paren_str += ')';
        dfs(result, paren_str, n, left, right + 1);
        paren_str.pop_back();
    }
}





/// Iterative Solution
vector<string> generateParenthesis(int n) {
    if (!n) {
        return {""};
    }

    vector<string> parens;

    for (int i = 0; i < n; i++) {
        for (string l : generateParenthesis(i)) {
            for (string r : generateParenthesis(n - 1 - i)) {
                parens.push_back('(' + l + ')' + r);
            }
        }
    }

    return parens;
}