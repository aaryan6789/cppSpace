#include <iostream>
#include <thread>



void thread_function()
{
    for(int i = 0; i < 1000000; i++);     // Just For Sleeping
    
    std::cout<<" thread function Executing"<<std::endl;
}

class DisplayThread
{
public:
    void operator()()     
    {
        for(int i = 0; i < 10; i++)
            std::cout<<"Display Thread Executing"<<std::endl;
    }
};

void thread_function_ID(){
    std::cout<<"Inside Thread :: ID  = "<<std::this_thread::get_id() << std::endl;    
}

int thread_id_demo()  
{
    std::thread threadObj1(thread_function_ID);
    std::thread threadObj2(thread_function_ID);
 
    if(threadObj1.get_id() != threadObj2.get_id())
        std::cout<<"Both Threads have different IDs"<<std::endl;
 
    std::cout<<"From Main Thread :: ID of Thread 1 = "<<threadObj1.get_id()<<std::endl;    
    std::cout<<"From Main Thread :: ID of Thread 2 = "<<threadObj2.get_id()<<std::endl;    
 
    threadObj1.join();    
    threadObj2.join();    
    return 0;
}

// Implemented in thread_2
int thread_join();
int thread_pass_arguments();
int thread_race_condition_demp();
int thread_cv_mutex();

int main(){
    // 1. Creating a thread using Function Pointer
    std::thread threadObj1(thread_function);
    for(int i = 0; i < 1000000; i++);     // Just For sleeping
        
    std::cout<<"Display From MainThread"<<std::endl;

    threadObj1.join();    

    std::cout<<"Exit of Main function"<<std::endl;
    // ------------------------------------------------------------------------

    // 2. Creating a thread using Function Objects
    std::thread threadObj2( (DisplayThread()) );
    for(int i = 0; i < 5; i++)
        std::cout<<"Display From Main Thread "<<std::endl;
    
    std::cout<<"Waiting For Thread2 to complete"<<std::endl;
    
    threadObj2.join();
    std::cout<<"Exiting from Main Thread"<<std::endl;
    // ------------------------------------------------------------------------

    // 3. Creating a thread using Lambda functions
    int x = 9;
    std::thread threadObj3([]{
                        for(int i = 0; i < 10; i++)
                            std::cout<<"Display Thread Lambda Executing"<<std::endl;
                        });
            
    for(int i = 0; i < 5; i++)
        std::cout<<"Display From Main Thread \n"<<std::endl;
        
    threadObj3.join();
    std::cout<<"Exiting from Main Thread \n"<<std::endl;

    thread_id_demo();

    thread_join();
    thread_pass_arguments();
    thread_race_condition_demp();

    thread_cv_mutex();
    
    return 0;
}