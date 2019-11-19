#include <vector>
#include <iostream>

// Max Heap can be used to implement a Priority Queue.
// Heaps are stored as Arrays/ Vectors.
// The Order in which heap elements are stored in a vector are level by level
// form Binary Heap.

// Heapify Up and Heapify Down
// Heapify_up when we push an item to the heap
// heapify Down when we pop from heap

// Data Structure for Min Heap aka PriorityQueue
template <class T>
class PriorityQueue {

private:
    std::vector<T> A;

    // Return PARENT of A[i]
    int PARENT(int i){
        return (i-1)/2;
    }

    // Return LEFT child of A[i]
    int LEFT(int i){
        std::cout << "LEFT " << (2*i + 1) << std::endl;
        return (2*i + 1);
    }

    // Return RIGHT child of A[i]
    int RIGHT(int i){
        return (2*i + 2);
    }

    // Heapify Down
    void moveDown(int i){
        std::cout << "HEAPIFY DOWN FOR " << i << std::endl;
        // Get the left and right child of the node at index i
        int left = LEFT(i);
        int right = RIGHT(i);
        int smallest = i;

        // Compare A[i] with its left and right children and find the smallest val
        if(left < A.size() && A[left] < A[i]){
            smallest = left;
        }
        if(right < A.size() && A[right] < A[smallest]){
            smallest = right;
        }

        // Swap the node with the node of the samllest value.
        // Call moveDown again if needed
        if(smallest != i){
            std::swap(A[i], A[smallest]);
            moveDown(smallest);
        }
    }

    // Heapify Up
    void moveUp(int i){
        // Check if the node and its parent violate its prperty or not
        if(i != 0 && A[PARENT(i)] > A[i]){
            // if here that means the property is violated
            // so swap the element with its Parent
            std::swap(A[i], A[PARENT(i)]);
            // Call Heapify up on the parent now
            moveUp(PARENT(i));
        }
    }

public:
    // Enqueue a key in the Heap / PQ
    void enqueue(T key){
        std::cout << "EnQueue " << key <<  " in the PQ (minHeap)" << std::endl;
        // Always enter the key in the end
        A.push_back(key);

        // Call heapify_up if the key violates the min Heap property
        int index = A.size() - 1;
        moveUp(index);
    }

    // Dequeue the item with the lowest priority i.e the min in minHeap
    void dequeue(){
        if(isEmpty()){
            std::cout << "Heap is Empty. Cant Dequeue any item." << std::endl;
            return;
        }

        std::cout << "Dequeueing Top item = " << A[0] << std::endl;

        // Replace the root i.e 1st item of the heap with the last node in the heap
        A[0] = A.back();
        A.pop_back();

        // Call heapify_down on the root node now
        moveDown(0);
    }

    // return the top element or the lowest priority element from the heap or pq
    T top(){
        if(isEmpty()){
            std::cout << "Nohing to pop" << std::endl;
            return -1;
        }

        std::cout << "Top in the PQ (min_Heap) is " << A[0] << std::endl;
        return A[0];
    }

    // Check if the PQ is empty or not
    bool isEmpty(){
        return (A.size() == 0);
    }

    // PQ size
    unsigned int size(){
        return A.size();
    }
};

int main(){
    PriorityQueue<double> pq;

    pq.enqueue(10.90);
    pq.enqueue(11);

    pq.top();
    // pq.dequeue();

    std::cout << "PQ (minHeap) size = " << pq.size() << std::endl;

    pq.enqueue(12);
    pq.top();
    pq.enqueue(1);

    pq.top();
    std::cout << "PQ (minHeap) size = " << pq.size() << std::endl;

    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.top();

}

