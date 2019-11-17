
#include "_lc_linked_list.h"

/* Get the nth node from the front */
void get_nth_node(ListNode *head, int n) {
	// The linked list will start from 1
	ListNode *current = head;
	int count = 1;

	while (current != NULL) {
		count++;
		current= current->next;

		if (count == n)
			break;
	}

	cout << "The " << n << "th node is " << current->val << endl;
}

/* Get the nth node from the front */
ListNode* getNth(ListNode* head, int n){
	ListNode* current = head;
	int count = 1;

	while (current != NULL) {
		count++;
		current= current->next;

		if (count == n)
			break;
	}

	return current;
}


/* Get the nth node from the last */
void get_nth_last(ListNode* head, int n){
	ListNode *fast, *slow;
	fast = slow = head;

	for(int i = 0; i< n; i++){
		fast = fast->next;
	}

	while (fast != NULL){
		fast = fast->next;
		slow = slow->next;
	}

	cout << n << "th node from the last is " << slow->val << endl;
}

/* Get the middle of the Linked List */
void get_middle(ListNode *head) {
	// Method 1 : Using Length of the list
	// Method 2 : 2 Pointers

	ListNode *fast, *slow;
	fast = slow = head;

	if (head == NULL) {
		printf("No LL to find middle from\n");
		return;
	}

	while ( fast != NULL && fast->next != NULL){ // TODO: Analyze the condition properly
		fast = fast->next->next;
		slow = slow->next;
	}

	printf("The middle of the Linked List is=%d\n", slow->val);
}
