//temp-big-endian.cc
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main() {

    uint32_t a = 0x11223344;
    uint32_t b = 0x11223344;
    uint32_t c = (a << 16) + (b >> 16);
    unsigned char* p = (unsigned char*)(&c);
    printf("the c is :%0x  %0x  %0x  %0x\n", p[0], p[1], p[2], p[3]);


    //uint32_t w = 0x12345678;
    //uint32_t l = 0x11223344;
    //uint64_t t = w;
    //t = t << 32 | l;
    //unsigned char *p = (unsigned char*)(&t);
    //
    //printf("host endian: %0x %0x %0x %0x - %0x %0x %0x %0x\n",
    //    p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
    //printf("not expect : 12345678 - 11223344\n");
    //printf("expect: 44 33 22 11 - 78 56 34 12\n");

    //uint64_t a = 0x1122334412345678;
    //unsigned char *p = (unsigned char*)(&a);

    //printf("host endian: %0x    %0x    %0x    %0x \
    //        %0x    %0x    %0x    %0x\n",
    //        p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
    return 0;
}
