#include "_n_ary_tree.h"
#include <algorithm>

using Node = NAry_Node;


// Max Depth
int _n_ary_maxDepth(NAry_Node* root) {
    if (root == nullptr) 
        return 0;
    int depth = 0;
    for (auto child : root->children) 
        depth = max(depth, _n_ary_maxDepth(child));

    return 1 + depth;
}


// ---------------------------------------------------------
/**
 * Given an N-ary tree, find the subtree with the maximum average. Return the root of the subtree.
A subtree of a tree is the node which have at least 1 child plus all its descendants. The average value of a subtree is the sum of its values, divided by the number of nodes.

Example 1:

Input:
		 20
	   /   \
	 12     18
  /  |  \   / \
11   2   3 15  8

Output: 18
Explanation:
There are 3 nodes which have children in this tree:
12 => (11 + 2 + 3 + 12) / 4 = 7
18 => (18 + 15 + 8) / 3 = 13.67
20 => (12 + 11 + 2 + 3 + 18 + 15 + 8 + 20) / 8 = 11.125

18 has the maximum average so output 18.
Similar questions:

https://leetcode.com/problems/maximum-average-subtree
*/

double maxAvg = 0.00;
NAry_Node* maxNode = nullptr;
pair<int, int> dfs(NAry_Node* root);

int _n_ary_maximumAveragetree(NAry_Node* root) {
    double maxAvg = 0;      // MaxAvergae 
    int count = 0;          // Count of nodes
    
    dfs(root);
    return maxNode->val;
}

pair<int, int> dfs(NAry_Node* root){
    if(!root) 
        return {0, 0};

    int currSum = root->val;
    int count = 1;

    for( auto child : root->children){
        pair<int, int> sum_count = dfs(child);

        currSum = currSum + sum_count.first;
        count = count + sum_count.second;  
    }

    double currAvg = currSum/count;

    if(count > 1 && currAvg > maxAvg){
        maxAvg = currAvg;
        maxNode = root;
    }

    return {currSum, count};
}