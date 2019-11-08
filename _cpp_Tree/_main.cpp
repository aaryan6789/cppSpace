#include "_tree.h"





int main(){
    TreeNode* root = new TreeNode(10);
    TreeNode left1(20);
    TreeNode right1(30);
    TreeNode* left2 = new TreeNode(40);
    TreeNode* right2 = new TreeNode(50);
    root->left = &left1;
    root->right = &right1;
    root->left->left = left2;
    root->left->right = right2;
    root->right = &right1;


    std::cout << size2(root) << std::endl;
    std::cout << numLeafNodes(root) << std::endl;

    cout << "Inorder Traversal Recursive for " << root->val << endl;
    inOrderTraversalR2(root);

    reverseLevelOrder(root);
    printZigZagTraversal(root);



    return 0;
}