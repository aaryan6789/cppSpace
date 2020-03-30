#include "_tree.h"





int main(){
    /**        root
     *          10
     *        /   \
     *      20     30
     *    /   \
     *  40     50
     */
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

    printPretty(root, 0, 5, cout);

    cout << "Inorder Traversal Recursive for " << root->val << endl;
    inOrderTraversalR2(root);
    printZigZagTraversal(root);
    binaryTreePathsII(root);

    /**        root
     *          40
     *        /   \
     *      20     50
     *    /   \
     *  10     30
     */
    TreeNode* root2 = new TreeNode(40);
    TreeNode left21(20);
    TreeNode right21(50);
    TreeNode* left22 = new TreeNode(10);
    TreeNode* right22 = new TreeNode(30);
    root2->left = &left21;
    root2->right = &right21;
    root2->left->left = left22;
    root2->left->right = right22;

    cout << shortestDistanceBST(root2, 20, 30) << endl;
    cout << shortestDistanceBST(root2, 40, 30) << endl;
    cout << shortestDistanceBST(root2, 20, 20) << endl;

    insertIntoBST(root2, 25);
    // cout << "New Root 2 " << root->val << endl;
    // printlevelOrderTraversalLine(root2);
    printPretty(root2, 0, 5, cout);

    TreeNode* root3 = nullptr;
    vector<int> nums = {89, 100, 33, 22, 45, 88, 90, 10};
    for(auto n : nums){
        root3 = insertIntoBST(root3, n);
        cout << "Root " << root3->val << endl;
    }

    printPretty(root3, 0, 5, cout);
    // invertTreeR(root3);

    // printPretty(root3, 0, 5, cout);

    cout << "Left View " << endl;
    leftView2(root3);
    // leftView(root3);
    
    cout << "Vertical Order Traversal " << endl;
    vector<vector<int>> vo = verticalTraversal(root3);
    for(auto v : vo){
        printArray(v);
    }

    top_view(root3);

    return 0;
}