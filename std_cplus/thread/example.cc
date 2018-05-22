//example.cc

#include "example.h"

ThreadExample::ThreadExample() {
  thread_.reset(new std::thread(&ThreadExample::ThreadCallback, this));
}

ThreadExample::~ThreadExample() {
  if (thread_.get() != nullptr) {
    thread_->join();  
    thread_=nullptr;
  }
}

//callback funtion, will do something...
void ThreadExample::ThreadCallback() {
  std::cout <<"..............." << std::endl;
}

int main() {
  ThreadExample thread_example;
  return 0;  
}
