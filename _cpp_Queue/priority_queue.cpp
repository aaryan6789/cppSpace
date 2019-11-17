#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

template<typename T>
class PriorityQueue {
private:
    int currSize;
    int maxSize;        // This priority queue assumes that it has a max size
    vector<T> arr;

    void moveDown(vector<T>& arr, int index) {
        int largest = (index << 1) + 1;

        while (largest < currSize) {
            if ((largest<currSize) && (arr[largest] < arr[largest+1]))   ++largest;
            if (arr[index] >= arr[largest])     break;
            std::swap(arr[index], arr[largest]);
            index = largest;
            largest = (largest << 1) + 1;
        }
    }

    void moveUp(vector<T>& arr, int index) {
        int upperVal = (index >> 1) - (index%2 == 0);
        while (upperVal >= 0) {
            if (arr[upperVal] >= arr[index]) break;
            std::swap(arr[upperVal], arr[index]);
            index = upperVal;
            upperVal = (index >> 1) - (index%2 == 0);
        }
    }

public:
    static const int DEFAULT_VAL = -(1<<30);

    PriorityQueue(int pqSize) {
        currSize = -1;
        maxSize = pqSize;
        arr = vector<T>(maxSize+1, T(PriorityQueue::DEFAULT_VAL));
    }

    ~PriorityQueue()    {       }

    // O(lgN) complexity
    void enqueue(T val) {
        arr[++currSize] = val;
        this->moveUp(arr, currSize);     // O(lgN) operation

        // Last Leaf gets removed.
        // ALTERNATE SOLUTION: We can modify it to consider only leaves from [(n-1)/2,n) and
        // find the lowest value leaf and remove that followed by restoring the heap property.
        if (currSize == maxSize)    {
            std::cout << "\nOP: enqueue(" << val << ") ==> The Priority Queue is of capacity " << maxSize << ". Removing last leaf element: " << arr[currSize] << "\n\n";
            arr[currSize] = T(PriorityQueue::DEFAULT_VAL);
            --currSize;
        }
    }

    T top() const {
        if (currSize == -1)     {
            std::cout << "Priority Queue is empty. Cannot get top() element.\n";
            return T(PriorityQueue::DEFAULT_VAL);
        }

        return arr[0];
    }

    // O(lgN) time complexity
    void dequeue() {    // Element with the top most priority ==> first element is dequeued
        if (currSize == -1) {
            std::cout << "Priority Queue is empty. Cannot dequeue().\n";
            return;
        }

        if (currSize == 0) {
            arr[0]  = T(PriorityQueue::DEFAULT_VAL);
            currSize = -1;
            return;
        }

        std::swap(arr[0], arr[currSize]);
        arr[currSize] = T(PriorityQueue::DEFAULT_VAL);       // reset the value
        --currSize;
        this->moveDown(arr, 0);     // O(lgN) operation
    }

};



int main(int argc, char* argv[]) {
    PriorityQueue<int> pq(5);
    pq.enqueue(14);
    pq.enqueue(22);
    pq.enqueue(13);
    pq.enqueue(-6);

    std::cout << "PriorityQueue.top(): " << pq.top() << "\n";   // Should be '22'
    pq.dequeue();
    std::cout << "PriorityQueue.top(): " << pq.top() << "\n";   // Should be '14'
    pq.dequeue();
    std::cout << "PriorityQueue.top(): " << pq.top() << "\n";   // Should be '13'
    pq.enqueue(9);
    pq.enqueue(20);
    pq.enqueue(5);
    pq.enqueue(8);

    std::cout << "PriorityQueue.top(): " << pq.top() << "\n";   // Should be '20'
    pq.dequeue();
    std::cout << "PriorityQueue.top(): " << pq.top() << "\n";   // Should be '13'
    pq.dequeue();
}