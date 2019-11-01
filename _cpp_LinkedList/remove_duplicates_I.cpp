#include "_lc_linked_list.h"


/* LeetCode Easy
Given a sorted linked list, delete all duplicates such that each element appear only once.
Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
 */
ListNode* deleteDuplicates(ListNode* head) {
    if(!head)
        return head;

    ListNode* current = head;

    while(current != NULL && current->next != NULL){
        if(current->next->val == current->val){
            ListNode* next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else{
            current = current->next;
        }
    }

    return head;
}