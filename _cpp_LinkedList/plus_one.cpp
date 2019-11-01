
#include "_lc_linked_list.h"

// Recursive Implementation:
// We can recursively reach the last node and forward carry to previous nodes.
// Recursive solution doesn’t require reversing of linked list.
// We can also use a stack in place of recursion to temporarily hold nodes.

// Recursively add 1 from end to beginning and returns
// carry after all nodes are processed.
int addWithCarry(ListNode *head)
{
    // If linked list is empty, then return carry
    if (head == NULL)
        return 1;

    // Add carry returned be next ListNode call
    int res = head->val + addWithCarry(head->next);

    // Update data and return new carry
    head->val = (res) % 10;
    return (res) / 10;
}

// This function mainly uses addWithCarry().
ListNode* addOne(ListNode *head){
    // Add 1 to linked list from end to beginning
    int carry = addWithCarry(head);

    // If there is carry after processing all ListNodes,
    // then we need to add a new ListNode to linked list
    if (carry){
        ListNode *newNode = new ListNode(carry);
        newNode->next = head;
        return newNode; // New node becomes head now
    }

    return head;
}




int recur(ListNode* cur, ListNode* parent) {
    if (cur == NULL) {
        int tmp = parent->val + 1;
        parent->val = tmp % 10;
        int carry = tmp / 10;
        return carry;
    }

    int carry = recur(cur->next, cur);
    if (parent==NULL)
        return carry;

    int tmp = parent->val + carry;
    parent->val = tmp % 10;
    carry = tmp / 10;

    return carry;
}

// Different method
ListNode* plusOne(ListNode* head) {
    ListNode* newHead;
    int carry = recur(head, NULL);
    if (carry == 0)
        return head;
    newHead = new ListNode(1);
    newHead->next = head;
    return newHead;
}