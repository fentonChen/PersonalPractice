#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <cstring>
#include <pthread.h>

std::mutex iomutex;
void f(int num) {
  while (1) {
    sched_param sch;
    int policy;
    pthread_getschedparam(pthread_self(), &policy, &sch);
    std::lock_guard<std::mutex> lk(iomutex);
    std::cout << "Thread " << num << " is executing at priority "
              << sch.sched_priority << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

int main() {
  std::thread t1(f, 1), t2(f, 2);

  // get the min&max scop of priority of the current policy
  int max_priority = sched_get_priority_max(SCHED_FIFO);
  int min_priority = sched_get_priority_min(SCHED_FIFO);
  {
  std::lock_guard<std::mutex> lk(iomutex);
  std::cout <<"min_priority of SCHED_FIFO is " << min_priority <<std::endl;
  }
  // reset the priority and policy of the indicate thread
  sched_param sch;
  sch.sched_priority = max_priority;
  if (pthread_setschedparam(t1.native_handle(), SCHED_FIFO, &sch)) {
      std::cout << "Failed to setschedparam: " << std::strerror(errno) << '\n';
  }

  // recheck the policy and priority of the indicated thread te see if the 
  // update was useful ?
  std::this_thread::sleep_for(std::chrono::seconds(2));
  int policy;
  pthread_getschedparam(t1.native_handle(), &policy, &sch);

  if (policy == SCHED_OTHER) {
    std::cout <<" policy is SCHED_OTHER" << std::endl;
  } else if (policy == SCHED_RR) {
    std::cout <<" policy is SCHED_RR" << std::endl;
  } else if (policy == SCHED_FIFO) {
    std::cout <<" policy is SCHED_FIFO, priority = " << sch.sched_priority 
              << std::endl;
  }

  t1.join(); t2.join();
}
