
#include "_tree.h"
using namespace std;

/**
 *  LeetCode E | CTCI
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Input:
 *
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 *
 * Output: ["1->2->5", "1->3"]
 *
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 */
void helper(vector<string> &res, string &cur, TreeNode *root);

vector<string> binaryTreePathsR(TreeNode* root) {
    cout << "Binary Tree Root to Leaf Paths" << endl;
    vector<string> res;
    if(root == nullptr)
        return res;

    string cur = to_string(root->val);
    helper(res, cur, root);
    printArray(res);
    return res;
}

void helper(vector<string> &res, string &cur, TreeNode *root) {
    if(root->left == nullptr && root->right == nullptr) {
        res.push_back(cur);
        return;
    }

    if(root->left) {
        string temp = cur + "->" + to_string(root->left->val);
        helper(res, temp, root->left);
    }

    if(root->right) {
        string temp = cur + "->" + to_string(root->right->val);
        helper(res, temp, root->right);
    }

}


// using a Stack (faster then Queue)
vector<string> binaryTreePathsI(TreeNode* root) {
    vector<string> res;
    if(root == nullptr)
        return res;
    stack<pair<TreeNode*, string>> my_stack;
    my_stack.push(make_pair(root, to_string(root->val)));

    while(!my_stack.empty()) {
        pair<TreeNode*, string> temp = my_stack.top();
        my_stack.pop();

        TreeNode *node = temp.first;
        string path = temp.second;

        if(node->left == nullptr && node->right == nullptr) {
            res.push_back(path);
            printArray(res);
        }
        else {
            if(node->right != nullptr) {
                my_stack.push(make_pair(node->right, path + "->" + to_string(node->right->val)));
            }
            if(node->left != nullptr) {
                my_stack.push(make_pair(node->left, path + "->" + to_string(node->left->val)));
            }
        }
    }
    return res;
}


// Using a Queue
vector<string> binaryTreePathsII(TreeNode* root) {
    vector<string> res;
    if(root == nullptr)
        return res;
    queue<pair<TreeNode*, string>> my_stack;
    my_stack.push(make_pair(root, to_string(root->val)));

    while(!my_stack.empty()) {
        pair<TreeNode*, string> temp = my_stack.front();
        my_stack.pop();

        TreeNode *node = temp.first;
        string path = temp.second;

        if(node->left == nullptr && node->right == nullptr) {
            res.push_back(path);
            printArray(res);
        }
        else {
            if(node->right != nullptr) {
                my_stack.push(make_pair(node->right, path + "->" + to_string(node->right->val)));
            }
            if(node->left != nullptr) {
                my_stack.push(make_pair(node->left, path + "->" + to_string(node->left->val)));
            }
        }
    }
    return res;
}