#include "_lc_linked_list.h"

/**
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end
 * should remain as it is.
 *
 * Example:
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 * Note:
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be changed.
 */


int countListNode(ListNode* head){
    ListNode* current = head;
    int count = 0;
    while(current != NULL){
        current = current->next;
        count++;
    }
    return count;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    cout << "Reversing Group " << head->val << endl;
    if( k == 0){
        return head;
    }

    if(k > countListNode(head)){
        return head;
    }

    // Reverse a LL in a group of K
    ListNode* current = head;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    int count = 0;

    while( current != NULL && count < k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    cout << "prev = " << prev->val << endl;

    // next is now a pointer to (k+1)th node (also current is at k+1th node)
    // Recursively call for the list starting from current/next.
    // And make rest of the list as next of first node
    if(next != NULL){
        cout << "next = " << next->val << endl;
        cout << "head = " << head->val << endl;
        head->next = reverseKGroup(next, k);        // Head is still the 1st node of that group, and
                                                    // for making the links it should point to the
                                                    // head of the next group.
                                                    // That we get after reversing the group
    }

    return prev;
}



ListNode* reverseKGroup2(ListNode* head, int k){
    ListNode* current = head;
    int count = 0;

    // Check here itself if we want to trigger the function or not
    while(current && count != k){
        current = current->next;
        count++;
    }

    // If nodes left in the list are less than k, then return head directly on line 77

    // Else If, reverse the sublist
    if(count == k){
        // Reverse the k nodes after, return the head of the reversed nodes
        cout << "Current Before = " << current->val << endl;
        current = reverseKGroup2(current, k);
        cout << "Current after = " << current->val << endl;
        cout << "Head after = " << head->val << endl;

        for(int i = k; i>0; i--){
            ListNode* next = head->next;
            head->next = current;
            current = head;
            head = next;
        }
        head = current;
    }

    return head;
}



bool checkValidity(ListNode* head, int k){
    int count = 0;
    ListNode* current = head;
    while(current != nullptr){
        count++;
        current = current->next;
        if(count == k){
            return true;
        }
    }
    
    return false;
}

ListNode* reverseKGroup3(ListNode* head, int k) {
    if(head == nullptr || k == 0){
        return head;
    }
    
    if(!checkValidity(head, k)){
        return head;
    }
    
    int count = k;
    ListNode* current = head;
    ListNode* next;
    ListNode* prev = nullptr;
    
    while(current != nullptr && count--){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    // If there is a next node then we can call a reverse K group recursively
    if(next){
        head->next = reverseKGroup3(next, k);
    }
    
    return prev;
}