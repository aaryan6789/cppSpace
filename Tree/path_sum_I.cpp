
#include "_tree.h"

/* LeetCode 112
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * Note: A leaf is a node with no children.
 * Example: Given the below binary tree and sum = 22,
 *
 *		    5
 *		   / \
 *		  4   8
 *		 /   / \
 *		11  13  4
 *	   /  \      \
 *	  7    2      1
 *
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

/* Algorithm:
 * 1. Start from root and recursively check for the sum
 * 2. Calculate the Sub Sum
 * 3. Check for the SubSum in the Left Sub Tree
 * 4. Check for the SubSum in the right Sub Tree
 */
// Using Recursion
bool hasPathSum(TreeNode* root, int sum) {
	if(root == NULL){
		return false;
	}

	int subSum = sum - root->val;
	if(root->left == NULL && root->right == NULL){
		return subSum == 0;
	}

	return hasPathSum(root->left, subSum) || hasPathSum(root->right, subSum);

}


/*** level-bfs-iterative solution  ***/
bool hasPathSumI(TreeNode* root, int sum){
	if(root==NULL)  return false;
	
	queue<TreeNode*> q;
	q.push(root);
	while(q.size()>0){
		TreeNode* node=q.front();
		q.pop();
		if(node->left==NULL && node->right==NULL){
			if(node->val==sum)  
				return true;
		}

		if(node->left){
			node->left->val+=node->val;
			q.push(node->left);
		}
		
		if(node->right){
			node->right->val+=node->val;
			q.push(node->right);
		}
	}
	return false;
}
