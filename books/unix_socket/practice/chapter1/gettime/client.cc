#include <stdio.h>
#include "unp.h"

/**
 *  The argv[1] is the ip address of the time server
 */
int main(int argc, char **argv) {
  int    sockfd, n;
  char   recvline[MAXLINE + 1];
  struct sockaddr_in servaddr;

  if (argc != 2) {
    //err_quit("usage: a.out <IPaddress>");
    printf("error agrc !=2\n");
  }

  if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    //err_sys("socket error");
    printf("socket error\n");
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port   = htons(13); // daytime server

  //inet_pthon is a replace of :
  //servaddr.sin_addr.s_addr = inet_addr("192.168.1.0");
  //but inet_addr is a deprecated method as not support with IpV6
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    //err_quit("inet_pton error for %s", argv[1]);
    printf("inet_pton error for %s\n", argv[1]);
  }

  if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0) {
   // err_sys("connect error");
    printf("connect error \n");
  }

  while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
    recvline[n] = 0;         // null terminate
    if (fputs(recvline, stdout) == EOF)
      printf("fputs error\n");
  }
  if (n < 0)
    printf("read error\n");

  return 0;
}
