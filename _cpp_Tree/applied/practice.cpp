#include "../_tree.h"
#include <map>

bool p_isSubtree(TreeNode* S, TreeNode* T){
    if(S == NULL){
        return false;
    }

    if(T == NULL){
        return true;
    }

    return false;
}


// Iterative
bool p_isSymmetric(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(root);

    while(!q.empty()){
        TreeNode* t1 = q.front();   q.pop();
        TreeNode* t2 = q.front();   q.pop();

        if(t1->val != t2->val)
            return false;

        if(!t1 && !t2)
            continue;

        q.push(t1->left);
        q.push(t2->right);

        q.push(t1->right);
        q.push(t2->left);
    }
    return true;
}


bool p_hasPathSum(TreeNode* root, int sum){
    if(!root){
        return (sum == 0);
    }

    int subSum = sum - root->val;
    if(!root->left && !root->right && subSum == 0){
        return true;
    }

    bool ans = false;
    if(root->left){
        ans = ans || p_hasPathSum(root->left, subSum);
    }

    if(root->right){
        ans = ans || p_hasPathSum(root->right, subSum);
    }

    return ans;
}

vector<int> p_topView(TreeNode* root){
    cout << "Top view " << endl;
    map<int, int> map;

    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<TreeNode*, int> pt = q.front();
        int hd = pt.second;
        TreeNode* temp = pt.first;
        q.pop();

        if(map.find(hd) == map.end()){
            map[hd] = temp->val;
        }

        if(temp->left)
            q.push(make_pair(temp->left, hd-1));

        if(temp->right)
            q.push(make_pair(temp->right, hd+1));
    }

    vector<int> topView;
    for(auto kv : map){
        topView.push_back(kv.second);
    }

    return topView;
}




vector<vector<int>> p_verticalOrder(TreeNode* root){
    cout << "Vertical Order Traversal" << endl;
    vector<vector<int>> vrt{};
    map<int, vector<int>> map;

    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<TreeNode*, int> pt = q.front();
        int hd = pt.second;
        TreeNode* temp = pt.first;
        q.pop();

        map[hd].push_back(temp->val);

        if(temp->left)
            q.push(make_pair(temp->left, hd-1));

        if(temp->right)
            q.push(make_pair(temp->right, hd+1));
    }

    for(auto kv : map){
        cout << kv.first << " ";
        for(auto& i : kv.second){
            cout << i << " " ;
        }
        cout << endl;

        vrt.push_back(kv.second);
    }

    return vrt;
}

vector<vector<int>> p_zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> zigzag{};

    stack<TreeNode*> odd;     // Stack for Odd level 1, 3 ,5
    stack<TreeNode*> even;    // Stack for Even level 2, 4 ,6

    vector<int> level{};
    odd.push(root);

    while(!odd.empty() || !even.empty()){
        while(!odd.empty()){
            TreeNode* temp = odd.top();
            odd.pop();
            level.push_back(temp->val);

            if(temp->left){
                even.push(temp->left);
            }
            if(temp->right){
                even.push(temp->right);
            }
        }
        zigzag.push_back(level);
        level.clear();
        while(!even.empty()){
            TreeNode* temp = even.top();
            even.pop();
            level.push_back(temp->val);

            if(temp->right){
                odd.push(temp->right);
            }
            if(temp->left){
                odd.push(temp->left);
            }


        }
        zigzag.push_back(level);
        level.clear();
    }

    return zigzag;

}

vector<int> p_averageOfLevels(TreeNode* root){
    queue<TreeNode* > q;
    q.push(root);
    vector<int> average;
    while(!q.empty()){
        int nodeCount = q.size();
        int levelSum = 0;
        int count = nodeCount;

        while(nodeCount){
            if(nodeCount == 0){
                break;
            }

            TreeNode* temp = q.front();
            q.pop();

            levelSum += temp->val;
            // cout << "LevelSum = " << levelSum << endl;

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }

            nodeCount--;
        }
        cout << "LevelSum = " << levelSum << endl;
        average.push_back(levelSum/count);

    }

    return average;
}

vector<vector<int>> p_levelOrderTraversalLine(TreeNode* root){
    queue<TreeNode* > q;
    q.push(root);
    vector<vector<int>> levels;
    while(!q.empty()){
        int nodeCount = q.size();
        vector<int> level;

        while(nodeCount){
            if(nodeCount == 0){
                break;
            }

            TreeNode* temp = q.front();
            q.pop();

            level.push_back(temp->val);

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }

            nodeCount--;
        }

        levels.push_back(level);

    }

    return levels;
}


vector<int> p_levelOrderTraversal(TreeNode* root){
    queue<TreeNode* > q;
    q.push(root);
    vector<int> level;

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        level.push_back(temp->val);

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }

    return level;
}

void _fillLeaves(TreeNode* root, vector<int>& lvs){
    if(!root){
        return;
    }

    if(!root->left && !root->right){
        lvs.push_back(root->val);
    }

    _fillLeaves(root->left, lvs);
    _fillLeaves(root->right, lvs);
}

bool p_leafSimilar(TreeNode* root1, TreeNode* root2){
    vector<int> lvs1;
    vector<int> lvs2;

    _fillLeaves(root1, lvs1);
    _fillLeaves(root2, lvs2);

    if(lvs1 == lvs2){
        return true;
    }
    else{
        return false;
    }
}

int p_numLeafNodesI(TreeNode* root){
    std::queue<TreeNode*> q;
    int count = 0;
    q.push(root);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp->left == NULL && temp->right == NULL){
            count++;
        }

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }

    cout << "Num of Leaf Nodes in Tree " << root->val << " is " << count << endl;
    return count;
}

int p_numLeafNodes(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    return p_numLeafNodes(root->left) + p_numLeafNodes(root->right);
}

int p_sizeTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + p_sizeTree(root->left) + p_sizeTree(root->right);
    }
}

int p_maxDepth(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int lDepth = p_maxDepth(root->left);
    int rDepth = p_maxDepth(root->right);

    return std::max(lDepth, rDepth) + 1;
}


int main(){
    /**        root
     *          10
     *        /   \
     *      20     30
     *    /   \      \
     *  40     50     60
     *               /  \
     *             70   80
     */
    TreeNode* root = new TreeNode(10);
    TreeNode left1(20);
    TreeNode right1(30);
    TreeNode* left2 = new TreeNode(40);
    TreeNode* right2 = new TreeNode(50);
    TreeNode* right3 = new TreeNode(60);
    TreeNode* right4 = new TreeNode(80);
    TreeNode* left4 = new TreeNode(70);
    root->left = &left1;
    root->right = &right1;
    root->left->left = left2;
    root->left->right = right2;
    root->right = &right1;
    right3->left = left4;
    right3->right = right4;
    root->right->right = right3;


    cout << "Size Of the Tree R = ";
    cout << p_sizeTree(root) << endl;

    cout << "Max Depth of the Tree R = ";
    cout << p_maxDepth(root) << endl;

    cout << "Num of Leaf Nodes in Tree R = ";
    cout << p_numLeafNodes(root) << endl;

    p_numLeafNodesI(root);

    cout << p_leafSimilar(root, root) << endl;

    vector<int> lev = p_levelOrderTraversal(root);
    for(auto& item : lev){
        cout << item << " ";
    }
    cout << endl;

    vector<vector<int>> levs = p_levelOrderTraversalLine(root);

    for(auto& row : levs){
        for(auto& col : row){
            cout << col << " ";
        }
        cout << endl;
    }

    vector<int> avg = p_averageOfLevels(root);
    for(auto& item : avg){
        cout << item << " ";
    }
    cout << endl;

    vector<vector<int>> zz = p_zigzagLevelOrder(root);

    for(auto& row : zz){
        for(auto& col : row){
            cout << col << " ";
        }
        cout << endl;
    }

    vector<vector<int>> vrt = p_verticalOrder(root);

    for(auto& row : vrt){
        for(auto& col : row){
            cout << col << " ";
        }
        cout << endl;
    }

    vector<int> tv = p_topView(root);
    for(auto& item : tv){
        cout << item << " ";
    }
    cout << endl;

    cout << "Tree has path sum " << p_hasPathSum(root, 70) << endl;

    cout << "Is tree Symmetric = " << p_isSymmetric(root) << endl;


    return 0;
}