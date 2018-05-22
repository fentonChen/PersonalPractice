//main.cc
#include <iostream>
#include <chrono>
#include <ratio>
//#include <ctime>

int main() {
  using namespace std::chrono;

  steady_clock::time_point t1 = steady_clock::now();
  
  for (int i=0; i<1000; i++) {
    for (int j=0; j<5000; j++)
    std::cout << "*";
  }
  std::cout << std::endl;

  steady_clock::time_point t2 = steady_clock::now();
  
  milliseconds time_span = duration_cast<milliseconds>(t2-t1);

   
  std::cout << "It took me " << time_span.count() << "milliseconds.";
  std::cout << std::endl;
}
