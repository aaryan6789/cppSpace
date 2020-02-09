#include "_tree.h"

/** Based on Max Diameter of the Tree
 * LeetCode H | 124. Binary Tree Maximum Path Sum
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * 
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections. 
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * Example 1:
 * Input: [1,2,3]
 * 
 *        1
 *       / \
 *      2   3
 * 
 * Output: 6
 * 
 * Example 2:
 * Input: [-10,9,20,null,null,15,7]
 * 
 *    -10
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * Output: 42
 */

static int dfs(TreeNode* root, int& maxsum) {
    if(!root) 
        return 0;
    int l_max = max(0, dfs(root->left, maxsum));
    int r_max = max(0, dfs(root->right, maxsum));
    maxsum = max(l_max + r_max + root->val, maxsum);
    return root->val + max(l_max,r_max);
}

int maxPathSum(TreeNode* root) {
    int maxsum = INT_MIN;
    dfs(root,maxsum);
    return maxsum;
}