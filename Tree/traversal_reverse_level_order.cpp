#include "_tree.h"
#include <algorithm>

/* Given a binary tree, return the bottom-up level order traversal of its TreeNodes
 * values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 */

/* Method 1 : Using Queue and Stack
 * 1. Create a Queue
 *    Create a Stack
 * 2. EnQueue the root
 * 3. while the the queue is not empty
 *   a. Dequeue from the Queue
 *   b. Push it on the Stack
 *   c. If right child is present, enQueue Right Child
 *   d. If left child is available, enQueue Left Child
 * 4. Print the Stack
 *
 * Time Complexity = O(n)
 * Space Complexity = O(2n) for Queue and Stack
 */

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> levels{};
    if(!root)
        return levels;

    TreeNode* temp;
    queue<TreeNode*> q;
    q.push(root);
    vector<int> level{};
    while(1){
        int nodeCount = q.size();
        if(nodeCount == 0)
            break;

        while(nodeCount>0){
            temp = q.front();
            q.pop();
            level.push_back(temp->val);

            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);

            nodeCount--;
        }
        levels.push_back(level);
        level.clear();
    }
    reverse(levels.begin(), levels.end());
    return levels;
}

void printReverseLevelOrder(TreeNode* root){
    cout << "Reverse Level Order Traversal for Root = " << root->val << endl;
    stack <TreeNode*> S;
    queue <TreeNode*> Q;
    Q.push(root);

    // Do something like normal level order traversal order. Following are the
    // differences with normal level order traversal
    // 1) Instead of printing a TreeNode, we push the TreeNode to stack
    // 2) Right subtree is visited before left subtree
    while (Q.empty() == false){
        /* Dequeue TreeNode and make it root */
        root = Q.front();
        Q.pop();
        S.push(root);

        /* Enqueue right child */
        if (root->right)
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT

        /* Enqueue left child */
        if (root->left)
            Q.push(root->left);
    }

    // Now pop all items from stack one by one and print them
    while (S.empty() == false)
    {
        root = S.top();
        cout << root->val << " ";
        S.pop();
    }
}