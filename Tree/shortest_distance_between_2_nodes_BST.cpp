#include "_tree.h"

/**
 * LeeTcode Medium | Shortest distance between two nodes in BST
 * PreReq : BST, BST Validate, Construct BST, LCA of BST
 * 
 * Given a Binary Search Tree and two keys in it. 
 * Find the distance between two nodes with given two keys. 
 * It may be assumed that both keys exist in BST.
 * 
 * 
 * Input:  Root of above tree
         a = 3, b = 9
Output: 4 : Distance between 3 and 9 in above BST is 4.

Input: Root of above tree
         a = 9, b = 25
Output: 3 : Distance between 9 and 25 in above BST is 3.
 */

/**
 * Algorithm : Using Recursion
 * 1. We start from the root and for every node, we do following.
2. If both keys are greater than the current node, we move to the right child of the current node.
3. If both keys are smaller than current node, we move to left child of current node.
4. If one keys is smaller and other key is greater, current node is 
Lowest Common Ancestor (LCA) of two nodes. 
We find distances of current node from two keys and return sum of the distances.
 */

int distanceFromRoot(TreeNode* root, int node){
    if(root->val == node){
        return 0;
    }
    else if (node < root->val){
        return 1 + distanceFromRoot(root->left, node);
    }
    else{
        return 1 + distanceFromRoot(root->right, node);
    }
}

int shortestDistanceBST(TreeNode* root, int node1, int node2){
    // Check for the Tree
    cout << "Distance Bw " << node1 << " & " << node2 << endl;
    int res = -1;
    
    // make sure that node1 is smaller than node2 
    if(node1 > node2){
        swap(node1, node2);
    }

    if(!root)
        return res;

    if((node1 > root->val) && (node2 > root->val)){
        cout << "-- 1 -- " << endl;
        return shortestDistanceBST(root->right, node1, node2);
    }
    
    if(node1 < root->val && node2 < root->val){
        cout << "-- 2 -- " << endl;
        return shortestDistanceBST(root->left, node1, node2);
    }

    if(root->val >= node1 && root->val <= node2){
        cout << "-- 3 -- " << endl;
        return  distanceFromRoot(root, node1) + 
                distanceFromRoot(root, node2);
    }
}
