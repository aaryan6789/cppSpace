#include "_tree.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        
        Node* prev = root;
        Node* cur = root;
        
        while(prev) {
            cout << "prev = " << prev->val;
            cur = prev;
            
            // Move in the same level until the nodes are there
            while(cur) {
                cout << "curr = " << cur->val << endl;
                
                // Make connections in the same parent
                if (cur->left) 
                    cur->left->next = cur->right;
                
                // Make connections between different parents
                if (cur->right && cur->next)
                    cur->right->next = cur->next->left;
                
                // Move to the next node in the same level
                cur = cur->next;
            }
            
            // Move to the next level
            prev = prev->left;
        }
        
        return root;
    }
    
    Node* connectR(Node* root) {
        if(!root)
            return nullptr;
        
        if(root->left)
            root->left->next = root->right;
        
        if(root->next && root->right)
            root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
        
        return root;
    }
    
    Node* connectLO(Node* root) {
        if(!root)
            return NULL;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            Node* temp = q.front(); q.pop();

            if(temp != NULL){
                // cout << temp->val << endl;
                temp->next = q.front();

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }
            else {
                if(!q.empty())
                    q.push(NULL);
            }
            
        }
        
        return root;
    }
};