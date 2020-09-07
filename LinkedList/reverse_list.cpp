#include "_lc_linked_list.h"

/**
 * CTCI | LEETCODE E
 * Reverse a Linked List
 *
 * Iterative Algorithm:
 * 1. Declare 3 pointers curr, prev and next.
 * 2. Prev becomes the new Head of the reversed list
 */

ListNode* reverseList(ListNode* head) {
    if(!head || !head->next){
        return head;
    }
    ListNode* current = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}