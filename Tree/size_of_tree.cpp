/* calculate_size.c * * Created on: May 20, 2018 *      Author: Harsh  */
#include "_tree.h"
using namespace std;
/* Calculate the Size of the Tree
 * Size of the Tree is the number of elements present in the tree
 *
 * Method1: Using Recursion
 * size of tree = size of left Subtree + 1 + size of right Subtree
 */
int size(TreeNode* root){
	if(!root)
		return 0;

	int ret = size(root->left) + 1 + size(root->right);
	cout << "Size of the Binary Tree:Root= " << root->val << " is " << ret << endl;;
	return ret;
}

#include <queue>
/**
 * Using Queue
 */
int size2(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int count = 0;
    queue<TreeNode*> q;
    q.push(root);

    TreeNode* temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        count++;

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }

	cout << "Size of the Tree = " << count << endl;
	return count;
}
