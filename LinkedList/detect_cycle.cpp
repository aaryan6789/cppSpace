#include "_lc_linked_list.h"

/**
 * Given a linked list, determine if it has a cycle in it.
 * To represent a cycle in the given linked list, we use an integer pos which
 * represents the position (0-indexed) in the linked list where tail connects to.
 * If pos is -1, then there is no cycle in the linked list.
 *
 * Example 1:
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the second node.
 *
 * Example 2:
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the first node.
 *
 * Example 3:
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 *
 * Follow up:
 * Can you solve it using O(1) (i.e. constant) memory?
 */
/**
 * Two Pointer Method: Floyd's Cycle Finding Algorithm
 * 1. Declare 2 pointers for traversing the LL
 * -- fast  --> increment by 2 nodes
 * -- slow  --> increment by 1 node
 * 2. If these 2 pointers meet at some point in then there definitely
 * there is a loop. If they dont then no loop.
 *
 * O(n) and 2 Extra Space
 * This concept can be extended for removing the loop too.
 */
bool hasCycle(ListNode *head) {
    if(head == NULL || head->next == NULL){
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }

    return false;
}


// Return the Node where the Cycle Starts
ListNode *detectCycle(ListNode *head) {
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    ListNode *slow=head, *fast=head;
    fast=fast->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=(fast->next)->next;
        slow=slow->next;
        if(slow==fast){
            break;
        }
    }

    slow = head;

    if(fast==NULL || fast->next==NULL){
        return NULL;
    }

    fast = fast->next;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }

    return slow;
}