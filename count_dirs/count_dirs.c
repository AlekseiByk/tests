#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/sendfile.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>

int count_dir (char * path);
int print_dir (char *path);

int main(int argc, char ** argv){
	if ((argc < 2) || (argc > 2)){
		printf ("not right program start\n%s <dir> <dir>\n", argv[0]);
		exit (1);
	}

	errno = 0;
	int dir1_fd = open (argv[1], O_DIRECTORY);
	if (dir1_fd == -1){
		perror ("open error");
		exit (EXIT_FAILURE);
	}

	printf ("number of files and directories in \"%s\" is %d\n", argv[1], count_dir (argv[1]));

	print_dir (argv[1]);


	return 0;
}

int count_dir (char *path){

	DIR* dir = opendir(path);

	struct dirent *dirstruct = NULL;
	int count = 0;

	while ((dirstruct = readdir (dir)) != NULL)
		if (strcmp(dirstruct->d_name, "..") && strcmp(dirstruct->d_name, ".")){
			count++;
		}
	return count;
}

int print_dir (char *path){

	DIR* dir = opendir(path);

	struct dirent *dirstruct = NULL;
	int count = 0;

	while ((dirstruct = readdir (dir)) != NULL)
		if ((dirstruct->d_type) == DT_DIR){
			printf ("%s\n", dirstruct->d_name);
		}
	return 0;
}