
#include "_tree.h"

int max(int a, int b){
	if(a>=b)
		return a;
	else
		return b;
}

int diameter(struct TreeNode* root){
	if(root == NULL)
		return 0;

	int lheight = maxDepthR(root->left);
	int rheight = maxDepthR(root->right);

	int ldia = diameter(root->left);
	int rdia = diameter(root->right);

	int maxDia = (ldia>rdia ? ldia:rdia);

	int ret = max(maxDia, lheight+rheight+1);
	//printf("Diameter of Tree:%d is %d\n", root->data, ret);
	return ret;
}

/* Function to find height of a tree */
int height2 (struct TreeNode* root, int* ans){
	if (root == NULL){
		return 0;
	}

	int left_height = height2(root->left, ans);
	int right_height = height2(root->right, ans);

	// update the ans value, because diameter of a tree is nothing but maximum
	// value of (left_height + right_height + 1) for each node
	*ans = max((*ans), (1 + left_height + right_height));

	return 1 + max(left_height, right_height);
}

/* Computes the diameter of binary tree with given root. */
int diameter2(struct TreeNode* root){
	if (root == NULL)
		return 0;
	int ans = INT_MIN; // This will store the final answer
	int height_of_tree = height2(root, &ans);

	return ans;
}
