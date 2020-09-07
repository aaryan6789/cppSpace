#include "_tree.h"

/** LEETCODE E
 * Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
 */


/* A utility function to check whether trees with roots as root1 and root2 are
identical or not */
bool areIdentical(TreeNode * root1, TreeNode *root2) {
    /* base case(s) */
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if(root1->val != root2->val)
        return false;

    /* Check if the data of both roots is same and data of left and right
        subtrees are also same */
    return (areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right) );
}

bool isSubtree(TreeNode* S, TreeNode* T) {
    /* base cases */
    if (S == NULL)
        return false;

    if (T == NULL)
        return false;

    /* Check the tree with root as current node */
    if (areIdentical(S, T))
        return true;

    /* If the tree with root as current node doesn't match then
        try left and right subtrees one by one */
    return isSubtree(S->left, T) ||
            isSubtree(S->right, T);
}