#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

/*
Condition variables
A condition variable manages a list of threads waiting until another thread notify them.
Each thread that wants to wait on the condition variable has to acquire a lock first.
The lock is then released when the thread starts to wait on the condition and
the lock is acquired again when the thread is awakened.

BoundedBuffer = Ring Buffer = Curcular Queue
A very good example is a concurrent Bounded Buffer. 
It’s a cyclic buffer with a certain capacity with a start and an end. 
Here is our implementation of a Bounded Buffer using condition variables:
 */ 
struct BoundedBuffer {
    int* buffer;
    
    int capacity;

    int front;
    int rear;
    int count;

    std::mutex lock;

    std::condition_variable not_full;
    std::condition_variable not_empty;

    BoundedBuffer(int capacity) : capacity(capacity), front(0), rear(0), count(0) {
        buffer = new int[capacity];
    }

    ~BoundedBuffer(){
        delete[] buffer;
    }

    // Producer
    void deposit(int data){
        std::unique_lock<std::mutex> l(lock);

        not_full.wait(l, [this](){return count != capacity; });

        buffer[rear] = data;
        rear = (rear + 1) % capacity;
        ++count;

        l.unlock();
        not_empty.notify_all();
    }

    int fetch(){
        std::unique_lock<std::mutex> l(lock);

        not_empty.wait(l, [this](){return count != 0; });

        int result = buffer[front];
        front = (front + 1) % capacity;
        --count;

        l.unlock();
        not_full.notify_all();

        return result;
    }
};

void consumer(int id, BoundedBuffer& buffer){
    for(int i = 0; i < 5; ++i){
        int value = buffer.fetch();
        std::cout << "Consumer " << id << " fetched " << value << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}

void producer(int id, BoundedBuffer& buffer){
    for(int i = 0; i < 7; ++i){
        buffer.deposit(i);
        std::cout << "Produced " << id << " produced " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

/*
We can use this structure to fix multiple consumers / multiple producers problem.
This problem is very common in concurrent programming. 
Several threads (consumers) are waiting from data produced by another several 
threads (producers). 

Here is an example with several threads using the structure:
Three consumer threads and two producer threads are created and query the 
structure constantly. 
An interesting thing about this example is the use of std::ref to pass the buffer by
reference, it is necessary to avoid a copy of the buffer.
 */

int main(){
    BoundedBuffer buffer(20);
    int num_byts = sizeof(int);
    cout << num_byts << endl;

    std::thread c1(consumer, 0, std::ref(buffer));
    std::thread c2(consumer, 1, std::ref(buffer));
    std::thread c3(consumer, 2, std::ref(buffer));
    std::thread p1(producer, 0, std::ref(buffer));
    std::thread p2(producer, 1, std::ref(buffer));

    c1.join();
    c2.join();
    c3.join();
    p1.join();
    p2.join();

    return 0;
}