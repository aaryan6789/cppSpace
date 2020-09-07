#include "_tree.h"

/** LeetCode M | 199 : Right Side View
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * Example:
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 *
 * Explanation:
 *
 *    1            <---
 *  /   \
 * 2     3         <---
 *  \     \
 *   5     4       <---
 */

// Uisng 1 Queue and Traversal at each level
vector<int> rightSideView(TreeNode* root) {
    vector<int> rightView{};
    if (!root)
        return {};

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        // number of nodes at current level
        int n = q.size();

        // Traverse all nodes of current level
        for(int i = 1; i <= n; i++) {
            TreeNode* temp = q.front();
            q.pop();

            // Print the right most element at the level
            if (i == n){
                cout << temp->val << endl;
                rightView.push_back(temp->val);
            }


            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);

            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }

    return rightView;
}



// Using 2 Deque's (C Implementation)
vector<int> rightSideView2(TreeNode* root) {
    if(!root)
        return {};

    vector<int> right_view{};

    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    TreeNode* temp;

    q1.push(root);

    while(!q1.empty() || !q2.empty()){
        right_view.push_back(q1.back()->val);
        while(!q1.empty()){
            temp = q1.front();
            cout << "Q1 temp = " << temp->val << endl;
            q1.pop();

            // Push the Left and Right child of the TreeNode from q1 on to q2
            if(temp->left != NULL){
                q2.push(temp->left);
            }

            if(temp->right != NULL){
                q2.push(temp->right);
            }
        }
        cout << " q2.back()->val " << q2.back()->val << endl;
        right_view.push_back(q2.back()->val);


        while(!q2.empty()){
            temp = q2.front();
            cout << "Q2 temp = " << temp->val << endl;
            q2.pop();

            // Push the Left and Right child of the TreeNode from q2 on to q1
            if(temp->left != NULL){
                q1.push(temp->left);
            }

            if(temp->right != NULL){
                q1.push(temp->right);
            }
        }
        cout << " q1.back()->val " << q1.back()->val << endl;

    }

    return right_view;

}