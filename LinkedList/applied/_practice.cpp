#include "../_lc_linked_list.h"

// 1. Merge 2 Lists
// 2. Merge K Lists
// 3. Delete n Nodes after m nodes
// 4. Reverse List
// 5. Reverse in K groups
// 6. Remove duplicates from a List

// I/p = 1->1->2->3->4->4->5->6
// O/p = 2->3->5->6
void p_removeDuplicatesII(ListNode* head){
    // Dummy Node Concept
    ListNode dummy(-1);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* current = head;

    while(current != NULL){
        while((prev->next->val == current->next->val) && (current->next != NULL)){
            current = current->next;
        }

        if(prev->next == current){
            prev = prev->next;
        }
        else{
            prev->next = current->next;
        }
        current = current->next;
    }

    head = dummy.next;
}

ListNode* p_removeDuplicatesII2(ListNode* head){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* cur = dummy;
    int duplicate;
    while (cur->next && cur->next->next) {
        if (cur->next->val == cur->next->next->val) {
            duplicate = cur->next->val;
            while (cur->next && cur->next->val == duplicate) {
                cur->next = cur->next->next;
            }
        }
        else {
            cur = cur->next;
        }
    }
    return dummy->next;
}


ListNode* p_reverseKGroups(ListNode* head, int k){
    // printList(head);
    // cout << "Revering in groups of " << k << " now." << endl;
    ListNode* current = head;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    int count = 0;

    while(current != NULL && count < k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(next!= NULL){
        head->next = p_reverseKGroups(next, k);
    }

    return prev;

}



ListNode* p_merge2Lists(ListNode* list1, ListNode* list2){
    cout << "\n MERGING 2 Lists" << endl;
    ListNode* dummy = new ListNode(-1);      // Works
    // ListNode* dummy(0);                     // Seg Fault
    ListNode* result = dummy;

    while(list1 != NULL && list2 !=NULL){
        if(list1->val <= list2->val){
            result->next = list1;
            list1 = list1->next;
        }
        else {
            result->next = list2;
            list2 = list2->next;
        }

        result = result->next;
    }
    cout << "Here 1" << endl;
    // If any of the lists are still there
    result->next = (list1 == NULL ? list2 : list1);

    cout << "Here 3" << endl;
    result = dummy->next;
    return result;
}

#include <queue>
#include <vector>
using namespace std;

struct cmp{
    bool operator() (ListNode* l1, ListNode* l2){
        return l1->val > l2->val;
    }
};

ListNode* p_mergeKLists(vector<ListNode*>& lists){
    cout << "\n MERGING K Lists" << endl;
    // Using MinHeap
    priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;

    cout << "Here 1" << endl;

    for(auto lh : lists){
        if(lh)
            minHeap.push(lh);
    }

    ListNode* result = minHeap.top();
    minHeap.pop();

    if(result->next){
        minHeap.push(result->next);
    }

    ListNode* current = result;
    while(!minHeap.empty()){
        current->next = minHeap.top();
        minHeap.pop();

        current = current->next;

        if(current->next){
            minHeap.push(current->next);
        }
    }

    return result;
}


ListNode* p_reverseList(ListNode* head){
    ListNode* current = head;
    ListNode* prev = NULL;
    ListNode* next;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        if(current && next && prev)
            cout << "current = " << current->val << " next = " << next->val << " prev = " << prev->val << endl;
    }

    cout << "prev = " << prev->val << endl;
    return prev;
}

ListNode* p_movelastToFront(ListNode* head){
    ListNode* last = head;
    ListNode* sec_last = NULL;

    while(last->next != NULL){
        sec_last = last;
        last = last->next;
    }

    sec_last->next = NULL;
    last->next = head;

    head = last;
    return head;

}

ListNode* p_rotateList(ListNode* head, int n){
    ListNode* k = NULL;
    ListNode* kplus1 = head;

    while(kplus1->next != NULL && n != 0){
        k = kplus1;
        kplus1 = kplus1->next;
        n--;
    }
    ListNode* newHead = kplus1;

    k->next = NULL;

    while(kplus1->next != NULL){
        kplus1 = kplus1->next;
    }

    kplus1->next = head;
    return newHead;
}

int main(){
    cout << "\n\n Practice Applied\n\n" << endl;
    ListNode* list1 = NULL;
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
    list1 = one;
    printList(list1);

    ListNode* list2 = NULL;
    ListNode* one2 = new ListNode(10);
	ListNode* two2 = new ListNode(11);
    ListNode* three2 = new ListNode(18);
    one2->next = two2;
    two2->next = three2;

    list2 = one2;
    printList(list2);

    ListNode* list3 = NULL;
    ListNode* one3 = new ListNode(40);
	ListNode* two3 = new ListNode(341);
    ListNode* three3 = new ListNode(419);
    one3->next = two3;
    two3->next = three3;

    list3 = one3;
    printList(list3);

    ListNode* result = p_merge2Lists(list1, list2);
    printList(result);


    printList(list1);
    vector<ListNode*> lists;
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    // ListNode* resultK = p_mergeKLists(lists);
    // printList(resultK);
    printList(list1);


    ListNode* result2 = p_reverseList(list1);
    printList(result2);


    ListNode* head1 = NULL;
    ListNode* one1 = new ListNode(1);
    ListNode* two1 = new ListNode(1);
    ListNode* three1 = new ListNode(3);
    ListNode* four1 = new ListNode(4);
    ListNode* five1 = new ListNode(4);
    ListNode* six1 = new ListNode(6);
	ListNode* seven1 = new ListNode(7);
    ListNode* eight1 = new ListNode(7);
    one1->next = two1;
    two1->next = three1;
    three1->next = four1;
    four1->next = five1;
    five1->next = six1;
	six1->next = seven1;
	seven1->next = eight1;
    head1 = one1;

    // head1 = p_removeDuplicatesII2(head1);

    printList(head1);

    // head1 = p_movelastToFront(head1);
    printList(head1);
    // head1 = p_rotateList(head1, 4);
    printList(head1);

    head1 = p_reverseKGroups(head1, 3);
    printList(head1);






    return 0;



}