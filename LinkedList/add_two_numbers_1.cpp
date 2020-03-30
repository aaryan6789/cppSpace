#include <stdio.h>
#include <stdlib.h>

#include "_lc_linked_list.h"

/* CTCI | LeetCode M
 * add_two_numbers_1.c | Apr 9, 2018 | Author: hsahu
 *
 * Given two numbers represented by two lists,
 * write a function that returns sum list.
 * The sum list is list representation of addition of two input numbers.
 *
 * Example 1:
 * Input: First List: 5->6->3  	// represents number 365
 *        Second List: 8->4->2 	//  represents number 248
 * Output: Result list: 3->1->6  	// represents number 613
 *
 * Example 2
 * Input: First List: 7->5->9->4->6  	// represents number 64957
 *   	   Second List: 8->4 			//  represents number 48
 * Output: Result list: 5->0->0->5->6  // represents number 65005
 */

/** Algorithm:
 * 1. Traverse both lists. One by one pick nodes of both lists and add the values.
 * // Calculate value of next digit in resultant list.
   // The next digit is sum of following things
   // (i)  Carry
   // (ii) Next digit of first list (if there is a next digit)
   // (ii) Next digit of second list (if there is a next digit)
 * 2. If sum is more than 10 then make carry as 1 and reduce sum to (sum%10).
 * 3. If one list has more elements than the other then consider remaining values
 *  of this list as 0.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
	ListNode* dummy = new ListNode(0);
	ListNode* result = dummy;			// Head of the Result List

	// Addition of 2 numbers have sum and carry
	// if sum = 12 then carry = 1 and sum = 2
	// if sum = 9  then carry = 0 and sum = 9
	int carry = 0;
	int sum;

	// While both the lists exist, loop through them
	while(head1 != NULL || head2 != NULL){
		sum = carry + (head1 ? head1->val: 0) +
					  (head2 ? head2->val: 0);

		if (sum >= 10) {
			sum = sum % 10;
			carry = 1;
		}
		else {
			sum = sum % 10;
			carry = 0;
		}

		// Create a New node for the result list and add it to the result list
		ListNode* newNode = new ListNode(sum);
		result->next = newNode;
		result = result->next;

		// Move the linked lists
		if(head1)
			head1 = head1->next;

		if(head2)
			head2 = head2->next;
	}

	if (carry > 0)
		result->next = new ListNode(carry);

	result = dummy->next;
	return result;
}