//macro2.cpp
//# operator use with macro
//The # operator causes a replacement-text token to be converted to a string
//surrounded by quotes.
#include <iostream>
using namespace std;

#define MKSTR( x ) #x

int main() {
  cout << MKSTR(HELLO C++) << endl;

  return 0;
}
