#include "iostream"
#include "thread"
#include "mutex"
#include "condition_variable"
using namespace std;

std::mutex mu;
std::condition_variable cond;
int count = 1;
int n = 20;

void printEven() {
    while(count < n){
        unique_lock<mutex> lock(mu);

        cond.wait(lock, []() {return (count % 2 == 0);});

        cout << "Even thread prints : " << count << endl;
        count++;
        
        lock.unlock();
        cond.notify_all();
    }
}

void printOdd() {
    while(count < n){
        unique_lock<mutex> lock(mu);
        
        cond.wait(lock, []() {return (count % 2 != 0);});
        
        cout << "Odd thread prints : " << count << endl;
        count++;
        
        lock.unlock();
        cond.notify_all();
    }
}

void printOddEven(){
    std::thread t1(printOdd);
    std::thread t2(printEven);
    t1.join();
    t2.join();
    return;
}


// 1. Acquire the Lock
// 2. Condition Variable and wait for the Condition
// 3. Do the Work in the CS
// 4. Unlock the Lock
// 5. Notify others 