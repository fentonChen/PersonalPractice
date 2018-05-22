//deque1.cpp
//Simulate push_back(), push_front(), size(), and arrary subscript access use.
#include <deque>
#include <iostream>
using namespace std;

int main() {
  deque<float> coll; //deque container for floating-point elements
  
  //insert elements from 1.1 to 6.6 each at the front
  for (int i=1; i<=6; ++i) {
    coll.push_front(i*1.1); //insert at the front  
  }

  //insert elemtns from 10.1 to 16.1 each at the back
  for (float i=10.1; i<=16.1; ++i) {
    coll.push_back(i);      //insert at the back
  }

  //print all elements followed by a space
  for (int i=0; i<coll.size(); ++i) {
    cout << coll[i] << ' ';  
  }
  cout << endl;
}
