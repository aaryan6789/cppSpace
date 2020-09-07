#include "_tree.h"
/**
297. Serialize and Deserialize Binary Tree | LeetCode Hard

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 */

// Using Pre Order Traversal + Marker for Null Nodes

#include <string>
using namespace std;

// class Codec {
// public:
//     void encode(TreeNode* root, string& file){
//         if(!root){
//             file.append("# ");
//             return;
//         }
        
//         file.append(to_string(root->val) + ' ');
//         encode(root->left, file);
//         encode(root->right, file);
//     }
    
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         string file = "";    
//         if(!root)
//             return file;
        
//         encode(root, file);
//         return file;
//     }

//     TreeNode* decode(istringstream& file){
//         string val;
//         // file >> val;
//         if (val == "#") {
//             return nullptr;
//         }
//         else {
//             cout << val << endl;
//             TreeNode* root = new TreeNode(stoi(val));
//             root->left = decode(file);
//             root->right = decode(file);
//             return root;
//         }
//     }
    
    
//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         if(data.size() == 0){
//             return nullptr;
//         }
//         // istringstream file(data);
//         TreeNode* root = this->decode(file);
//         return root;
//     }
// };

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));