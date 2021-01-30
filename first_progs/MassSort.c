#include <stdio.h>
#include <math.h>


void printMass(int* a,int size)
{
	
	for (int i=0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
}

void function(int *a, int count)
{
	for (int j = 0; j < count; j++)
	{
		int max = a[0];
		int number = 0;
		for (int i = 1 ; i < count-j; i++)
		{
			if (max < a[i]) 
			{
				max = a[i];
				number = i;
			}
		}
	a[number] = a[count-1-j];
	a[count-1-j] = max;
	}
	printMass( a, count);
}

void main(void)
{
	int among[10]={10,2,49,45,6,74,80,9,1,12};
	function(among, sizeof(among)/sizeof(int));
}