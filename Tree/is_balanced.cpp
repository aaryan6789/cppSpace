#include "_tree.h"
using namespace std;

bool isBalanced(TreeNode* root) {
    if(root == nullptr){
        return true;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    if( ( abs(leftDepth - rightDepth) <= 1) &&
        ( isBalanced(root->left)) &&
        ( isBalanced(root->right))){
        return true;
    }

    return false;
}