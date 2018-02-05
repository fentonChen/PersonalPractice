//multi_time.cpp
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

int64_t rtmp_stat_gettime(void) {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (int64_t)tv.tv_sec * 1000000 + tv.tv_usec;
}

int main() {
  int64_t cur_time = rtmp_stat_gettime();
  printf("cur_time is %lld \n", cur_time);
  return 0;
}
