#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Methods
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// TreeNode newNode(int x){
//     TreeNode ntNode(x);
//     return ntNode;
// }

template <typename T>
void printArray(const vector<T>& A){
    for(int i = 0 ; i< A.size() ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}


// TreeNode Size
int size2(TreeNode* root);
int size(TreeNode* root);

// Tree Leaf Questions
int numLeafNodes(TreeNode* root);
int sumOfLeftLeaves(TreeNode* root);

/// Tree Depth
int maxDepth(TreeNode* root);
bool isBalanced(TreeNode* root);

/// Tree Levels
vector<double> averageOfLevels(TreeNode* root);

/// Tree Traversals

void inOrderTraversalR2(TreeNode* root);
void inOrderTraversalI(TreeNode* root);
void inOrderStack(TreeNode* root);


void inOrderTraversalR(TreeNode* root, vector<int>& inorder);
vector<int> inorderTraversalDFS(TreeNode* root);
vector<int> inorderTraversal(TreeNode* root);


void reverseLevelOrder(TreeNode* root);
vector<vector<int>> zigzagLevelOrder(TreeNode* root);
void printZigZagTraversal(struct TreeNode* root);



vector<string> binaryTreePathsI(TreeNode* root);

vector<string> binaryTreePathsII(TreeNode* root);

