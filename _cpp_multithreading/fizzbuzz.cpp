#include <mutex>
#include <condition_variable>
#include <iostream>
using namespace std;


// 36 ms Answer
class FizzBuzz {
private:
    int n;
    int count;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->count = 1;
    }

    void fizz(function<void()> printFizz) {
        while (true) {
            // Acquire the Lock
            unique_lock<mutex> lock(m);

            // Wait on the COndition to become true
            while (count <= n && (count % 3 != 0 || count % 5 == 0))
                cv.wait(lock);

            // Termination
            if (count > n) return;

            // What is the work of this thread
            printFizz();
            count++;

            // Work Done so Notify all the other threads
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 5 != 0 || count % 3 == 0))
                cv.wait(lock);
            if (count > n) return;
            printBuzz();
            count++;
            cv.notify_all();
        }
    }

	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 5 != 0 || count % 3 != 0))
                cv.wait(lock);
            if (count > n) return;
            printFizzBuzz();
            count++;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 5 == 0 || count % 3 == 0))
                cv.wait(lock);
            if (count > n) return;
            printNumber(count++);
            cv.notify_all();
        }
    }
};