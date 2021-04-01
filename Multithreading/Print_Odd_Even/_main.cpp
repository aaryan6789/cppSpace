#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "_header.h"

using namespace std;

class OddEven {
    int n;
    int count;
    
    mutex m;
    condition_variable cv;
    
public:
    OddEven(int range){
        n = range;
        count = 1;
    }
    
    void printEven() {
        while(true){
            unique_lock<mutex> lock(m);

            cv.wait(lock, [this]() {return (count % 2 == 0);});

            if(count > n)
                return;

            cout << "Even thread prints : " << count << endl;
            count++;
            
            cv.notify_all();
        }
    }
    
    void printOdd() {
        while(true){
            unique_lock<mutex> lock(m);
            
            cv.wait(lock, [this]() {return count > n && (count % 2 != 0);});
            
            if(count > n)
                return;
            
            cout << "Odd thread prints : " << count << endl;
            count++;
            
            cv.notify_all();
        }
    }
};



int main() {
    printOddEven();
    // OddEven obj(15);
    
    // thread even(&OddEven::printEven, &obj);

    // thread odd(&OddEven::printOdd, &obj);
    
    // odd.join();
    // even.join();
    
    return 0;
}

// Write a program to build 64-bit timer on a 32-bit architecture machine ?


// Write a program to pritn numbers sequentially using two threads where one thread prints odd and other even ?

