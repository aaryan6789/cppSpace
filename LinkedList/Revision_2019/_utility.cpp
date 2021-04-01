#include "../_lc_linked_list.h"
using namespace std;

void printList(ListNode* head){
	ListNode *current = head;
	int num_nodes=0;

	// cout << "Printing Linked List:" << endl;
	while(current != NULL) {
		cout << current->val << " " ;
		num_nodes++;
		current = current->next;
	}
	cout << "\nNumber of Nodes: " << num_nodes << endl;
}

int listLength(ListNode* head) {
	ListNode* current = head;
	int num_nodes = 0;

	while(current != NULL) {
		num_nodes++;
		current = current->next;
	}

	return num_nodes;
}