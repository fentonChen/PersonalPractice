//example.h
//
//Implement a general mothed about the std::thread use with smart pointer. Also
//note that the thread's callback method belongs to the class.
//
//execute:
//g++ example.cc -o example.out -std=c++11 -pthread

#include <iostream>
#include <thread>
#include <memory>

class ThreadExample {
  public:
    ThreadExample();
    ~ThreadExample();
  private:
    void ThreadCallback();
    //std::unique_ptr<std::thread> thread_{nullptr};  
    std::thread thread_(&ThreadExample::ThreadCallback, this);  
};
