#include "_tree.h"

/*
Top view means when you look the tree from the top the nodes, what you will see will be called the top view of the tree. See the example below.
You only have to complete the function.
For example :

   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4
Top View : 1 -> 2 -> 5 -> 6
 */

void left_side(TreeNode *p){
    if(p) {
        left_side(p->left);
        cout << p->val << " ";
    }
}

void right_side(TreeNode *p){
    if(p) {
        cout << p->val << " ";
        right_side(p->right);
    }
}

void top_view_Recur(TreeNode * root){
    left_side(root->left);
    cout << root->val << " ";
    right_side(root->right);
}


vector<vector<int>> top_view(TreeNode* root) {cout << "Left View " << endl;
    cout << "Top View " << endl;
    
    vector<int> top{};
    // Base case
    if (!root)
        return vertOrder;

    // Create a map and store vertical oder in
    // map using function getVerticalOrder()
    map <int, vector<int>> m;
    int hd = 0;

    // Create queue to do level order traversal.
    // Every item of queue contains TreeNode and horizontal distance.
    queue<pair<TreeNode*, int> > que;
    que.push(make_pair(root, hd));

    while (!que.empty()){
        // pop from queue front
        pair<TreeNode *,int> temp = que.front();
        que.pop();
        hd = temp.second;
        TreeNode* TreeNode = temp.first;

        // insert this TreeNode's data in vector of hash
        m[hd].push_back(TreeNode->val);

        if (TreeNode->left != NULL)
            que.push(make_pair(TreeNode->left, hd-1));
        if (TreeNode->right != NULL)
            que.push(make_pair(TreeNode->right, hd+1));
    }

    // Traverse the map and push TreeNodes at every horigontal distance (hd)
    vector<int> level;
    for(auto kv : m){
        level = kv.second;
        top.push_back(level[0]);
    }

    return top;
}