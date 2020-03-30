#include "_lc_linked_list.h"

/** LeetCode E | CTCI | https://leetcode.com/problems/merge-two-sorted-lists/
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 */

/* Algorithm: Dummy Node Concept
 * -----------------------------
 * 1. Set up a false "result" node that allows us to easily return the head
 *    of the merged list later.
 *    Maintain a dummy pointer, which points to the current node for which we are
 *    considering adjusting its next pointer.
 *
 * 2. Then, we do the following until at least one of l1 and l2 points to null:
 *    if the value at l1 is less than or equal to the value at l2,
 *        then we connect l1 to the previous node and increment l1.
 *    Otherwise, we do the same, but for l2.
 *
 * 3. Then, regardless of which list we connected, we increment result to keep
 *    it one step behind one of our list heads.
 *
 * 4. After the loop terminates, at most one of l1 and l2 is non-null.
 * Therefore (because the input lists were in sorted order),
 * if either list is non-null, it contains only elements greater than all of the
 * previously-merged elements.
 *
 * This means that we can simply connect the non-null list to the merged list and return it.
 */

/* Time Complexity:
 * O(m + n) == Length of both the lists
 * O(1) Space complexity
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    ListNode* dummy = new ListNode(0);  // On the Stack would be ListNode* dummy(0)
    ListNode* result = dummy;			// Head of the Result List

    while(l1!= NULL &&  l2!= NULL){     // && to get out of this early
        if(l1->val <= l2->val){
            result->next = l1;
            l1 = l1->next;
        }
        else {
            result->next = l2;
            l2 = l2->next;
        }

        result = result->next;
    }

    // Exactly one of l1 and l2 can be non-null at this point, so connect
    // the non-null list to the end of the merged list.
    result->next = (l1 == NULL ? l2 : l1);

    result = dummy->next;
    delete dummy;               // Prevents Memory Leaks
    return result;
}