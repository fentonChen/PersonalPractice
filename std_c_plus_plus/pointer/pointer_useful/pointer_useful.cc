//pointer_useful.cc

#include <iostream>
#include <stdlib.h>

int main() {
  int* a_ptr = (int*)malloc(sizeof(int));
  *a_ptr = 11;
  int* b_ptr = a_ptr;
  if (b_ptr != NULL) {
    std::cout <<"b_ptr = " << *b_ptr << std::endl;  
  }
  if (a_ptr) {
    std::cout <<"a_ptr = " << a_ptr << std::endl;
    free(a_ptr);
    a_ptr = NULL;
  }
  if (b_ptr != NULL) {
    std::cout <<"b_ptr is not null\n";  
    std::cout <<"b_ptr is " << b_ptr << std::endl;
  }

  return 0;  
}
