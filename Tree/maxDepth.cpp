#include "_tree.h"
#include <algorithm>

int maxDepth(TreeNode* root) {
    if(root == nullptr){
        return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}