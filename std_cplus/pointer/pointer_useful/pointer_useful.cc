//pointer_useful.cc

#include <iostream>
#include <stdlib.h>

typedef struct RTMP {
  int m_stream_id;
  int m_pausing;
};

struct RTMPSenderImpl {
  RTMP* RTMPInstance;  
};

int main() {
  RTMPSenderImpl * impl = (RTMPSenderImpl*)malloc(sizeof(RTMPSenderImpl));
  impl->RTMPInstance = (RTMP*)malloc(sizeof(RTMP));
  impl->RTMPInstance->m_stream_id = 12;

  RTMP* anotherInstance = impl->RTMPInstance;
  if (anotherInstance) {
    std::cout <<"anotherInstance->m_stream_id is " 
              << anotherInstance->m_stream_id << std::endl;  
  }



  //int* a_ptr = (int*)malloc(sizeof(int));
  //*a_ptr = 11;
  //int* b_ptr = a_ptr;
  //if (b_ptr != NULL) {
  //  std::cout <<"b_ptr = " << *b_ptr << std::endl;  
  //}
  //if (a_ptr) {
  //  std::cout <<"a_ptr = " << a_ptr << std::endl;
  //  free(a_ptr);
  //  a_ptr = NULL;
  //}
  //if (b_ptr != NULL) {
  //  std::cout <<"b_ptr is not null\n";  
  //  std::cout <<"b_ptr is " << b_ptr << std::endl;
  //}

  return 0;  
}
