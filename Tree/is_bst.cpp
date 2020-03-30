#include "_tree.h"

/* Returns true if the given tree is a BST and its values are >= min and <= max. */
int isBSTUtil(TreeNode* node, long long min, long long max){
    /* an empty tree is BST */
    if (node==NULL)
        return 1;

    /* false if this node violates the min/max constraint */
    if (node->val <= min || node->val >= max)
        return 0;

    /* otherwise check the subtrees recursively, tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->val) && // Allow only distinct values
        isBSTUtil(node->right, node->val, max); // Allow only distinct values
}

bool isValidBST(TreeNode* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

/// Time Complexity: O(n)
/// Auxiliary Space : O(1) if Function Call Stack size is not considered,
///  otherwise O(n)


/// Simplified Method
/// We can simplify method 1 using NULL pointers instead of INT_MIN and INT_MAX
/// values.


// Returns true if given tree is BST.
bool isBST(TreeNode* root, TreeNode* left = NULL, TreeNode* right =NULL) {
    // Base condition
    if (root == NULL)
        return true;

    // if left TreeNode exist then check it has correct val or not
    // i.e. left TreeNode's val should be less than root's val
    if (left != NULL and root->val <= left->val)
        return false;

    // if right TreeNode exist then check it has correct val or not
    // i.e. right TreeNode's val should be greater than root's val
    if (right != NULL and root->val >= right->val)
        return false;

    // check recursively for every TreeNode.
    return isBST(root->left, left, root) and
           isBST(root->right, root, right);
}