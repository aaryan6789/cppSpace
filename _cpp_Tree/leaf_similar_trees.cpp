#include "_tree.h"
/**
 * LeetCode E | FB, GOOG
 *
 * Consider all the leaves of a binary tree.  From left to right order,
 * the values of those leaves form a leaf value sequence.
 *
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
 * Two binary trees are considered leaf-similar if their leaf value sequence is the same.
 *
 * Return true if and only if the two given trees with head nodes
 * root1 and root2 are leaf-similar.
 *
 * Note:
 * Both of the given trees will have between 1 and 100 nodes.
 */

/// Time Complexity: O(T_1 + T_2)  where T_1, T_2T are the lengths of the given trees.
/// Space Complexity: O(T_1 + T_2)  the space used in storing the leaf values.

// Helper Function to fill leaves
void fillLeaves(TreeNode* root, vector<int>& leaves){
    if(!root)
        return;

    if(!root->left && !root->right){
        leaves.push_back(root->val);
    }

    fillLeaves(root->left, leaves);
    fillLeaves(root->right, leaves);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    if (!root1 && root2)    return false;
    if (!root2 && root1)    return false;
    if (!root1 && !root2)   return true;

    vector<int> lvs1;
    vector<int> lvs2;

    fillLeaves(root1, lvs1);
    fillLeaves(root2, lvs2);

    if(lvs1 == lvs2){
        return true;
    }

    return false;

}