
#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;
using ThreadID = std::thread::id;


class WaitForGraph {
private:
    mutex gMutex;
    
};




class DDMutex {
private:
    std::mutex mMutex;
    ThreadID mOwnerID;
    bool mIsOwned = false;

public:
    void Lock(){
        ThreadID currTID = std::this_thread::get_id();
        // WaitForGraph::get().AddNode(currTID);

        if (mIsOwned)
        {
        // WaitForGraph::get().AddEdge(mOwnerID, currTID);
        }

        mMutex.lock();
        mOwnerID = currTID;
        mIsOwned = true;
    }

    // The Unlock method will undo what the Lock has done.

public:
    void Unlock(){
        // WaitForGraph::get().RemoveNode(mOwnerID);
        mIsOwned = false;
        mMutex.unlock();
    }
};

int main()
{
  DDMutex m1, m2;

  std::vector<std::thread> threads;

  threads.emplace_back([&m1, &m2]()
                       {
                         m1.Lock();
                         m2.Lock();
                         std::this_thread::sleep_for (std::chrono::seconds(1));
                         m1.Unlock();
                         m2.Unlock();
                       });
  
  threads.emplace_back([&m1, &m2]()
                       {
                         m2.Lock();
                         m1.Lock();
                         std::this_thread::sleep_for (std::chrono::seconds(1));
                         m2.Unlock();
                         m1.Unlock();
                       });

  for (auto& th : threads)
  {
    if (th.joinable())
    {
      th.join();
    }
  }

  return 0;
}