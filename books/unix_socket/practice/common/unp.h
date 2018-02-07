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

#endif
