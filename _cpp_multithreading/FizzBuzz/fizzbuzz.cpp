#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;
/**
 * Write a program that outputs the string representation of numbers from 1 to n, however:

If the number is divisible by 3, output "fizz".
If the number is divisible by 5, output "buzz".
If the number is divisible by both 3 and 5, output "fizzbuzz".
For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz.

Suppose you are given the following code:

class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}
Implement a multithreaded version of FizzBuzz with four threads. The same instance of FizzBuzz will be passed to four different threads:

Thread A will call fizz() to check for divisibility of 3 and outputs fizz.
Thread B will call buzz() to check for divisibility of 5 and outputs buzz.
Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and outputs fizzbuzz.
Thread D will call number() which should only output the numbers
*/



void printFizz(){
    cout << "fizz" << endl;
}

void printBuzz(){
    cout << "buzz" << endl;
}

void printFizzBuzz(){
    cout << "fizzbuzz" << endl;
}

void printNumber(int n){
    cout << n << endl;
}

// 32 MS
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

            // Wait on the Condition to become true
            // Start waiting for the Condition Variable to get signaled
            // Wait() will internally release the lock and make the thread to block
            // As soon as condition variable get signaled, resume the thread and
            // again acquire the lock. Then check if condition is met or not
            // If condition is met then continue else again go in wait.
            // while (count <= n && (count % 3 != 0 || count % 5 == 0))
            cv.wait(lock, [this](){return (count > n || (count % 3 == 0 && count % 5 != 0));});

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
            // while (count <= n && (count % 5 != 0 || count % 3 == 0))
            //     cv.wait(lock);
            
            cv.wait(lock, [this](){return (count > n || (count % 3 != 0 && count % 5 == 0));});
            if (count > n) 
                return;
            printBuzz();
            count++;
            cv.notify_all();
        }
    }

	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            // while (count <= n && (count % 5 != 0 || count % 3 != 0))
            //     cv.wait(lock);
            cv.wait(lock, [this](){return (count > n || (count % 3 == 0 && count % 5 == 0));});
            if (count > n) return;
            printFizzBuzz();
            count++;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            // while (count <= n && (count % 5 == 0 || count % 3 == 0))
            //     cv.wait(lock);
            cv.wait(lock, [this](){return (count > n || (count % 3 != 0 && count % 5 != 0));});
            if (count > n) return;
            printNumber(count++);
            cv.notify_all();
        }
    }
};

int main(){
    FizzBuzz* f = new FizzBuzz(15);

    // Creating Threads using Function Objects
    std::thread fizz1(&FizzBuzz::fizz, f, printFizz);
    std::thread fizz2(&FizzBuzz::buzz, f, printBuzz);
    std::thread fizz3(&FizzBuzz::fizzbuzz, f, printFizzBuzz);
    std::thread fizz4(&FizzBuzz::number, f, printNumber);

    fizz1.join();
    fizz2.join();
    fizz3.join();
    fizz4.join();

    cout << "Another Way of Calling the Threads " << endl;

    FizzBuzz f2(30);
    std::thread fizz5(&FizzBuzz::fizz, &f2, printFizz);
    std::thread fizz6(&FizzBuzz::buzz, &f2, printBuzz);
    std::thread fizz7(&FizzBuzz::fizzbuzz, &f2, printFizzBuzz);
    std::thread fizz8(&FizzBuzz::number, &f2, printNumber);

    fizz5.join();
    fizz6.join();
    fizz7.join();
    fizz8.join();


}