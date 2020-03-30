#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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
void printlevelOrderTraversal(TreeNode* root);
void inOrderTraversalR2(TreeNode* root);
void inOrderTraversalI(TreeNode* root);
void inOrderStack(TreeNode* root);

/// Tree Views
void leftView(TreeNode* root);
void leftView2(TreeNode* root);
vector<int> top_view(TreeNode* root);

void inOrderTraversalR(TreeNode* root, vector<int>& inorder);
vector<int> inorderTraversalDFS(TreeNode* root);
vector<int> inorderTraversal(TreeNode* root);
void printPretty(TreeNode *root, int level, int indentSpace, ostream& out);
void printlevelOrderTraversalLine(TreeNode* root);
void reverseLevelOrder(TreeNode* root);
vector<vector<int>> zigzagLevelOrder(TreeNode* root);
void printZigZagTraversal(struct TreeNode* root);
vector<vector<int>> verticalTraversal(TreeNode* root);

/// Tree Paths

vector<string> binaryTreePathsI(TreeNode* root);

vector<string> binaryTreePathsII(TreeNode* root);
int distanceFromRoot(TreeNode* root, int node);
int shortestDistanceBST(TreeNode* root, int node1, int node2);
struct TreeNode* invertTreeR(struct TreeNode* root);

TreeNode* insertIntoBST(TreeNode* root, int val);
