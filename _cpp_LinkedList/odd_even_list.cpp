/**
 * LeetCode Medium | CTCI | 328
 * Given a singly linked list, group all odd nodes together followed by the even
 * nodes. Please note here we are talking about the node number and not the
 * value in the nodes.
 *
 * You should try to do it in place.
 * The program should run in O(1) space complexity and O(nodes) time complexity.
 *
 * Example 1:
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 *
 * Example 2:
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 *
 * Note:
 * 1. The relative order inside both the even and odd groups should remain as it
 *    was in the input.
 * 2. The first node is considered odd, the second node even and so on ...
 */
#include "_lc_linked_list.h"
ListNode* oddEvenList(ListNode* head) {
    if(head == NULL){
        return head;
    }

    ListNode* oddHead = head;
    ListNode* even = head->next;        // even = evenTail
    ListNode* evenHead = even;          // Cache the evenHead for making the links later

    while(even != NULL && even->next != NULL){
        oddHead->next = even->next;
        oddHead = oddHead->next;
        even->next = oddHead->next;
        even = even->next;
    }

    oddHead->next = evenHead;
    return head;
}