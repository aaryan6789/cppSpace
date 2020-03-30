
#include "_lc_linked_list.h"
/*
Leetcode E | 234
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/
ListNode* reverse(ListNode* head){
    ListNode* current = head;
    ListNode* prev = nullptr;
    ListNode* nxt = nullptr;
    while(current != nullptr){
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    return prev;
}

bool isPalindrome1(ListNode* head) {
    if(head == nullptr || head->next == nullptr){
        return true;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    int count = 0;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        // count++;
    }
    if(fast != nullptr){
        slow = slow->next;
    }
    slow = reverse(slow);
    fast = head;
    while(slow != nullptr){
        if(fast->val != slow->val){
            return false;
        }
        fast = fast->next;
        slow = slow->next;
        // count--;
    }
    return true;

}



#include <stack>
bool isPalindrome(ListNode* head) {
    ListNode* front = head;
    stack<int> s;

    while(front!= NULL){
        s.push(front->val);
        front = front->next;
    }

    while(head != NULL){
        int i = s.top();
        s.pop();

        if(i != head->val){
            return false;
        }

        head = head->next;
    }

    return true;
}