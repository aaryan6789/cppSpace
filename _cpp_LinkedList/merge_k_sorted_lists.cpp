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

    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    for (auto lh : lists){
        if (lh)
            pq.push(lh);
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* p = dummy;
    while (!pq.empty()){
        ListNode* smallest = pq.top();
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
    priority_queue<ListNode *, vector<ListNode *>, cmp> q;

    for(auto l : lists) {
        if(l)  q.push(l);
    }

    if(q.empty())
        return NULL;

    ListNode* result = q.top();
    q.pop();

    if(result->next)
        q.push(result->next);

    ListNode* tail = result;
    while(!q.empty()) {
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if(tail->next)
            q.push(tail->next);
    }

    return result;
}
