/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "_lc_linked_list.h"
/**
 * Reverse a linked list from position m to n. Do it in one-pass.
 * Note: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example:
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 */

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* current = head;
	ListNode* prev = NULL;

	// Move the 2 pointers until they reach the mth node
	while(m > 1){
		prev = current;
		current = current->next;
		m--;
		n--;
	}
	// Here current is mth node
	// prev is before mth node

	cout << "prev = " << prev->val << " current = " << current->val << endl;
	// For linking the sub list after reversing the sublist to finish the linked list
	ListNode* before_m = prev;
	ListNode* mth = current;        // Since mth next node will be used for
									// linking to the rest of the linked list
									//
	cout << "mth = " << mth->val << " before_m = " << before_m->val << endl;

	// Iteratively reverse the nodes until n becomes 0
	ListNode* next = NULL;
	while(n>0){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		n--;
	}

	// Make the links now
	// Prev now points to the nth node
	// the prev pointer after reversing would come at the place of mth node
	// so the link is made by connecting the before_m to prev pointer

	// current now points to the node after the nth node.
	// So mth next node should be pointing to current to make the link
	if(before_m != NULL){
		before_m->next = prev;
	}
	else{
		head = prev;
	}

	mth->next = current;
	return head;
}
