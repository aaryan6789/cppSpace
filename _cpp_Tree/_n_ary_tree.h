
#include "_tree.h"

class NAry_Node {
public:
    int val;
    vector<NAry_Node*> children;

    NAry_Node() {}

    NAry_Node(int _val) {
        val = _val;
    }

    NAry_Node(int _val, vector<NAry_Node*> _children) {
        val = _val;
        children = _children;
    }
};