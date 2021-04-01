#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

void printFoo(){
    cout << "foo" ;
}

void printBar(){
    cout << "bar " << endl;
}

// Making a Class to Print Foo Bar altenatively given the number of times as an argument
class FooBar {
    private:
        int n;
        mutex _m;
        condition_variable cv;
        bool foo = true;        // Flag to be used with the condition variable

    public:
        FooBar(int cap){
            this->n = cap;
        }

        void Foo(function<void()> printFoo){
            // 1. Acquire the Lock
            unique_lock<mutex> lock(_m);

            for(int i = 0; i< n; i++) {
                // 2. Wait for the condition to become true
                // In this case foo should return true
                cv.wait(lock, [this](){return foo;});

                // 3. Execute the Task
                printFoo();

                // 4. Reset the flags
                foo = false;

                // 5. Notify the threads
                cv.notify_one();
            }
        }

        
        void Bar(function<void()> printBar){
            // 1. Acquire the Lock
            unique_lock<mutex> lock(_m);

            // Loop Through to keep printing the foo bar alternatively
            for(int i = 0; i< n; i++) {
                // 2. Wait for the condition to become true
                // In this case foo should return false
                cv.wait(lock, [this](){return !foo;});

                // 3. Execute the Task
                printBar();

                // 4. Reset the flags
                foo = true;

                // 5. Notify the threads
                cv.notify_one();
            }
        }
};

int main() {
    FooBar* fb = new FooBar(6);

    // Create Threads
    thread th_foo(&FooBar::Foo, fb, printFoo);
    thread th_bar(&FooBar::Bar, fb, printBar);

    th_bar.join();
    th_foo.join();

}