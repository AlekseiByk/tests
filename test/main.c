#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <malloc.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <ifaddrs.h>


/*
int main() {
    printf("%f\n", exp(0));
    return 0;
}
*/
int takenumber (char * str);

int main(int argc, char ** argv) {

	if (argc < 2) {
		printf("Too less arguments\n");
		return -1;
	} else if (argc > 2) {
		printf("Too many arguments\n");
		return -2;
	}

	int input = takenumber (argv[1]);

	if (input == 1){

		int sk_udp = socket(AF_INET, SOCK_DGRAM, 0);
		if (sk_udp == -1)
			perror("socket fail");

		struct sockaddr_in addr1 = {
			.sin_family = AF_INET,
			.sin_port	= htons(8000),
			.sin_addr	= htonl(INADDR_ANY)
		};

		char buf[sizeof(struct sockaddr)];

		int ret = bind(sk_udp, (struct sockaddr*) &addr1, sizeof(addr1));
		if (ret == -1)
			perror("bind fail");
		unsigned int size = sizeof(addr1);
		recvfrom(sk_udp, buf, sizeof(struct sockaddr), 0, (struct sockaddr*) &addr1, &size);
		if (ret == -1)
			perror("recv fail");

			printf("a\n");
			fflush(0);

///////////////////////////////////////////

		int sk = socket (PF_INET, SOCK_STREAM, 0);
		struct sockaddr_in addr = {
			.sin_family = AF_INET,
			.sin_port	= htons(8000),
			.sin_addr	= htonl(0xC0A8006C)
		};

		struct ifaddrs *ifap;

		ret = getifaddrs (&ifap);
		if (ret == -1)
			perror("getifaddr error");

		printf("%d\n", sizeof (struct sockaddr)); //htonl(inet_addr("192.168.0.108"))
		
		
		ret = connect (sk, (struct sockaddr*) buf, sizeof(struct sockaddr));
		if (ret == -1)
			perror("connect fail");

		printf("connect return %d", ret);

	}
	else{
		
		int sk_udp = socket(AF_INET, SOCK_DGRAM, 0);
		if (sk_udp < 0)
			perror("socket fail");

		struct sockaddr_in addr1 = {
			.sin_family = AF_INET,
			.sin_port	= htons(8000),
			.sin_addr	= htonl(0xffffffff)
		};

		int a = 1;
		int ret = setsockopt(sk_udp, SOL_SOCKET, SO_BROADCAST, &a, sizeof(a));
		if (ret == -1)
			perror("setsockopt fail");

		struct ifaddrs *ifap;

		ret = getifaddrs (&ifap);
		if (ret == -1)
			perror("getifaddr error");

		printf("%d\n", sizeof (struct sockaddr)); //htonl(inet_addr("192.168.0.108"))

		sendto(sk_udp, ifap -> ifa_addr, sizeof(struct sockaddr), 0,(struct sockaddr*) &addr1, sizeof(addr1));
		if (ret == -1)
			perror("sendto error");
//////////////////////////////////////////////////////////////
		int sk = socket(PF_INET, SOCK_STREAM, 0);
		if (sk == -1)
			perror ("socket");

		printf ("socket");
		fflush(0);

		struct sockaddr_in addr = {
			.sin_family = AF_INET,
			.sin_port	= htons(8000),
			.sin_addr	= htonl(INADDR_ANY)
		};

		printf("binding\n");
		fflush(0);

		ret = bind(sk, (struct sockaddr*) &addr, sizeof(addr));
		if (ret = -1)
			perror("bind error");

		printf("listening\n");
		fflush(0);

		listen(sk, 256);
		if (ret = -1)
			perror("listen error");

		printf("accepting\n");
		fflush(0);			

		unsigned int size = sizeof(addr);
		int sk2 = accept(sk, (struct sockaddr*) &addr, &size);
		if (ret = -1)
			perror("accept error");

		printf("accept returned %d", sk2);
	}

	return 0;
}

int takenumber (char * str)
{
	char *strptr = NULL, *endptr = NULL;

	long input = 0;
	input = strtol(str, &endptr, 10);
 
//-------------------------------------------------------------
	if (endptr == strptr || *endptr != '\0') {
		printf("Wront input string\n");
		exit (-3);
	}
 
	if (errno == ERANGE && (input == LONG_MAX || input == LONG_MIN)) {
		printf("Out of range\n");
		exit(-5);
	}

	return input;
}
