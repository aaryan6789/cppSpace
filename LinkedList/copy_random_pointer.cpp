#include "_lc_linked_list.h"

/**
 * A linked list is given such that each node contains an additional 
 * random pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * The Linked List is represented in the input/output as a list of n nodes. 
 * Each node is represented as a pair of [val, random_index] where:
 * - val: an integer representing Node.val
 * - random_index: the index of the node (range from 0 to n-1) where 
 * random pointer points to, or null if it does not point to any node.
 * 
 * Example 1:
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 * Example 2:
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 * 
 * Example 3:
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 * 
 * Example 4:
 * Input: head = []
 * Output: []
 * Explanation: Given linked list is empty (null pointer), so return null.
 *  
 * 
 * Constraints:
 * -10000 <= Node.val <= 10000
 * Node.random is null or pointing to a node in the linked list.
 * Number of Nodes will not exceed 1000.
 */


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};


/**
 * Method 1 : use Hashing. Below is algorithm.
1. Traverse the original linked list and make a copy in terms of data.
2. Make a hash map of key value pair with original linked list node and copied linked list node.
3. Traverse the original linked list again and using the hash map adjust the next and random reference of cloned linked list nodes.
*/
Node* copyRandomList(Node* head) {
    
    if(!head)
        return NULL;
    
    // Initialize two references, one with original list's head
    Node* orig = head;
    Node* clone = NULL;
    
    // Hash map which contains node to node mapping of original  
    // and clone linked list.
    unordered_map<Node* , Node*> map;
    
    // Traverse the original list and 
    // make a copy of that in the clone linked list.
    while(orig != NULL){
        clone = new Node();
        clone->val = orig->val;
        map[orig] = clone;
        orig = orig->next;
    }
    
    orig = head;
    // Traversal of original list again to adjust the next and random  
    // references of clone list using hash map.
    while(orig != NULL){
        clone = map[orig];
        clone->next = map[orig->next];
        clone->random = map[orig->random];
        
        orig = orig->next;
    }
    
    return map[head];
}
