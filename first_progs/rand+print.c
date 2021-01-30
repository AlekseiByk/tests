#include <stdio.h>
#include <malloc.h>
#include <time.h>

void print2D(void* arr, int n, int m)
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%d ", *((int*)arr+i*m+j));
		}
		printf("\n");
	}
}


void main() {
	srand(time(NULL));
	int* arr = (int*) calloc(15,sizeof(int));
	for (int i=0; i < 15; i++)
	{
		*(arr+i) = rand();
	}
	
	print2D(arr, 5, 3);
	

}