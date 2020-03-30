/* rotate_list_circularly.c  * Created on: Jul 17, 2018 * Author: Harsh */

#include "_lc_linked_list.h"
/** LeetCode | M | 61
 * Given a linked list,
 * rotate the list to the right by k places, where k is non-negative.
 *
 * Example 1:
 *
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 *
 * Example 2:
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
 *
 * Exaqmple 3:
 * I/P = 1->2->3
 * k = 200000000
 * O/p = 2->1->3
 *
 */

int length(ListNode* head) {
    int len = 0;
    while(head) {
        head = head->next;
        len++;
    }
    return len;
}

// Rotate a Linked List one by one
ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    // The following calculation is needed only when the value of K gets very large
    // Then the rotation doesnt need to be done again and again.
    int len = length(head);
    if(k>len)
        k = k%len;

    ListNode* last;
    ListNode* sec_last;
    ListNode* current = head;

    //one by one rotate by bringing the last node in the front
    while( k != 0){
        current = head;
        while(current->next != NULL){
            sec_last = current;
            current = current->next;
        }

        last = current;
        last->next = head;
        sec_last->next = NULL;
        head = last;
        k--;
    }
    return head;
}


ListNode* rotateRight2(ListNode* head, int k) {
    if (head == NULL || k == 0 || head->next == NULL)
        return head;

    int len = 1;
    ListNode *p1 = head;
    while(p1->next){
        len++;
        p1 = p1->next;
    }
    p1->next = head;

    k = k%len;
    for (int i = 0; i < (len-k); i++){
        p1 = p1->next;
    }

    ListNode *pNewHead = p1->next;

    p1->next = NULL;

    return pNewHead;

}
