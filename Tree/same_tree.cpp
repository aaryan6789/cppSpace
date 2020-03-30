#include "_tree.h"

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL)
        return true;

    if(p == NULL || q == NULL)
        return false;

    if(p->val != q->val)
        return false;


    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// BFS + queue
bool isSameTree2(TreeNode* p, TreeNode* q) {
    queue<pair<TreeNode*, TreeNode*>> myQueue;
    myQueue.push(make_pair(p, q));
    while (!myQueue.empty()) {
        p = myQueue.front().first;
        q = myQueue.front().second;

        if(!p ^ !q || (p && q && p->val != q->val))
            break;
        myQueue.pop();

        if(p && q) {
            myQueue.push({p->left, q->left});
            myQueue.push({p->right, q->right});
        }
    }
    return myQueue.empty();
}

// DFS + stack
bool isSameTree3(TreeNode* p, TreeNode* q) {
    stack<pair<TreeNode*, TreeNode* >> myStack;
    myStack.push(pair<TreeNode*, TreeNode*>(p, q));
    while (!myStack.empty()) {
        p = myStack.top().first;
        q = myStack.top().second;
        if (!p ^ !q || (p && q && p->val != q->val))
            break;
        myStack.pop();
        if (p && q) {
            myStack.push(pair<TreeNode*, TreeNode*> (p->right, q->right));
            myStack.push(pair<TreeNode*, TreeNode*> (p->left, q->left));
        }
    }
    return myStack.empty();
}