
#include "_tree.h"

/**
 * CTCI | Print nodes at k distance from root
 * Given a root of a tree, and an integer k.
 * Print all the nodes which are at k distance from root.
 * For example, in the below tree, 4, 5 & 8 are at distance 2 from root.
 *             1
 *           /   \
 *         2      3
 *       /  \    /
 *     4     5  8
 */

void printKDistant(TreeNode *root , int k){
    if(root == NULL)
        return;

    if( k == 0 ){
        cout << root->val << " ";
        return ;
    }
    else {
        printKDistant( root->left, k - 1 ) ;
        printKDistant( root->right, k - 1 ) ;
    }

    return;
}

// Iterative | BFS using Queue
//
bool printKDistantI(TreeNode* root, int klevel) {
    queue<TreeNode*> q;
    int level = 1;
    bool flag = false;
    q.push(root);

    // extra NULL is pushed to keep track of all the nodes to be pushed before
    // level is incremented by 1
    q.push(NULL);
    while (!q.empty()) {
        TreeNode* temp = q.front();

        // print when level is equal to k
        if (level == klevel && temp != NULL) {
            flag = true;
            cout << temp->val << " ";
        }
        q.pop();

        if (temp == NULL) {
            if (q.front())
                q.push(NULL);

            level += 1;

            // break the loop if level exceeds the given level number
            if (level > klevel)
                break;
        }
        else {
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
    cout << endl;

    return flag;
}