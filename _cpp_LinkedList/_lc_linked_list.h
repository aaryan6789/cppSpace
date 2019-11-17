#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/* Leetcode Structure to represent a Singly Linked List */
struct ListNode {
    int val;
    ListNode *next;

    // Constructor
    ListNode(int x) : val(x), next(NULL) {}     // Member initializer list
};

void printList(ListNode* head);
int listLength(ListNode* head);

void insertBeg(ListNode **head_ref, int val);
void insert_last(ListNode **head_ref, int data);
ListNode* addTwoLists(ListNode* head1, ListNode* head2);

bool hasCycle(ListNode *head);

ListNode* reverseList(struct ListNode *head);
ListNode* reverseKGroup(ListNode* head, int k);
ListNode* reverseKGroup2(ListNode* head, int k);
int countListNode(ListNode* head);

void practice_1();