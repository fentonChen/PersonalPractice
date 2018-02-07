#ifndef __unp_h
#define __unp_h

#include	<unistd.h>
#include	<string.h>
#include	<sys/uio.h>		/* for iovec{} and readv/writev */
#include	<arpa/inet.h>	/* inet(3) functions */
#include  <sys/socket.h>   /* basic socket definitions */
#include	<netinet/in.h>	/* sockaddr_in{} and other Internet defns */

/* Following shortens all the type casts of pointer arguments */
#define	SA	struct sockaddr

/* Miscellaneous constants */
#define	MAXLINE		4096	/* max text line length */

/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
   kernels still #define it as 5, while actually supporting many more */
#define	LISTENQ		1024	/* 2nd argument to listen() */

#endif
