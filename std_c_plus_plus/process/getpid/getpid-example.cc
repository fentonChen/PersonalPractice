//getpid-example.cc
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("pid = %d\n", getpid());
 
    //call method execl to start a new execute program, and find out if the pid
    //of it are same with current execute program ? if True, there're in one 
    //process
    int ret = execlp("./exe","exe",(char *)0);


    return 0;
}
