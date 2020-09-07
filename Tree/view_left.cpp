
#include "_tree.h"

/**
 * CTCI
 * Given a Binary Tree, print it’s left view.
 * Left view of a Binary Tree is a set of nodes visible when tree is seen from
 * the left side
 */
/*
 * Examples:
 *
 * Input :        1
 *              /   \
 *             2     3
 *            / \   / \
 *           4   5 6   7
 * Output : 1 2 4
 *
 * Input :         1
 *               /   \
 *              2     3
 *               \   /
 *                4 5
 *                   \
 *                    6
 *                   / \
 *                  7   8
 * Output : 1 2 4 6 7
 **/

/// Algorithm:
/// The idea is to do level order traversal of the Tree using a queue and
/// print the first node at each level.
/// While doing level order traversal, after traversing all node at each level,
///  push a NULL delimiter to mark the end of the current level.
/// So, do the level order traversal of the tree.
/// Print the first node at each level in the tree and
/// push the children of all nodes at each level in the queue
/// until a NULL delimiter is encountered.

void leftView(TreeNode* root) {
    cout << "Left View " << endl;
    if (root == NULL)
        return;

    queue<TreeNode*> q;
    q.push(root);       // Push root
    q.push(NULL);       // Delimiter

    while (!q.empty()) {
        TreeNode* temp = q.front();
        if (temp) {
            // Prints first node of each level
            cout << temp->val << " ";

            // Push children of all nodes at current level
            while (q.front() != NULL) {
                // If left child is present push into queue
                if (temp->left)
                    q.push(temp->left);

                // If right child is present push into queue
                if (temp->right)
                    q.push(temp->right);

                // Pop the current node
                q.pop();
                temp = q.front();
            }
            // Push delimiter for the next level
            q.push(NULL);
        }
        // Pop the delimiter of the previous level
        q.pop();
    }
}

void leftView2(TreeNode* root) {
    cout << "Left View " << endl;
    if (root == NULL)
        return;

    queue<TreeNode*> q;
    q.push(root);       // Push root
    vector<int> left;
    TreeNode* temp;

    while (!q.empty()) {
        int n = q.size();
        left.push_back(q.front()->val);
        cout << q.front()->val << " ";

        if(n == 0)
            break;

        while(n--){
            temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);

            // If right child is present push into queue
            if (temp->right)
                q.push(temp->right);
            
        }
    }
}