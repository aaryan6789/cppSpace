
#include "_tree.h"




int DFS(TreeNode* root, int& ans){
	if(!root) return 0;
	
	int l_h = DFS(root->left, ans);
	int r_h = DFS(root->right, ans);

	// update the ans value, because diameter of a tree is nothing but maximum
	// value of (left_height + right_height + 1) for each node
	ans = max(ans, (l_h + r_h));
	
	return max(l_h, r_h) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
	if(!root) return 0;
	
	int ans = 0;
	DFS(root, ans);
	return ans;
}




int max(int a, int b){
	if(a>=b)
		return a;
	else
		return b;
}

int diameter(struct TreeNode* root){
	if(root == NULL)
		return 0;

	int lheight = maxDepth(root->left);
	int rheight = maxDepth(root->right);

	int ldia = diameter(root->left);
	int rdia = diameter(root->right);

	int maxDia = (ldia>rdia ? ldia:rdia);

	int ret = max(maxDia, lheight+rheight+1);
	//printf("Diameter of Tree:%d is %d\n", root->data, ret);
	return ret;
}