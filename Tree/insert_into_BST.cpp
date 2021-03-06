#include "_tree.h"

/**
 * LEETCODE M | INSERT INTO TREE
 * Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:

         4
       /   \
      2     7
     / \   /
    1   3 5
This tree is also valid:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4
 */

TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* newNode = new TreeNode(val);
    
    if(root == NULL){
        return newNode;
    }
    
    // Insert into the BST
    // If val is greater than the root val then it goes towards the right
    if(val > root->val){
        root->right = insertIntoBST(root->right, val);
    }
    else{
        // else it goes towards the left
        root->left = insertIntoBST(root->left, val);
    }
    
    return root;
}