#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printMass(int* a,int size)
{
	
	for (int i=0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int* mergeSort(int a[], int count, int numbers)
{
	int j=0; 
	int i=0;
	int m=0;
	int answer[count];
	while (m < count)
	{
		j = numbers/2;
		i = 0;
		
		while (i + j < numbers*3/2)
		{
			if (i != numbers/2)
			{
				if (j != numbers)
				{
					if (a[m+i] >= a[m+j])
					{
						answer[m+i+j-numbers/2]=a[m+j];
						j++;
					}
					if (a[m+i] < a[m+j])
					{
						answer[m+i+j-numbers/2]=a[m+i];
						i++;
					}
				}
				else
				{
					answer[m+i+j-numbers/2]=a[m+i];
					i++;
				}
			}
			else
			{
				answer[m+i+j-numbers/2]=a[m+j];
				j++;	
			}
		}
		m = m + numbers;
	}
	if (numbers==count){printMass(answer, 16);}
	else {mergeSort( answer, 16, 2*numbers);}
}

void main()
{
	srand(time(NULL));
	int among1[32];
	for (int k=0; k < 16; k++)
	{
	among1[k] =rand();
	}
	printMass(among1, 16);
	mergeSort( among1, 16, 2);
}

