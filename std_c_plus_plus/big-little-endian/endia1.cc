//endian1.cc
#include <iostream>
#include <stdio.h>
#include <stdint.h>

struct kt {
#if __BYTE_ORDER == __LITTLE_ENDIAN
  uint8_t version:2;
  uint8_t padding:1;
  uint8_t blockcount:5;
#elif __BYTE_ORDER == __BIG_ENDIAN
  uint8_t blockcount:5;
  uint8_t padding:1;
  uint8_t version:2;
#endif
}
kt;

int main() {
    //origin-data : 126 == 0x7E -- 0111 1110
    //big-endian-storage  : 0xF 0x1 0x2 == 15 1 2
    //little-endian-storage : 0x1E 0x1 0x1 == 30 1 1
    char result = 126;
    memcpy(&kt, &result, 1);
    printf(" blockcount=%d, padding=%d, version=%d,ok\n", 
            kt.blockcount, kt.padding, kt.version);

    return 0;
}
