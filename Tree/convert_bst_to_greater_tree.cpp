#include "_tree.h"

/**
 * Leetcode E | AMZN
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of all
 *  keys greater than the original key in BST.
 *
 * Example:
 *
 * Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
 */

// Using Recursion
// Since in BST all the nodes on the right side of the root are greater
// We maintain a minor "global" state so each recursive call
// can access and modify the current total sum.
// Essentially, we ensure that the current node exists,
// recurse on the right subtree, visit the current node by updating
// its value and the total sum, and finally recurse on the left subtree.
// If we know that recursing on root->right properly updates the right subtree
// and that recursing on root->left properly updates the left subtree,
// then we are guaranteed to update all nodes with larger values before the current
// node and all nodes with smaller values after.

// Time Complexity = O(n)
// Space Complexity = O(n)
int sum = 0;
TreeNode* convertBST(TreeNode* root) {
    if(root != NULL){
        convertBST(root->right);
        sum = sum + root->val;
        root->val = sum;

        convertBST(root->left);
    }

    return root;
}


// Using Stack
/**
Intuition
If we don't want to use recursion, we can also perform a reverse in-order traversal via iteration and a literal stack to emulate the call stack.

Algorithm
One way to describe the iterative stack method is in terms of the intuitive recursive solution.
First, we initialize an empty stack and set the current node to the root.
Then, so long as there are unvisited nodes in the stack or node does not point
to null, we push all of the nodes along the path to the rightmost leaf onto the stack.
This is equivalent to always processing the right subtree first in the
recursive solution, and is crucial for the guarantee of visiting nodes in order
 of decreasing value. Next, we visit the node on the top of our stack, and
  consider its left subtree. This is just like visiting the current node before
  recursing on the left subtree in the recursive solution.
  Eventually, our stack is empty and node points to the left null child of the
  tree's minimum value node, so the loop terminates. */

TreeNode* convertBST2(TreeNode* root) {
    int sum = 0;
    TreeNode* temp = root;
    stack<TreeNode*> st;

    while(!st.empty() || temp != NULL){
        /* push all nodes up to (and including) this subtree's maximum on
            * the stack. */
        while(temp != NULL){
            st.push(temp);
            temp = temp->right;
        }

        temp = st.top();
        st.pop();
        sum = sum + temp->val;
        temp->val = sum;

        /* all nodes with values between the current and its parent lie in
            * the left subtree. */
        temp = temp->left;
    }

    return root;
}