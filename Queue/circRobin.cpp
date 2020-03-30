#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class CircularQueue {
private:
    int front, back;
    vector<T> circularQueue;
    int maxElems;

public:

    static const int DEFAULT_VALUE = -(1<<30);

    CircularQueue(int max) : front(-1), back(-1) {
        this->maxElems = max;
        this->circularQueue = std::vector<T>(this->maxElems, T(CircularQueue::DEFAULT_VALUE));
    }

    ~CircularQueue()    {       }

    void enqueue(T val) {
        std::cout << "Before Enqueue(" << val << "): front=" << front << "\tback=" << back << "\n";
        if ( ((front == 0) && (back == this->maxElems -1)) || (front - back == 1))  {
            std::cout << "Cannot enqueue elements anymore, the queue is full\n";
            return;
        }

        if (front == -1)    front = 0;
        if (back == (this->maxElems - 1))  back = 0;
        else ++back;

        std::cout << "After Enqueue(" << val << "): front=" << front << "\tback=" << back << "\n\n";
        circularQueue[back] = val;
    }

    T top() {
        if (front == -1) {
            std::cout << "The CircularQueue is empty. Returning gibberish value as top()\n";
            return T(CircularQueue::DEFAULT_VALUE);
        }
        return circularQueue[front];
    }

    void dequeue() {
        std::cout << "Before Dequeue(): front=" << front << "\tback=" << back << "\n";
        if (front == -1) {
            std::cout << "The CircularQueue is empty: Cannot Dequeue\n";
            return;
        }

        circularQueue[front] = CircularQueue::DEFAULT_VALUE;
        if (front == back)      front = back = -1;  // Single Element
        else if (front == (this->maxElems-1))    front = 0;
        else ++front;

        std::cout << "After Dequeue(): front=" << front << "\tback=" << back << "\n";
    }
};


// int main(int argc, char* argv[]) {
//     CircularQueue<int> cq(5);
//     cq.enqueue(14);
//     cq.enqueue(22);
//     cq.enqueue(13);
//     cq.enqueue(-6);

//     std::cout << "CircularQueue.top(): " << cq.top() << "\n";
//     cq.dequeue();
//     std::cout << "CircularQueue.top(): " << cq.top() << "\n";
//     cq.dequeue();
//     std::cout << "CircularQueue.top(): " << cq.top() << "\n";
//     cq.enqueue(9);
//     cq.enqueue(20);
//     cq.enqueue(5);
//     cq.enqueue(8);
// }
