#include "_lc_linked_list.h"

/** LeetCode M | 19 | https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * CTCI Hard
 * Given a linked list, remove the n-th node from the end of list and return its head.
 *
 * Example:
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end,
 * the linked list becomes 1->2->3->5.
 *
 * Note:
 * Given n will always be valid.
 *
 * Follow up:
 * Could you do this in one pass?
 */


// 2 pointer 1 Pass Solution + Dummy Pointer
// The first pointer advances the list by n+1 steps from the beginning,
// while the second pointer starts from the beginning of the list.
// Now, both pointers are exactly separated by n nodes apart.
// We maintain this constant gap by advancing both pointers together until the
// first pointer arrives past the last node.
// The second pointer will be pointing at the nth node counting from the last.
// We relink the next pointer of the node referenced by the second pointer to point
// to the node's next next node.
ListNode* removeNthFromEnd1(ListNode* head, int n) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* slow = dummy;
    ListNode* fast = dummy;

    while(n != 0){
        fast = fast->next;
        n--;
    }

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    auto toFree = slow->next;
    slow->next = slow->next->next;
    delete toFree;

    return dummy->next;
}

// Dummy is needed for these cases
// 1 and n = 1          -> []
// 1, 2 and n = 2       -> 2