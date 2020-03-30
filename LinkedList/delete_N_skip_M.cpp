#include "_lc_linked_list.h"
/**
 * Delete N nodes after M nodes of a Linked List
 *
 * 1. Move the current pointer by M nodes
 * 2. Cache the M->next node in another node Pointer
 * 3. Delete the N nodes one by one
 * 4. Join the links
 */
void deleteNskipM(ListNode* head, int n, int m){
	printf("Delete N = %d nodes after skipping M = %d  nodes\n", n, m);
	ListNode* current = head;
	ListNode* t;

	// Skip M Nodes
	for (int count = 1; count < m && current != NULL; count++){	//<--- Pay attention here
		current = current->next;
	}
	// Here current pointer is at the the Mth node

	// Start from the next node of Mth node and start deleting N Nodes
	t = current->next; 		// Cache the next node of Mth node for deleting
	for(int count = 1; count <= n && t != NULL; count ++) {
		ListNode* temp = t;
		t = t->next;
		free(temp);
	}
	// Here t is pointing to the M + Nth node


	// Join the links between current pointer(pointed to Mth node) and the t pointer
	current->next = t;

	return;
}

// Review the code : Logic is correct, but crashing
void deleteNskipM_alternatively(ListNode* head, int n, int m){
	printf("Delete N = %d nodes after skipping M = %d  nodes\n", n, m);
	ListNode* current = head;
	ListNode* t;

	while(current){
		// Skip M Nodes
		for (int count = 1; count < m && current != NULL; count++){	//<--- Pay attention here
			current = current->next;
		}

		// Here current pointer is at the the Mth node
		// Start from the next node of Mth node and start deleting N nodes
		t = current->next; 		// Cache the next node
		for(int count = 1; count <= n && t != NULL; count ++) {			// <--- Pay attention here
			ListNode* temp = t;
			t = t->next;
			free(temp);
		}

		// Join the links between current pointer and the t pointer
		current->next = t;

		// Set the current Pointer for next iteration
		current = t;
	}
}

