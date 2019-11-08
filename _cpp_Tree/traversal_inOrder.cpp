/* in_order_traversal.c  * Created on: May 30, 2018 * Author: Harsh */
#include "_tree.h"
using namespace std;

/* InOrder Traversal of a Tree : Left, Root, Right
 * Since the Terminating condition is when root is NULL.
 * It will have extra function Calls for leaf nodes because the function is
 * called for left and right subtree even when both are NULL.
 *
 * If we check the left and right Sub Tree before making a function call it
 * will reduce the number of function call overhead.
 */
void inOrderTraversalR2(TreeNode* root){
	// Base Case / Terminating Condition
	if(root == NULL)
		return;

	if(root->left != NULL)
		inOrderTraversalR2(root->left);

	cout << " " << root->val;

	if(root->right != NULL)
		inOrderTraversalR2(root->right);
}


/// LeetCode Format
void inOrderTraversalR(TreeNode* root, vector<int>& inorder){
	if(root->left)
		inOrderTraversalR(root->left, inorder);

	inorder.push_back(root->val);

	if(root->right)
		inOrderTraversalR(root->right, inorder);
}

vector<int> inorderTraversalDFS(TreeNode* root) {
	vector<int> inorder{};
	if(root == NULL)
		return inorder;

	inOrderTraversalR(root, inorder);
	return inorder;

}

#include <stack>
/* Iterative InOrder Traversal
 * Using Stack
 *
 * 1) Create an empty stack S.
 * 2) Initialize current node as root
 * 3) Push the current node to S and set current = current->left until current is NULL
 * 4) If current is NULL and stack is not empty then
 *   a) Pop the top item from stack.
 *   b) Print the popped item, set current = popped_item->right
 *   c) Go to step 3.
 * 5) If current is NULL and stack is empty then we are done.
 */
void inOrderTraversalI(TreeNode* root){
	cout << "\nInOrder Traversal using Stack/ Iterative\n";
	/* set current to root of binary tree */
	TreeNode* current = root;
	vector<int> inorder{};

	// Initialize Stack
	stack<TreeNode*> st;
	int done = 0;

	while(!done){
		// If current is not Null then push it on the Stack
		if(current != NULL){
			st.push(current);
			current = current->left;
		}
		// If current is NULL then Pop from the stack and Print
		else{
			if(!st.empty()){
				current = st.top();
				st.pop();
				cout << " " << current->val ;
				inorder.emplace_back(current->val);

				// Set the current to the right node of the current
				current = current->right;
			}
			else{
				done = 1;
			}
		}
	}
}

/**
 * Inorder Traversal - Left, Root, Right
 * Prints the entire left SubTree then root and then right SubTree
 */

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> inorder{};
	if (root == NULL) {
		return inorder;
	}

	stack<TreeNode*> s;
	s.push(root);

	while(!s.empty()) {
		auto cur = s.top();
		// Go to the left Sub Tree
		if (cur->left == NULL) {
			inorder.emplace_back(cur->val);
			s.pop();
			if (cur->right != NULL) {
				s.push(cur->right);
			}
		}
		else {
			s.push(cur->left);
			cur->left = NULL;
		}
	}
	return inorder;
}


void inOrderStack(TreeNode* root){
	cout << "\n Simple Inorder Traversal by Stack\n";
	if (root == NULL)
		return;

	// Create a Stack
	stack<TreeNode*> st;

	while(true){
		// If the root i snot null then push into the stack
		if(root != NULL){
			st.push(root);
			root = root->left;
		}
		// Goes in else if and only if root is null i.e it reached to the leftmost Node of the tree.
		else {
			// Break from the while loop when the Stack becomes empty
			if(st.empty()){
				break;
			}
			else{
				// Now pop from the Stack and give it to root
				root = st.top();
				st.pop();
				cout << " " << root->val;
				root = root->right;		// Since we have pushed all the left nodes so set the root to right
			}
		}
	}
}



