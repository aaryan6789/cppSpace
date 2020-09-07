#include "_tree.h"

/** KTH SMALLEST ELEMENT | LEETCODE M | 230 https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

// Method 1 : Using inorder Traversal
void inOrderTraversalRR(TreeNode* root, vector<int>& inorder){
    if(root->left)
        inOrderTraversalRR(root->left, inorder);

    inorder.push_back(root->val);

    if(root->right)
        inOrderTraversalRR(root->right, inorder);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> inOrder;
    inOrderTraversalRR(root, inOrder);
    
    return inOrder[k-1];
}




TreeNode* dfs (TreeNode *root, int &k) {
    if (!root) {
        return nullptr;
    }
    
    TreeNode *lNode = dfs(root->left, k);
    TreeNode *rNode = nullptr;
    if (--k == 0) {
        return root;
    }
    if (!lNode) {
        rNode = dfs(root->right, k);   
    } else {
        return lNode;
    }
    return rNode;
}

int kthSmallest2(TreeNode* root, int k) {
    TreeNode *result = dfs(root, k);
    return result->val;
}



// Method 2 : Using Stack and BST Property
int kthSmallest3(TreeNode* root, int k) {
    stack<TreeNode*> s;
    
    while(root != NULL || !s.empty()){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
        
        root = s.top(); 
        s.pop();
        
        if(--k == 0) 
            return root->val;
        
        root = root->right;
    }
    
    return -1;
}




int kthSmallestI(TreeNode* root, int k) {
    if(root == NULL){
        return 0;
    }
    
    stack<TreeNode*> dfs;  //inorder traversal
    
    while(root != NULL || !dfs.empty()){
        while(root != NULL){
            dfs.push(root);
            root = root->left;
        }

        if(k > 1){
            root = dfs.top();
            dfs.pop();
            root = root->right;
                k--;
        } 
        else {
            return dfs.top()->val;
    }
    }
    return 0;        
}