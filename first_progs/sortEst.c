#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>


typedef void (*sortFunction)(int* array, int n, int k);

float estimator(sortFunction fn);

sortFunction functionArray[0];

void bubbleSort(int* array, int n,int k);
void insertionSort(int* array, int n,int k);
void mergeSort(int* array, int n, int k);

void main()
{
	functionArray[0] = bubbleSort;
	functionArray[1] = insertionSort;
	functionArray[2] = mergeSort;

	for(int i = 2; i >= 0; i--) {
		printf("%g \n", estimator(functionArray[i]) );
	}
}

void bubbleSort(int* a, int count, int k) {
	
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
	
}

void insertionSort(int* a, int n, int k) {
	
	int i, j, value;
	for (j = 1; j < n; j++)
	{
		for (i = 1; i <= j; i++)
		{	
			value = a[j-i+1];	
			if (a[j-i] > value) 
			{
				a[j-i+1] = a[j-i];
				a[j-i]= value;
			}
		}
	}
	
}

void mergeSort(int a[], int count, int numbers)
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
	if (numbers == count){}
	else {mergeSort( answer, 16, 2*numbers);}
}

float estimator(sortFunction fn) {
	
	int testArray[1024];
	long temp1, a, b;
	
	
	for(int i = 0; i < 1024; i++) {
		testArray[i] = rand();
	}
	
	int iterations = 25000;
	
	QueryPerformanceCounter(&temp1);
	a = temp1;
	
	
	
	for(int i = 0; i < iterations; i++) {
		
		fn(testArray, 1024, 2);
	}
	
	QueryPerformanceCounter(&temp1);
	b = temp1;
	
	return (float)(b-a) / iterations;

}