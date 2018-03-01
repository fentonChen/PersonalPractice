//other-exe.cc
//just printf a number of pid
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("I'm a new execute program, my pid = %d\n", getpid());
    return 0;
}
