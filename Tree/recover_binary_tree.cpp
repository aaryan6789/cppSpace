#include "_tree.h"

/**
99. Recover Binary Search Tree | Hard

Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.

Example 1:
Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:
A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
 */

// https://leetcode.com/problems/recover-binary-search-tree/discuss/423225/C%2B%2B-Clear-Solution-(with-Explanation)
// Using Inorder Traversal and 3 Pointers
// first, current , last

void recoverTree(TreeNode* root) {
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* last = nullptr;
    
    inorder(root, prev, first, last);
    swap(first->val, last->val);
}

void inorder(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& last){
    if(!root)
        return;
    
    inorder(root->left, prev, first, last);
    
    // Modified Inorder Sequnece
    if(prev){
        if(root->val < prev->val){
            if(!first){
                first = prev;
            }
            last = root;
        }
    }
    
    prev = root;
    
    inorder(root->right, prev, first, last);
}