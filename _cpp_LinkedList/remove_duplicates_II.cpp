/* LeetCode Medium
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * Example 1:
 * Input: 1->2->3->3->4->4->5 -------->>>>> Output: 1->2->5
 *
 * Example 2:
 * Input: 1->1->1->2->3    ----------->>>>> Output: 2->3
 *
 */
#include "_lc_linked_list.h"
void removeAllDuplicates(ListNode* head) {
   /* create a dummy node that acts like a fake
	  head of list pointing to the original head*/
	ListNode dummy(-1);

	/* dummy node points to the original head*/
	dummy.next = head;
	ListNode* prev = &dummy;		// Address of dummy node in the prev pointer
	ListNode* current = head;

	while (current != NULL) {
		/* Until the current and previous values
		   are same, keep updating current */
		while (current->next != NULL && (prev->next->val == current->next->val)){
			current = current->next;
		}

		/* if current has unique value i.e current is not updated,
		 * Move the prev pointer to next node*/
		if (prev->next == current){
			prev = prev->next;
		}
		else{
			/* when current is updated to the last duplicate value of that segment,
			 * make prev the next of current*/
			prev->next = current->next;
		}
		current = current->next;
	}

	/* update original head to the next of dummy node */
	head = dummy.next;
}