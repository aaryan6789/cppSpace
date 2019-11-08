#include "_tree.h"

#include <map>
/** LeetCode M | 314 | Vertical Order Traversal
 *
 * Given a binary tree, return the vertical order traversal of its nodes' values.
 *  (ie, from top to bottom, column by column).
 *
 * If two nodes are in the same row and column, the order should be from left to
 * right.
 *
 * Examples 1:
 * Input: [3,9,20,null,null,15,7]
 *
 *    3
 *   /\
 *  /  \
 *  9  20
 *     /\
 *    /  \
 *   15   7
 *
 * Output:
 * [
 *   [9],
 *   [3,15],
 *   [20],
 *   [7]
 * ]
 *
 * Examples 2:
 * Input: [3,9,8,4,0,1,7]
 *
 *      3
 *     /\
 *    /  \
 *    9   8
 *   /\  /\
 *  /  \/  \
 *  4  01   7
 *
 * Output:
 * [
 *   [4],
 *   [9],
 *   [3,0,1],
 *   [8],
 *   [7]
 * ]
 *
 * Examples 3:
 * Input: [3,9,8,4,0,1,7,null,null,null,2,5]
 * (0's right child is 2 and 1's left child is 5)
 *
 *      3
 *     /\
 *    /  \
 *    9   8
 *   /\  /\
 *  /  \/  \
 *  4  01   7
 *     /\
 *    /  \
 *    5   2
 *
 * Output:
 *
 * [
 *   [4],
 *   [9,5],
 *   [3,0,1],
 *   [8,2],
 *   [7]
 * ]
 */

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> vertOrder{};
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
        // sort(level.begin(), level.end());
        vertOrder.push_back(level);
    }

    return vertOrder;
}

void printVerticalOrder(TreeNode* root) {
    // Base case
    if (!root)
        return;

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

    // Traverse the map and print TreeNodes at every horigontal distance (hd)
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++){
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}