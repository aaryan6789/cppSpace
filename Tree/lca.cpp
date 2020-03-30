#include "_tree.h"
/* LeetCode | E | 237
 * Given a binary search tree (BST), find the lowest common ancestor (LCA)
 * of two given nodes in the BST.
 *
 * The lowest common ancestor is defined between two nodes p and q as
 * the lowest node in T that has both p and q as descendants
 * (where we allow a node to be a descendant of itself).�
 *
 * Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4_     7        9
         /   \
        3     5

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself
             according to the LCA definition.

Note:
All of the nodes' values will be unique.
p and q are different and both values will exist in the BST.
*/

/*
Time Complexity: O(N), where N is the number of nodes in the binary tree.
In the worst case we might be visiting all the nodes of the binary tree.

Space Complexity: O(N). This is because the maximum amount of space utilized
by the recursion stack would be NN since the height of a skewed binary tree could be N.
 */

TreeNode* lowestCommonAncestorBT(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL)
        return NULL;

    if((root == p) || (root == q))
        return root;

    TreeNode* leftLCA = lowestCommonAncestorBT(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestorBT(root->right, p, q);

    if(leftLCA && rightLCA)
        return root;
    else if (leftLCA != NULL)
        return leftLCA;
    else
        return rightLCA;
}
