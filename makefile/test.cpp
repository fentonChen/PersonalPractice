//test.c

//#include <stdio.h>
#include "test.h"
#include "test2/test2.h"

int main() {
  int i=1;
  printf("Hello World");

  A atest;
  atest.setI(5);
  int geti = atest.getI();
  std::cout <<" get i is :" << geti << std::endl; 
  return 0;
}
