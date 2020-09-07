
/** LeetCode Easy
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 *
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 */

/**
 * Design a Data Structure SpecialStack that supports all the stack operations
 * like push(), pop(), isEmpty(), isFull() and an additional operation getMin()
 * which should return minimum element from the SpecialStack.
 * All these operations of SpecialStack must be O(1).
 * To implement SpecialStack, you should only use standard Stack data structure
 * and no other data structure like arrays, list, .. etc.
 */
/** Solution:
 *  Use two stacks: one to store actual stack elements and
 *  				other as an auxiliary stack to store minimum values.
 *  The idea is to do push() and pop() operations in such a way that the top of
 *  auxiliary stack is always the minimum.
 *  Let us see how push() and pop() operations work.
 *
 *  Push(int x) // inserts an element x to Special Stack
 *  1) push x to the first stack (the stack with actual elements)
 *  2) compare x with the top element of the second stack (the auxiliary stack).
 *  Let the top element be y.
 *  a) If x is smaller than y then push x to the auxiliary stack.
 *  b) If x is greater than y then push y to the auxiliary stack.
 *
 *  int Pop() // removes an element from Special Stack and return the removed element
 *  1) pop the top element from the auxiliary stack.
 *  2) pop the top element from the actual stack and return it.
 *
 *  The step 1 is necessary to make sure that the auxiliary stack is also
 *  updated for future operations.
 *
 *  int getMin() // returns the minimum element from Special Stack
 *  1) Return the top element of auxiliary stack.
 *  We can see that all above operations are O(1).
 */

// Tested on Leetcode
#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    std::stack<int> actStack;
    std::stack<int> auxStack;

    MinStack() {}

    int getMin() {
        return auxStack.top();
    }

    void push(int x) {
        // Push on the Actual Stack
        actStack.push(x);

        // Push on the Aux Stack only when its a min value
        if (auxStack.empty() || x <= getMin())
            auxStack.push(x);
    }

    void pop() {
        // Pop from the Aux Stack only if the actual stack popped value is the min
        if (actStack.top() == getMin())
            auxStack.pop();

        // Pop From the Actual Stack
        actStack.pop();
    }

    int top() {
        return actStack.top();
    }
};