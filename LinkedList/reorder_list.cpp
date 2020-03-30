#include "_lc_linked_list.h"
/**
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You may not modify the values in the list's nodes,
 * only nodes itself may be changed.
 *
 * Example 1:
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 *
 * Example 2:
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 */
void reverseList(ListNode** head){
    ListNode* current = *head;
    ListNode* prev;
    ListNode* next;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
}

/// TODO  DEBUG THIS
// Using 2 Pointer and Reversing
// 1. Find ther Middle Node using the 2 Pointer method (fast and slow)
// 2. Split the Liked List in 2 Halves.
// 3. Reverse the Secodn half
// 4. Do alternate Merge of the first and second half

void reorderList(ListNode* head) {
    if(!head || head->next == NULL || head->next->next == NULL){
        return;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while( fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the Linked List in 2 Parts
    ListNode* head1 = head;
    ListNode* head2 = slow->next;
    slow->next = NULL;

    // Reverse the Secodn half of the List
    reverseList(&head2);

    // Now Merge Alternate List
    ListNode* current = head;
    while(head1 || head2){
        // First and Last element of the 2 halves
        if(head1){
            current->next = head1;
            current = current->next;
            head1 = head1->next;
        }

        if(head2){
            current->next = head2;
            current = current->next;
            head2 = head2->next;
        }
    }
}



// Using DeQue
// 1. Create a Deque (Double Ended Queue)
// 2. Insert all elements to the Deque
// 3. Insert All the elements back to the Linked List in alternate Fashion
// i.e first, last and so on
// Time Complexity = O(n)
// Space Complexity = O(K)
#include <deque>
void reorderList1(ListNode* head) {

    deque<int> dq{};

    ListNode* current = head;
    while(current != NULL){
        dq.push_back(current->val);
        current = current->next;
    }

    int i = 0;
    current = head;
    while(!dq.empty()){         // Alternatively Push the values to the Linked List
        if(i%2 == 0){
            current->val = dq.front();
            dq.pop_front();
        }
        else{
            current->val = dq.back();
            dq.pop_back();
        }

        i++;
        current = current->next;
    }
}