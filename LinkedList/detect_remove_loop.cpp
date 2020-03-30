/*
 * detect_remove_loop.c
 *
 *  Created on: Apr 16, 2018
 *      Author: hsahu
 */

#include "_lc_linked_list.h"
/* detect_loop - Detect a loop in a Linked List
 * Method: Floyd's Cycle Finding Algorithm
 * 1. Declare 2 pointers for traversing the LL
 * -- fast  --> increment by 2 nodes
 * -- slow  --> increment by 1 node
 * 2. If these 2 pointers meet at some point in then there definitely
 * there is a loop. If they dont then no loop.
 *
 * This concept can be extended for removing the loop too.
 */
void detect_loop(ListNode* head) {

	ListNode *slow, *fast;
	slow = fast = head;

	while (slow && fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast){
			printf("There is a loop in this linked list.\n");
			return;
		}
	}
	printf("No loop detected.\n");
}

void _remove_loop(ListNode *loop_node, ListNode *head){
	ListNode *ptr1, *ptr2;
	ptr1 = ptr2 = loop_node;

	// count the number of nodes in the loop
	int k = 1;
	int i;

	while (ptr1->next != ptr2){
		ptr1 = ptr1->next;
		k++;
	}
	printf("Number of LoopNodes:%d\n", k);

	// Set ptr1 to head & ptr2 to (head + k)
	ptr1 = ptr2 = head;

	for (i = 0 ; i< k ; i++){
		printf("i = %d, k = %d ptr2->val = %d\n",i, k, ptr2->val);
		ptr2 = ptr2->next;
	}

	printf("1 Ptr1->val = %d\n", ptr1->val);
	printf("1 Ptr2->val = %d\n", ptr2->val);
	// Move both pointers at the same pace now
	while (ptr2 != ptr1) {
		printf("One\n");
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	printf("2 Ptr2->val = %d\n", ptr2->val);

	// Get the next of the start of the loop node
	ptr2 = ptr2->next;

	while(ptr2->next != ptr1)
		ptr2 = ptr2->next;

	ptr2->next = NULL;

	printf("Loop removed.\n");
}

void detect_remove_loop(ListNode *head) {

	ListNode *slow, *fast;
	slow = fast = head;

	while (slow && fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast){
			printf("There is a loop in this linked list.\nRemoving Loop now.\n");
			_remove_loop(slow, head);
			return;
		}
	}
	printf("No loop detected.\n");
}

/**
 * Form a Loop in a Linked List by attaching the last node to a node in the
 * middle of the Linked list.
 * Pretty sweet implementation :)
 */
void form_a_loop(ListNode *head, ListNode *loop_attach) {
	ListNode *current = head;

	// Go to the last node
	while (current->next != NULL){
		current = current->next;
	}

	// Forming loop
	printf("loop_attach->val:%d current->val:%d\n", loop_attach->val, current->val);
	current->next = loop_attach;

	printf("current->next->val:%d\n", current->next->val);
	printf("Loop Formed.\n");
}
