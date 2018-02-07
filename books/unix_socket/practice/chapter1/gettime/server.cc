#include <time.h>
#include <stdio.h>

#include "unp.h"

int main(int agrc, char **agrv) {
  int    listenfd, connfd;
  struct sockaddr_in servaddr;
  char   buff[MAXLINE];
  time_t ticks;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(13);    // daytime server
  
  bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

  listen(listenfd, LISTENQ);

  for ( ; ; ) {
    connfd = accept(listenfd, (SA *) NULL, NULL);
     
    ticks = time(NULL);
    snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
    write(connfd, buff, strlen(buff));

    close(connfd);
  }  

  return 0;
}
