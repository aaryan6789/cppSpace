#include "_tree.h"

/* LeetCode E | CTCI | AMAZON
 *
 * Given an array where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more than 1.
 *
 * Example:
 * Given the sorted array: [-10,-3,0,5,9],
 *
 * One possible answer is: [0,-3,9,-10,null,5], which represents the
 * following height balanced BST:
 *
 *       0
 *      / \
 *    -3   9
 *    /   /
 *  -10  5
 */

TreeNode* makeBST(const vector<int>& nums, int l, int h){
    if(l > h)
        return NULL;

    int mid = l+ (h-l)/2;
    int val = nums[mid];

    // Make a new TreeNode of the val equal to the mid of the array
    TreeNode *root = new TreeNode(val);

    root->left = makeBST(nums, l, mid-1);
    root->right = makeBST(nums, mid+1, h);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return makeBST(nums, 0, nums.size()-1);
}