
#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

class WorkerThread {
public:
    void operator()()     {
        cout <<"Worker Thread "<< this_thread::get_id() << " is Executing"<<endl;
    }
};

int thread_join()  {
    cout << "\n Thread JOINING AND DETACHING" << endl;
    vector<thread> threadList;
    for(int i = 0; i < 10; i++){
        threadList.push_back( thread( WorkerThread() ) );
    }

    // Now wait for all the worker thread to finish i.e.
    // Call join() function on each of the thread object
    
    cout<<"wait for all the worker thread to finish"<<endl;

    // Note: Have to Have to use & otherwise it wont be able to join
    for(auto& fn : threadList){
        // before calling join() or detach() we should check if thread is join-able every time i.e.
        if(fn.joinable())
            fn.join();
    }

    // for_each(threadList.begin(),threadList.end(), mem_fn(&thread::join));
    cout<<"Exiting from Main Thread"<<endl;
    return 0;
}