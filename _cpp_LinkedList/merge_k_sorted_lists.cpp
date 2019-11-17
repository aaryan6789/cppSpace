#include "_lc_linked_list.h"
#include <queue>

/** LEETCODE HARD | MERGE K LISTS
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
 */


struct cmp{
    bool operator() (ListNode* l1, ListNode* l2){
        return l1->val > l2->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (!lists.size())
        return nullptr;

    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;       // minHeap
    // Push the head nodes of all the lists on the min heap
    for (auto lh : lists){
        if (lh)
            pq.push(lh);
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* p = dummy;
    while (!pq.empty()){                    // Loop till minHeap is not empty
        ListNode* smallest = pq.top();      // Get the Top elemment from the heap which is the smallest
        pq.pop();

        p->next = smallest;
        p = p->next;
        if (smallest->next){
            pq.push(smallest->next);
        }
    }

    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
}

ListNode *mergeKListsHeap(vector<ListNode *> &lists) { //priority_queue
    // Create a min Heap
    priority_queue<ListNode *, vector<ListNode *>, cmp> q;

    // Push the head nodes of all the lists on the min heap
    for(auto lh : lists) {
        if(lh)
            q.push(lh);
    }

    if(q.empty())       // Boundary Check: If there are no elements on the heap then NULL
        return NULL;

    // The head of the result list is going to be the top element from the minHeap
    ListNode* result = q.top();
    q.pop();

    // Top element could be pointing to its next element. If it does then push it on the heap
    if(result->next)
        q.push(result->next);       // This will call heapify operation

    // Lets have a runner pointer
    ListNode* current = result;
    while(!q.empty()) {         // loop till the minHeap becomes empty
        current->next = q.top();        // Now make links
        q.pop();

        current = current->next;
        // Push the next element of the list on the heap
        if(current->next)
            q.push(current->next);
    }

    return result;
}
