#include "_tree.h"

#include <queue>
// Using Queue
int numLeafNodes(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);
    TreeNode* temp;
    int count = 0;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(!temp->left && !temp->right){
            count++;
        }

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }


    cout << "Leaf Nodes = " << count << endl;
    return count;
}