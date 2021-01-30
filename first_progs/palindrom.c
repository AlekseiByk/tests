#include <stdio.h>
#include <math.h>
#include <string.h>


void main(void)
{
	char b[100];
	scanf("%s", b);
	int f=strlen(b);
	int a=1;
	for (int i=0;i <= f/2; i++)
	{
	if (b[i] != b[f-1-i]) a=0;
	}
	printf("%d\n",a);
}