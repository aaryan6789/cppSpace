#include "_tree.h"
#include <queue>
using namespace std;

/**
 * LeetCode E | 404
 * Find sum of all left leaves in a given Binary Tree
 * Given a Binary Tree, find sum of all left leaves in it.
 *
 * Example:

    3
   / \
  9  20
    /  \
   15   7

 * There are two left leaves in the binary tree, with values 9 and 15 respectively.
 * Return 24.
 */

bool isLeaf(TreeNode* root){
    if(!root){
        return false;
    }

    if(root->left == NULL && root->right == NULL){
        return true;
    }

    return false;
}

int sumOfLeftLeaves(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int leftSum = 0;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(isLeaf(temp->left)){
            leftSum += temp->left->val;
        }

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }

    return leftSum;
}
