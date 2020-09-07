#include "_tree.h"

/** LeetCode E 235 | https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * 
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of 
 * two given nodes in the BST.
 * 
 * According to the definition of LCA on Wikipedia: 
 * “The lowest common ancestor is defined between two nodes p and q as the lowest
 * node in T that has both p and q as descendants (where we allow a node to be a
 * descendant of itself).”
 * 
 * Example 1:
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 * 
 * Example 2:
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of 
 * itself according to the LCA definition.
 *  
 * 
 * Note:
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the BST.
 */

/**
 * Algorithm - Recursive
 * 
 * 1. Start traversing the tree from the root node.
 * 2. If both the nodes p and q are in the right subtree, 
 *    then continue the search with right subtree starting step 1.
 * 3. If both the nodes p and q are in the left subtree, 
 *    then continue the search with left subtree starting step 1.
 * 4. If both step 2 and step 3 are not true, this means we have found the node 
 *    which is common to node p's and q's subtrees. 
 *    and hence we return this common node as the LCA.
*/

/**
Time Complexity: O(N), where N is the number of nodes in the BST. 
In the worst case we might be visiting all the nodes of the BST.

Space Complexity: O(N). This is because the maximum amount of space utilized 
by the recursion stack would be NN since the height of a skewed BST could be NN.
**/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if ((root->val > p->val) && (root->val > q->val)) {
        return lowestCommonAncestor(root->left, p, q);
    }
    if ((root->val < p->val) && (root->val < q->val)) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}

/**
 * Algorithm - Iterative
 * The steps taken are also similar to approach 1. 
 * The only difference is instead of recursively calling the function, 
 * we traverse down the tree iteratively. 
 * This is possible without using a stack or recursion since we don't need to
 * backtrace to find the LCA node. 
 * In essence of it the problem is iterative, 
 * it just wants us to find the split point. 
 * The point from where p and q won't be part of the same subtree or when one 
 * is the parent of the other.
 */
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* cur = root;
    while (true) {
        if (p->val < cur->val && q->val < cur->val) {
            cur = cur->left;
        } 
        else if (p->val > cur->val && q->val > cur->val) {
            cur = cur->right;
        } 
        else {
            break;
        }
    }
    return cur;
}