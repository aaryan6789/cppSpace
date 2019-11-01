#include "_lc_linked_list.h"


/** LeetCode M | CTCI M
 *
 * Partition List
 * Given a linked list and a value x,
 * partition it such that all nodes less than x come before nodes
 * greater than or equal to x.
 *
 * NOTE: You should preserve the original relative order of the nodes in each
 * of the two partitions.
 *
 * Example:
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 */

/**
 *  1. Create 2 different Linked Lists: smaller and greater
 * 		1. For elements less then value X		--> on smaller
 * 		2. For elements more than value X		--> on greater
 * 2. Iterate through the list,
 * 		insert the element in the head if node->data < x
 * 		insert the element in the tail if node->data > x
 * 3. Once we reach to the end of the list, merge the 2 lists
 */
ListNode* partition(ListNode* head, int x) {
    if(!head){
        return NULL;
    }

    ListNode* smallerHead = NULL;
    ListNode* smallerTail = NULL;
    ListNode* greaterHead = NULL;
    ListNode* greaterTail = NULL;

    ListNode* current = head;

    while(current != NULL){
        if(current->val < x){
            if(smallerHead == NULL){
                smallerHead = smallerTail = current;
            }
            else{
                smallerTail->next = current;
                smallerTail = smallerTail->next;
            }
        }
        else{
            if(greaterHead == NULL){
                greaterHead = greaterTail = current;
            }
            else{
                greaterTail->next = current;
                greaterTail = greaterTail->next;
            }
        }
        current = current->next;
    }

    // End the LINKED LIST
    if(greaterTail != NULL)
        greaterTail->next = NULL;

    if(smallerHead == NULL){
        return greaterHead;
    }
    else {
        smallerTail->next = greaterHead;
        return smallerHead;
    }
}