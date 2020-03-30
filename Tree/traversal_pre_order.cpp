/* Traversal_preOrder.c  * Created on: May 25, 2018 * Author: Harsh */
#include "_tree.h"
using namespace std;

/* PreOrder Traversal of a Tree : Root, Left, Right */
void preOrderTraversalR(struct TreeNode* root, vector<int>& preOrder){
	preOrder.push_back(root->val);

	if(root->left)
		preOrderTraversalR(root->left, preOrder);

	if(root->right)
		preOrderTraversalR(root->right, preOrder);
}

vector<int> preOrderTraversalDFS(TreeNode* root) {
	vector<int> preOrder{};
	if(root == NULL)
		return preOrder;

	preOrderTraversalR(root, preOrder);
	return preOrder;

}



/* Iterative pre order Traversal
 * Using Stack
 *
 * Algorithm:
 * 1) Create an empty stack nodeStack and push root node to stack.
 * 2) Do following while nodeStack is not empty.
 * 		a) Pop an item from stack and print it.
 * 		b) Push right child of popped item to stack
 * 		c) Push left child of popped item to stack
 *
 * Right child is pushed before left child to make sure that left subtree is processed first.
 */
void preOrderTraversalPrint(struct TreeNode* root){
	cout << "PreOrder Traversal using Stack/ Iterative";
	if (root == NULL)
	       return;

	// Create an empty Stack
	stack<TreeNode*> st;
	st.push(root);

	while(!st.empty()){
		TreeNode* temp = st.top();
		st.pop();

		cout << temp->val << " ";

		// Push the right child first on the stack  <--- Pay attention here
		if(temp->right)
			st.push(temp->right);

		if(temp->left)
			st.push(temp->left);
	}
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> preOrder{};
	if (root == NULL)
		return preOrder;

	// Create an empty Stack
	stack<TreeNode*> st;
	st.push(root);

	while(!st.empty()){
		TreeNode* temp = st.top();
		st.pop();

		preOrder.emplace_back(temp->val);

		// Push the right child first on the stack  <--- Pay attention here
		if(temp->right)
			st.push(temp->right);

		if(temp->left)
			st.push(temp->left);
	}
	return preOrder;
}
