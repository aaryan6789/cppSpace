#include "_tree.h"
/*
 * Given a Binary Tree:
 * 			1
 * 		   / \
 * 		  2   3
 * 		 / \
 * 		4   5
 * Level order traversal of the above tree is 1 2 3 4 5
 */

/* METHOD 1: Use Queue
 * Algorithm:
 * For each node, first the node is visited and then its child nodes are put in a FIFO queue.
 *
 * printLevelorder(tree)
 * 1) Create an empty queue q
 * 2) temp_node = root 			//start from root
 * 3) Loop while temp_node is not NULL
    a) print temp_node->val.
    b) Enqueue temp_node�s children (first left then right children) to q
    c) Dequeue a node from q and assign it�s value to temp_node
 */
void printlevelOrderTraversal(TreeNode* root){
	cout << "Level Order Traversal - Using Queue" << endl;
	if(!root)
		return;

	TreeNode* temp;
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){
		temp = q.front();
        q.pop();
		cout << temp->val;

		if(temp->left != NULL)
			q.push(temp->left);

		if(temp->right)
			q.push(temp->right);
	}

    cout << endl;
}


/* Level Order Traversal Line By Line
 * Given a binary tree, print level order traversal in a way that nodes of
 * all levels are printed in separate lines.
 */
void printlevelOrderTraversalLine(TreeNode* root){
	printf("Level Order Traversal - Line by Line\n");
	if(!root)
			return;

	TreeNode* temp;
	queue<TreeNode*> q;
	q.push(root);

	while(1){
		int nodeCount = q.size();
		if(nodeCount == 0)
			break;

		while(nodeCount>0){
			temp = q.front();
            q.pop();
			cout << temp->val << " ";

			if(temp->left != NULL)
				q.push(temp->left);

			if(temp->right)
				q.push(temp->right);

			nodeCount--;
		}
		cout << endl;
	}
}


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> levels{};
    if(!root)
        return levels;

    TreeNode* temp;
    queue<TreeNode*> q;
    q.push(root);
    vector<int> level{};
    while(1){
        int nodeCount = q.size();
        if(nodeCount == 0)
            break;

        while(nodeCount>0){
            temp = q.front();
            q.pop();
            level.push_back(temp->val);

            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);

            nodeCount--;
        }
        levels.push_back(level);
        level.clear();
    }
    return levels;
}

/* Level Order Traversal : Line by Line : Using 2 Queues
 * 1. Create 2 Queues
 * 2. Insert the 1st level in the first queue
 * 3. Print it while dequeuing from the 1st queue.
 * 4. Insert the left and right children into the second queue.
 * 5. Now start printing the second queue
 *    Before dequeuing from the second queue insert its left and right children
 *    to first queue.
 * 6. Continue this process until the queue becomes empty.
 */

/// Leetcode
vector<vector<int>> levelOrder1(TreeNode* root) {
    vector<vector<int>> levels{};
    if(!root){
        return levels;
    }

    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(root);
    TreeNode* temp;

    vector<int> level{};
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            temp = q1.front();
            level.push_back(temp->val);
            q1.pop();

            if(temp->left){
                q2.push(temp->left);
            }
            if(temp->right){
                q2.push(temp->right);
            }
        }
        levels.push_back(level);
        level.clear();
        while(!q2.empty()){
            temp = q2.front();
            level.push_back(temp->val);
            q2.pop();

            if(temp->left){
                q1.push(temp->left);
            }
            if(temp->right){
                q1.push(temp->right);
            }
        }
        if(level.size() != 0)
            levels.emplace_back(level);
        level.clear();
    }
    return levels;
}

