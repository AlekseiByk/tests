#include <math.h>
#include <stdio.h>
#include <Windows.h>
int main(void)
{
	long t;
	
	t=GetTickCount();
	
	t=GetTickCount() -t;
	printf("%f\n", ((double)t)/1000000	);
}