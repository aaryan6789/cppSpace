#include "_tree.h"

/** LeetCode M | Find Leaves of Binary Tree | 366
 *
 * Given a binary tree, collect a tree's nodes as if you were doing this:
 * Collect and remove all leaves, repeat until the tree is empty.
 *
 * Example:
 * Input: [1,2,3,4,5]
 *
 *           1
 *          / \
 *         2   3
 *        / \
 *       4   5
 *
 * Output: [[4,5,3],[2],[1]]
 *
 *
 * Explanation:
 * 1. Removing the leaves [4,5,3] would result in this tree:
 *
 *           1
 *          /
 *         2
 *
 * 2. Now removing the leaf [2] would result in this tree:
 *
 *           1
 *
 * 3. Now removing the leaf [1] would result in the empty tree:
 *
 *           []
 */

// Using DFS + Recursion
void dfs(TreeNode *&root, vector<int> &leaves) {
    if(root == NULL)
        return;

    if(!root->left && !root->right) {
        leaves.push_back(root->val);
        root = NULL;    // delete root; // To avoid infinite recursion
    }
    else {
        if(root->left)
            dfs(root->left, leaves);
        if(root->right)
            dfs(root->right, leaves);
    }
}

vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> res;

    while(root) {
        vector<int> leaves;

        dfs(root, leaves);
        res.push_back(leaves);
    }

    return res;
}