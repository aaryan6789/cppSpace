#include "_tree.h"

/**
 * LeetCode E | 101
 * Given a binary tree, check whether it is a mirror of itself
 * (ie, symmetric around its center).
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 *
 *
 * But the following [1,2,2,null,3,null,3] is not:
 *
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 *
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 */
// Iterative Solution - Using BFS
// 1. Make a Queue
// 2. Push root 2 times
// 3. Each 2 Consecutive nodes should have the same data
//    The algorithm works similarly to BFS, with some key differences.
//    Each time, two nodes are extracted and their values compared.
//    Then, the right and left children of the two nodes are inserted in the queue in opposite order.
//    The algorithm is done when either the queue is empty, or we detect that the tree is not symmetric (
//    i.e. we pull out two consecutive nodes from the queue that are unequal).
bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(root);

    while(!q.empty()){
        TreeNode* t1 = q.front();
        q.pop();

        TreeNode* t2 = q.front();
        q.pop();

        if(t1 == NULL && t2 == NULL){
            continue;
        }

        if(t1 == NULL || t2 == NULL){
            return false;
        }

        if(t1->val != t2->val){
            return false;
        }

        q.push(t1->left);
        q.push(t2->right);

        q.push(t1->right);
        q.push(t2->left);
    }

    return true;
}
// Returns true if trees with roots as root1 and root2 are mirror
bool isMirror(TreeNode *root1, TreeNode *root2) {
    // If both trees are empty, then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    // For 2 trees to be mirror images, the following 3 conditions must be true
    // 1 - Their root node's key must be same
    // 2 - left subtree of left tree and right subtree
    //      of right tree have to be mirror images
    // 3 - right subtree of left tree and left subtree
    //      of right tree have to be mirror images
    if (root1 && root2 && root1->val == root2->val){
    	return  isMirror(root1->left, root2->right) &&
    			isMirror(root1->right, root2->left);
    }

    // if neither of above conditions is true then
    // root1 and root2 are not mirror images
    return false;
}

// Returns true if a tree is symmetric i.e. mirror image of itself
bool isSymmetricR(TreeNode* root) {
    // Check if tree is mirror of itself
    return isMirror(root, root);
}