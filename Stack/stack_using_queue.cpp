




#include <queue>
using namespace std;


// Just use a queue where you "push to front" by pushing to back and then rotating
// the queue until the new element is at the front (i.e., size-1 times move the
// front element to the back).

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i=1; i<q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};