
#include "_tree.h"

/**
 * Given the root of a binary tree, find the maximum average value of any subtree of that tree.

(A subtree of a tree is any node of that tree plus all its descendants. The average value of a tree is the sum of its values, divided by the number of nodes.)

 

Example 1:



Input: [5,6,1]
Output: 6.00000
Explanation: 
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.
 

Note:

The number of nodes in the tree is between 1 and 5000.
Each node will have a value between 0 and 100000.
Answers will be accepted as correct if they are within 10^-5 of the correct answer.
 */ 
double dfs(TreeNode* root, int& count, double& maxAvg){
    if(!root) return 0;
    
    int left_cnt = 0;
    int right_cnt = 0;
    
    double subSum = dfs(root->left, left_cnt, maxAvg) + 
                    dfs(root->right, right_cnt, maxAvg) +
                    root->val;
    count = left_cnt + right_cnt + 1;
    
    maxAvg = max(subSum/count, maxAvg);
    return subSum;
}

double maximumAverageSubtree(TreeNode* root) {
    double maxAvg = 0;      // MaxAvergae 
    int count = 0;          // Count of nodes
    
    dfs(root, count, maxAvg);
    return maxAvg;
}

double ans = 0.00;
// Each node returns the sum of left values,right values, and the total amount 
// of nodes passed on. You add the accumilated node values to the first parameter
//  of the pair and add your own value, then you add the total node numbers to
//  the second param, then add one to it
pair<int, int> dfs2(TreeNode* root){
    if(!root) return {0,0};
    
    auto left = dfs2(root->left);
    auto right = dfs2(root->right);
    
    int sum = root->val + left.first + right.first;
    int count = 1 + left.second + right.second;
    
    double ansval = double(sum)/count;
    ans = max(ans, ansval);
    return {sum, count};
}

double maximumAverageSubtree2(TreeNode* root) {
    dfs2(root);
    return ans;
}