#include "_tree.h"
#include <queue>
using namespace std;

/**
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 * Example 1:
 *
 * Input:
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * Output: [3, 14.5, 11]
 *
 * Explanation:
 * The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2
 * is 11. Hence return [3, 14.5, 11].
 *
 * Note:
 * The range of node's value is in the range of 32-bit signed integer.
 */
using namespace std;

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;

    // Create a Queue
    queue<TreeNode*> q;
    q.push(root);

    while(q.size() != 0){
        int count = q.size();
        double sum=0;
        double nodes=0;

        while(count>0) {
            TreeNode* curr = q.front();
            q.pop();
            sum = sum + curr->val;
            nodes++;

            if(curr->left!=NULL)
                q.push(curr->left);

            if(curr->right!=NULL)
                q.push(curr->right);

            count--;
        }

        double val = sum/nodes;
        result.push_back(val);
    }

    return result;
}