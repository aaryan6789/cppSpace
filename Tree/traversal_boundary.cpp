#include "_tree.h"

/** Top Amazon 50
 * 545. Boundary of Binary Tree | LEETCODE Medium 
 * Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.  (The values of the nodes may still be duplicates.)

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1

Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].
 

Example 2

Input:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Boundary Traversal
// Left Boundary + Leaf Nodes + Right Boundary

void leftBoundary(TreeNode* root, vector<int>& res){
    if(!root)
        return;
    // to ensure top down order, print the node 
    // before calling itself for left subtree 
    if(root->left){         // it wont prin tleaf as root->left condition will fail
        res.push_back(root->val);
        leftBoundary(root->left, res);
    }
    else if(root->right){
        res.push_back(root->val);
        leftBoundary(root->right, res);
    }
}

void rightBoundary(TreeNode* root, vector<int>& res){
    if(!root)
        return;
    
    // to ensure bottom up order, first call for right 
    // subtree, then print this node 
    if(root->right){
        rightBoundary(root->right, res);
        res.push_back(root->val);
    }
    else if(root->left){
        rightBoundary(root->left, res);
        res.push_back(root->val);

    }
}

void leafNodes(TreeNode* root, vector<int>& res){
    if(!root)
        return;
    
    leafNodes(root->left, res);
    
    if(!root->left && !root->right)
        res.push_back(root->val);
    
    leafNodes(root->right, res);
    
}

vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> res = {};
    
    if(!root){
        return res;
    }
    res.push_back(root->val);
    
    leftBoundary(root->left, res);
    
    leafNodes(root->left, res);
    leafNodes(root->right, res);
    
    rightBoundary(root->right, res);
    
    return res;
}