#include "_tree.h"


unordered_map<int, int> in_map;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();

    int i = 0;
    for(auto &in : inorder){
        in_map[in] = i++;
    }

    return dfs(preorder, 0, n-1, inorder, 0, n-1);
}

TreeNode* dfs(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie){
    if(ps > pe){
        return NULL;
    }

    int val = preorder[ps];
    TreeNode* root = new TreeNode(val);

    if(ps == pe){
        return root;
    }

    int pos = in_map[val];
    int index = pos - is;

    root->left  = dfs(preorder, ps+1, ps+index, inorder, is, pos - 1);
    root->right = dfs(preorder, (ps+index+1), pe, inorder, pos+1, ie);

    return root;
}