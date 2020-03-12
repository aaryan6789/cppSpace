//__LINKEDLIST__C_

#include "_linked_list.h"
#include "_lc_linked_list.h"

using namespace std;

int main() {

	cout  << "Linked List" << endl;

	LinkedList sll;
	sll.listLength();
	sll.insertBeg(12);
	sll.insertBeg(21);
	sll.listLength();
	sll.printList();

	// LinkedList sl2 = new LinkedList();
	// ListNode* head = new ListNode(10);
	// insertBeg(&head, 21);
	// insertBeg(&head, 22);
	// insertBeg(&head, 23);

	// printList(head);

	// ListNode* list1 = new ListNode(1);
	// insertBeg(&list1, 2);
	// insertBeg(&list1, 3);

	// ListNode* list2 = new ListNode(2);
	// insertBeg(&list2, 2);
	// insertBeg(&list2, 2);

	// printList(list1);
	// printList(list2);

	// ListNode* res = addTwoLists(list1, list2);
	// printList(res);
	// res = reverseList(res);
	// printList(res);


	/* Start with the empty list */
    struct ListNode* head2 = NULL;

     /* Create Linked list is 1->2->3->4->5->6->NULL */
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* five = new ListNode(5);
    ListNode* six = new ListNode(6);
	ListNode* seven = new ListNode(7);
    ListNode* eight = new ListNode(8);
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
	six->next = seven;
	seven->next = eight;

    head2 = one;

    cout << "Given linked list" << endl;

    printList(head2);
    cout << countListNode(head2) << endl;
    // call reverseKGroup() here
    head2 = reverseKGroup(head2, 3);
    cout << "Reversed linked list" << endl;

    printList(head2);

	ListNode l1(10);
	ListNode l2(20);
	ListNode l3(30);

	l1.next = &l2;
	l2.next = &l3;

	ListNode copyll = l1;

	printList(&l1);

	l1.next = nullptr;
	printList(&l1);
	printList(&copyll);





	return(0);




}