//a.cc
#include "a.h"
#include "b.h"
#include <iostream>

int main() {
  A::a = 10;
  A::b = 11;
  B::c = 12;
  B::d = 13;
  std::cout <<"a = " << A::a << std::endl;
}
