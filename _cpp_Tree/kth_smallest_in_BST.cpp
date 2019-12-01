#include "_tree.h"





void inOrderTraversalR(TreeNode* root, vector<int>& inorder){
    if(root->left)
        inOrderTraversalR(root->left, inorder);

    inorder.push_back(root->val);

    if(root->right)
        inOrderTraversalR(root->right, inorder);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> inOrder;
    inOrderTraversalR(root, inOrder);
    
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

int kthSmallest(TreeNode* root, int k) {
    TreeNode *result = dfs(root, k);
    return result->val;
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