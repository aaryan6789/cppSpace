#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <time.h>
#include <functional>
#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

struct data {
    queue<int> q;
};


class Multi {
private:
    // queue<int> * q = new queue();
    queue<int> q;

    std::shared_ptr<data> shQ = make_shared<data>();
    std::weak_ptr<data> wpQ(shQ);

    int capacity;

    // Thread Safe Operation
    mutex _m;
    condition_variable cv_full;
    condition_variable cv_empty;
    

public:
    Multi(int n) {
        capacity = n;
        srand(time(nullptr));
    }

    void producer() {
        while(true) {
            // 1. Acquire the Lock first before getting into CS
            unique_lock<mutex> lock(_m);

            // 2. Check for the condition for Producers
            // Queue should not be full.
            cv_full.wait(lock, [this](){return (q.size() < this->capacity); });

            // Generate a Random number to push into the Queue
            int num = rand()%10 + 1;
            shQ->q.push(num);
            // cout << "P = " << num << endl;
            cout << "sh P = " << shQ->q.back() << endl;
            
            q.push(num);

            // 3. Notify other Threads
            cv_empty.notify_one();
        }
    }

    void consumer() {
        while(true) {
            // 1. Acquire the Lock
            unique_lock<mutex> lock(_m);

            // 2. Check for the condition for Producers
            // Queue should not be Empty.
            cv_empty.wait(lock, [this](){
                                    cout << "C waiting.." << endl;
                                    return !q.empty(); });

            int num = q.front(); q.pop();

            cout << "shQ C = " << shQ->q.front() << endl;

            cout << "C = " << num << endl;

            cv_full.notify_one();
        }
    }
};


int main() {
    // Create 2 Threads : Producer and Consumer
    Multi* m = new Multi(2);

    thread t1(&Multi::producer, m);
    thread t2(&Multi::consumer, m);

    t1.join();
    t2.join();

    return 0;
}