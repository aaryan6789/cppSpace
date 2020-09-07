#include "_tree.h"

// 111 LEETCODE E
/* minDepth : Calculate the Min Depth of the Binary Tree
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path
 *  from the root node down to the nearest leaf node.
 * Note: A leaf is a node with no children.
 *
 * Example: Given binary tree [3,9,20,null,null,15,7],
 *  3
   / \
  9  20
    /  \
   15   7

   return its minimum depth = 2.
 */

/** Algorithm : Using Recusion DFS
 * Time complexity : we visit each node exactly once, thus the time complexity
 * is O(N), where N is the number of nodes.
 *
 * Space complexity : In the worst case, the tree is completely unbalanced, e.g.
 *  each node has only one child node, the recursion call would occur N times
 * (the height of the tree), therefore the storage to keep the call stack would
 * be O(N).
 * But in the best case (the tree is completely balanced), the height of the
 *  tree would be log(N).
 * Therefore, the space complexity in this case would be O(log(N))
 */
int minDepth(TreeNode* root) {
    if(root == NULL)
        return 0;

    if(!root->left)
        return 1 + minDepth(root->right);
    else if(!root->right)
        return 1 + minDepth(root->left);
    else {
        int leftMin = minDepth(root->left);
        int rightMin = minDepth(root->right);

        if(leftMin > rightMin){
            return rightMin+1;
        }
        else{
            return leftMin+1;
        }
    }
}
