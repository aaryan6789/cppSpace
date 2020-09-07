#include "_lc_linked_list.h"

/**
 * 203 LeetCode E | https://leetcode.com/problems/remove-linked-list-elements/
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example:
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 */
// Case 1 - When the val is in the head itself
// Case 2 - When the Val is in the middle of the List somewhere
// Case 3 - When the val is in the end
// To handle these 3 cases we can approach the problem 2 ways
// 1. Handle the middle ones first and then in the end, we can handle the front one
ListNode* removeElements(ListNode* head, int val) {
    if(!head)
        return NULL;

    ListNode* current = head;

    // Handle Case 2 and 3
    while(current->next != NULL){
        if(current->next->val == val){
            auto toFree = current->next;
            // cout << "current = " << current->val << endl;
            current->next = current->next->next;
            delete toFree;
        }
        else{
            current = current->next;
        }
    }

    // Handle Case 1
    if(head->val == val){
        auto toFree = head;
        head = head->next;
        delete toFree;
    }
    return head;
}

// Using a Double Pointer to the Head node
ListNode* removeElements1(ListNode* head, int val){
    ListNode** curr_ref = &head;

    while(*curr_ref){
        if((*curr_ref)->val == val)
            *curr_ref = (*curr_ref)->next;
        else
            curr_ref = &((*curr_ref)->next);
    }

    return head;
}