/**
 * Design your implementation of the circular double-ended queue (deque).

Your implementation should support following operations:

MyCircularDeque(k): Constructor, set the size of the deque to be k.
insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
getRear(): Gets the last item from Deque. If the deque is empty, return -1.
isEmpty(): Checks whether Deque is empty or not.
isFull(): Checks whether Deque is full or not.

Example:

MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
circularDeque.insertLast(1);			// return true
circularDeque.insertLast(2);			// return true
circularDeque.insertFront(3);			// return true
circularDeque.insertFront(4);			// return false, the queue is full
circularDeque.getRear();  			// return 2
circularDeque.isFull();				// return true
circularDeque.deleteLast();			// return true
circularDeque.insertFront(4);			// return true
circularDeque.getFront();			// return 4


Note:

All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Deque library.
Accepted

 */
#include <vector>
using namespace std;

class MyCircularDeque {
    vector<int> queue;
    int head = 0; // goes forward
    int tail = 0; // goes backward
    // +------+---+---+---+--+--+--+--+--+--+------+
    // |  0   | 1 | 2 | 3 |  |  |  |  |  |  | n-1  |
    // +------+---+---+---+--+--+--+--+--+--+------+
    // | head |   |   |   |  |  |  |  |  |  | tail |
    // +------+---+---+---+--+--+--+--+--+--+------+
    int capacity = 0;
    int count = 0;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        queue.reserve(k);
        head = 0;
        tail = k-1;
        capacity = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        queue[head] = value;
        head = (head + 1) % capacity;       // % = Modulo
        count++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        queue[tail] = value;
        tail = (tail - 1 + capacity) % capacity;
        count++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        head = (head - 1 + capacity) % capacity;
        count--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        tail = (tail + 1) % capacity;
        count--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return queue[(head - 1 + capacity) % capacity];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return queue[(tail + 1) % capacity];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count == capacity;
    }
};



class MyCircularDequeGFG{
    private:
        vector<int> dq;
        int front;
        int last;
        int size;

    public:
        MyCircularDequeGFG(int k): front(-1), last(0), size(k) {}

        int isFull(){
            if((front == 0 && last == size-1) || (front == last+1)){
                return true;
            }
            return false;
        }



};




















class MyCircularDeque2 {
private:
    vector<int> deq;
    int head;
    int tail;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque2(int k) {
        deq = vector<int>(k, 0);
        head = -1;
        tail = -1;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        if(head == -1) {
            head = deq.size()-1;
        }
        else {
            head--;
            if(head < 0) head = deq.size()-1;
        }
        deq[head] = value;
        if(tail == -1) tail = head;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        tail = (tail+1)%deq.size();
        deq[tail] = value;
        if(head == -1) head = tail;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(head == -1 && tail == -1) return false;
        if(head == tail) {
            head = -1;
            tail = -1;
        }
        else {
            head = (head+1)%deq.size();
        }
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(head == -1 && tail == -1) return false;
        if(head == tail) {
            head = -1;
            tail = -1;
        }
        else {
            tail--;
            if(tail < 0) tail = deq.size()-1;
        }
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) return -1;
        return deq[head];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        return deq[tail];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (head == -1 && tail == -1);
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return ((tail+1)%deq.size() == head);
    }
};
