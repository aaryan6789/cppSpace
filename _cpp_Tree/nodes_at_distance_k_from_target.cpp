#include "_tree.h"

/**
 * LeetCode M | FB, LinkeIN, GooG
 * We are given a binary tree (with root node root), a target node, and an
 * integer value K.
 *
 * Return a list of the values of all nodes that have a distance K from the
 * target node.  The answer can be returned in any order.
 *
 * Example 1:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
 * Output: [7,4,1]
 *
 * Explanation:
 * The nodes that are a distance 2 from the target node (with value 5)
 * have values 7, 4, and 1.
 *
 * Note that the inputs "root" and "target" are actually TreeNodes.
 * The descriptions of the inputs above are just serializations of these objects.
 *
 * Note:
 * 1. The given tree is non-empty.
 * 2. Each node in the tree has unique values 0 <= node.val <= 500.
 * 3. The target node is a node in the tree.
 * 4. 0 <= K <= 1000.
 */

#include <unordered_map>
// Keep a Map of the treeNodes and there level
unordered_map<TreeNode* , int> map;

void printMap(unordered_map<TreeNode* , int>& map){
    for(auto & item : map){
        cout << item.first->val << " " << item.second << endl;
    }
    cout << endl;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    vector<int> res;

    find(root, target);
    printMap(map);
    cout << "map[" << root->val << "] " << map[root] << endl;
    dfs(root, target, K, map[root], res);
    return res;
}

// Find the Target Node and keep the map updated with their levels
// Starting from 0 at the target level
int find(TreeNode* root, TreeNode* target){
    if(!root)
        return -1;

    if(root == target){
        map[root] = 0;
        return 0;
    }

    // look for the target in left sub tree
    int left = find(root->left, target);
    if(left != -1){
        map[root] = left + 1;
        return left+1;
    }

    // Look for the target in the right subtree
    int right = find(root->right, target);
    if(right != -1){
        map[root] = right + 1;
        return right+1;
    }

    return -1;
}

void dfs(TreeNode* root, TreeNode* target, int K, int level, vector<int>& res){
    if(!root)
        return;

    cout << "DFS " << root->val << " " << level << endl;
    // look for the root/ node in the map an d get its level
    if(map.find(root) != map.end()){
        level = map[root];
        cout << "DFS map[" << root->val << "] " << map[root] << endl;
    }

    cout << "DFS " << root->val << " " << level << endl;
    if(level == K){
        res.push_back(root->val);
    }

    dfs(root->left, target, K, level+1, res);
    dfs(root->right, target, K, level+1, res);
}
