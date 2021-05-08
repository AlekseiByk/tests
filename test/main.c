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

		int sk = socket(AF_INET, SOCK_DGRAM, 0);
		if (sk == -1)
			perror("socket fail");

		struct sockaddr_in addr = {
			.sin_family = AF_INET,
			.sin_port	= htons(8000),
			.sin_addr	= htonl(INADDR_ANY)
		};

		char buf[16];

		int ret = bind(sk, (struct sockaddr*) &addr, sizeof(addr));
		if (ret == -1)
			perror("bind fail");
		unsigned int size = sizeof(addr);
		recvfrom(sk, buf, sizeof(buf), 0, (struct sockaddr*) &addr, &size);
		if (ret == -1)
			perror("recv fail");



		printf ("%s", buf);

/*
		int sk = socket (PF_INET, SOCK_STREAM, 0);
		struct sockaddr_in addr = {
			.sin_family = AF_INET,
			.sin_port	= htons(8000),
			.sin_addr	= htonl(0x7F000001)
		};

		int ret = connect (sk, (struct sockaddr*) &addr, sizeof(addr));

		printf("connect return %d", ret);
*/
	}
	else{
/*		
		int sk = socket(AF_INET, SOCK_DGRAM, 0);
		if (sk < 0)
			perror("socket fail");

		struct sockaddr_in addr = {
			.sin_family = AF_INET,
			.sin_port	= htons(8000),
			.sin_addr	= htonl(0xffffffff)
		};

		int a = 1;
		int ret = setsockopt(sk, SOL_SOCKET, SO_BROADCAST, &a, sizeof(a));
		if (ret == -1)
			perror("setsockopt fail");																																																																							while (1) {};

		char buf[16] = "Hello world!...";

		sendto(sk, buf, sizeof(buf), 0,(struct sockaddr*) &addr, sizeof(addr));
		if (ret == -1)
			perror("sendto error");
*/
		int sk = socket(PF_INET, SOCK_STREAM, 0);

		struct sockaddr_in addr = {
			.sin_family = AF_INET,
			.sin_port	= htons(8000),
			.sin_addr	= htonl(INADDR_ANY)
		};

		bind(sk, (struct sockaddr*) &addr, sizeof(addr));

		listen(sk, 256);

		int sk2 = accept(sk, (struct sockaddr*) &addr, sizeof(addr));

		printf("accept returned %d", sk2);
	}

	return 0;
}

int takenumber (char * str)
{
	char *strptr = NULL, *endptr = NULL;

	long input = 0;
	input = strtol(str, &endptr, 10);
 
 --------------------------------------------------------------------------------------------------------------------------------------------
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
