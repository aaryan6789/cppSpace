#include "_linked_list.h"

using namespace std;


void LinkedList::insertBeg(int data) {
	/* 1. Allocate a newNode
	 * 2. Fill in the data field
	 * 3. Make current head as the next of newNode
	 * 4. newNode will be the new Head of the linked list
	 */
    // node* head = this->head;
	cout << "Inserting " << data <<  " in the beginning" << endl;
	node* newNode = new node;     // newNode = (struct node* )malloc(sizeof(struct node));
	/* Check for Null pointer */
	if (!newNode){
		printf("malloc failed\n");
		return;
	}

	newNode->data = data;		    //2
	newNode->next = head;   	    //3
	head = newNode;		            //4
}


#include "_lc_linked_list.h"

void insertBeg(ListNode** head_ref, int val){
	cout << "Inserting " << val << " in the beginnig" << endl;
	ListNode* newNode = new ListNode(val);

	newNode->next = *head_ref;
	*head_ref = newNode;
}

void insert_last(ListNode **head_ref, int data){
	/* 1. Allocate a newNode (malloc) + check for NULL pointer
	 * 2. Fill in the data field
	 * 3. Fill in the next field of the node.
	 * 	  The next of the newNode will be NULL as its gonna be the last node.
	 * 4. Now we have to position the node to be the last node.
	 * 	- If the Linked list is empty then the newNode will be the 1st and Last
	 * 	  node. We will handle this condition check first as then we can save
	 * 	  the time of traversing the linked list.
	 * 	- Else, we have to traverse the linked list till the end of the LL.
	 * 	  And attach the newNode at the end now.
	 */
	printf("Insert %d in the end\n", data);
	ListNode *current = *head_ref;
	ListNode *newNode = new ListNode(data);
	/* check for NULL node */
	if (!newNode){
		printf("malloc failed\n");
		return;
	}

	if (*head_ref == NULL) {
		printf("The Current Linked List is empty. So this node will be the head node\n");
		*head_ref = newNode;
		return;
	}
	else {
		/* traverse to the last node */
		while(current->next != NULL) {
			current = current->next;
		}
		printf("Last node of the current linked list is: %d\n", current->val);
		current->next = newNode;
	}
}