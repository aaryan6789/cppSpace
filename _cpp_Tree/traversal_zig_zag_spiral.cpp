
#include "_tree.h"
using namespace std;
/* LeetCode M 103 | CTCI
 * ZIG ZAG Traversal
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values.
 * (ie, from left to right, then right to left for the next level and alternate
 * between).
 *
 * For example: Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
 *
 * return its zigzag level order traversal as:
 *
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */
/* Algorithm: Using 2 stacks
 * 1. Use one stack for printing from left to right and
 *    other stack for printing from right to left.
 * 2. In every iteration, we have nodes of one level in one of the stacks.
 * 3. Print the nodes, and push nodes of next level in other stack.
 */

// Using 2 Stacks
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> zigzag{};
	if(!root)
		return zigzag;

	// Create 2 Stacks
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	TreeNode* temp;
	s1.push(root);

	vector<int> level;
	while(!s1.empty() || !s2.empty()) {
		while(!s1.empty()){
			temp = s1.top();
			s1.pop();
			level.emplace_back(temp->val);

			if(temp->left)
				s2.push(temp->left);

			if(temp->right)
				s2.push(temp->right);
		}
		zigzag.emplace_back(level);
		level.clear();

		while(!s2.empty()){
			temp = s2.top();
			s2.pop();
			level.emplace_back(temp->val);

			if(temp->right)
				s1.push(temp->right);

			if(temp->left)
				s1.push(temp->left);
		}
		if(level.size() != 0){
			zigzag.emplace_back(level);
		}
		level.clear();
	}

	return zigzag;
}


void printZigZagTraversal(struct TreeNode* root){
	if(!root)
		return ;

	// Create 2 Stacks
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	TreeNode* temp;
	s1.push(root);

	vector<int> level;
	while(!s1.empty() || !s2.empty()) {
		while(!s1.empty()){
			temp = s1.top();
			s1.pop();
			level.emplace_back(temp->val);

			if(temp->left)
				s2.push(temp->left);

			if(temp->right)
				s2.push(temp->right);
		}
		cout << endl;

		while(!s2.empty()){
			temp = s2.top();
			s2.pop();
			level.emplace_back(temp->val);

			if(temp->right)
				s1.push(temp->right);

			if(temp->left)
				s1.push(temp->left);
		}
		cout << endl;

	}
}


vector<vector<int>> zigzagLevelOrder2(TreeNode* root) {
	vector <vector <int>> result;
	if (!root) {
		return result;
	}
	stack <TreeNode *> even, odd;
	even.emplace(root);

	while (!even.empty() || !odd.empty()) {
		vector <int> level;
		if (odd.empty()) {
			while (!even.empty()) {
				auto curr = even.top();
				even.pop();
				level.emplace_back(curr->val);
				if (curr->left) {
					odd.emplace(curr->left);
				}
				if (curr->right) {
					odd.emplace(curr->right);
				}
			}
		} else {
			while (!odd.empty()) {
				auto curr = odd.top();
				odd.pop();
				level.emplace_back(curr->val);
				if (curr->right) {
					even.emplace(curr->right);
				}
				if (curr->left) {
					even.emplace(curr->left);
				}
			}
		}
		result.emplace_back(level);
	}
	return result;
}
