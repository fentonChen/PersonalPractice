//lambda_thread
//
//Created by fenton.c@outlook.com
//Compile:
//  g++ lam_thd.cc -o lam_thd.out -std=c++11 -pthread
#include <iostream>
#include <thread>

using namespace std;

int main() {
   bool in_data = true; 
   std::thread t1([&] () {
     if (in_data) {
       cout <<"in_data is " << in_data << endl;  
     }  
   });
   t1.join();
}
