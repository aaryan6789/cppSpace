/**
 * LeetCode M | 622 | Aurora , Argo
 * Design your implementation of the circular queue.
 * The circular queue is a linear data structure in which the operations are
 * performed based on FIFO (First In First Out) principle and the last position
 * is connected back to the first position to make a circle.
 * It is also called "Ring Buffer".
 *
 * One of the benefits of the circular queue is that we can make use of the
 * spaces in front of the queue.
 * In a normal queue, once the queue becomes full, we cannot insert the next
 * element even if there is a space in front of the queue.
 * But using the circular queue, we can use the space to store new values.
 *
 * Your implementation should support following operations:
 *
 * MyCircularQueue(k): Constructor, set the size of the queue to be k.
 * Front: Get the front item from the queue. If the queue is empty, return -1.
 * Rear: Get the last item from the queue. If the queue is empty, return -1.
 * enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
 * deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
 * isEmpty(): Checks whether the circular queue is empty or not.
 * isFull(): Checks whether the circular queue is full or not.
 *
 *
 * Example:
 *
 * MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
 * circularQueue.enQueue(1);  // return true
 * circularQueue.enQueue(2);  // return true
 * circularQueue.enQueue(3);  // return true
 * circularQueue.enQueue(4);  // return false, the queue is full
 * circularQueue.Rear();  // return 3
 * circularQueue.isFull();  // return true
 * circularQueue.deQueue();  // return true
 * circularQueue.enQueue(4);  // return true
 * circularQueue.Rear();  // return 4
 */

#include <vector>
using namespace std;

// Using Vector and 4 variables
// template <class T>
class MyCircularQueue {
public:
    vector<int> data;
    int start;
    int end;
    int curr_size;
    const int max_size;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : max_size(k) {
        // Assign Capacity to the Circular Queue
        data.resize(k);
        this->start = 0;
        this->end = -1;
        this->curr_size = 0;
    }

    /** Insert an element into the circular queue.
        Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()){      // If Full then false
            return false;
        }

        end = (end+1) % max_size;
        data[end] = value;
        curr_size++;
        return true;
    }

    /** Delete an element from the circular queue.
        Return true if the operation is successful. */
    bool deQueue() {
        if(curr_size == 0){     // If Empty Queue already then False
            return false;
        }

        start = (start+1) % max_size;
        curr_size--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(curr_size == 0)
            return -1;
        else
            return data[start];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(curr_size == 0)
            return -1;
        else
            return data[end];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(curr_size == 0)
            return true;

        return false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (curr_size == max_size){
            return true;
        }

        return false;
    }
};