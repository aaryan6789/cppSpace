#include "_lc_linked_list.h"
/* LeetCode | M
Given a linked list, swap every two adjacent nodes and return its head.
Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:
1. Your algorithm should use only constant extra space.
2. You may not modify the values in the list's nodes, only nodes itself may be changed.
*/

ListNode* swapPairs(ListNode* head) {
    // Return early if no nodes or 1 node
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* first = head;             // First Node
    ListNode* second = head->next;      // Second Node
    head= second;                       // Will be the new Head

    while(second != NULL){
        ListNode* temp = second->next;      // Cache the next to second node

        second->next = first;               // Make the Swap link

        if(temp == NULL || temp->next == NULL){
            first->next = temp;
            return head;
        }

        first->next = temp->next;
        first = temp;
        second = first->next;

    }

    return head;

}

// Recursive Solution
ListNode* swapPairsR(ListNode* head) {
    if (!head || !(head->next))
        return head;
    ListNode *res = head->next;
    head->next = swapPairs(res->next);
    res->next = head;
    return res;
}