#include <iostream>
#include <thread>
using namespace std;

/**
 * How not to pass arguments to threads in C++11 ? 
 * 
 * Don’t pass addresses of variables from local stack to thread’s callback 
 * function. 
 * 
 * Why ? 
 * Because it might be possible that local variable in Thread 1 goes out of 
 * scope but Thread 2 is still trying to access it through it’s address.
 * 
 * In such scenario accessing invalid address can cause unexpected behaviour.
 */
void newThreadCallback(int *p)
{
    cout<<"Inside Thread :  "" : p = "<< p <<endl;
    chrono::milliseconds dura( 1000 );
    this_thread::sleep_for( dura );
    
    *p = 19;
}
void startNewThread()
{
    int i = 10;
    cout<<"Inside Main Thread :  "" : i = "<<i<<endl;
    thread t(newThreadCallback, &i);
    t.detach();
    cout<<"Inside Main Thread :  "" : i = "<<i<<endl;
}

int thread_pass_arguments()
{
    startNewThread();
    chrono::milliseconds dura( 2000 );
    this_thread::sleep_for( dura );
    return 0;
}