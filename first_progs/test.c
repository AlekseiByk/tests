#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
void printMass(int* a,int size)
{
	
	for (int i=0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void insertSort(int a[], int count)
{	
    int i, j, value;
	for (j = 1; j < count; j++)
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

void mergeSort(int a[], int b[], int count)
{
	int answer[count];
    int i=0, j=0;
	while (j + i <= 19)
	{
		if (j != 10)
		{
			if (i != 10)
			{
				if (a[j] <= b[i]) 
				{
					answer[i+j]=a[j];
					j++;
				}
				
				if (a[j] > b[i]) 
				{
					answer[i+j]=b[i];
					i++;
				}
			}
			else 
			{
				answer[i+j]=a[j];
				j++;
			}
		}
		else 
		{
				answer[i+j]=b[i];
				i++;
		}
	}
	printMass(answer, 20);
}



void main()
{
	srand(time(NULL));
	int among1[10];
	int among2[10];
	for (int k=0; k < 10; k++)
	{
	among1[k] = rand();
	}
	for (int k=0; k < 10; k++)
	{
	among2[k] =rand();
	}
	insertSort( among1, 10);
	printMass(among1, 10);
	insertSort( among2, 10);
	printMass(among2, 10);
	mergeSort( among1, among2, 20);
}
*/

void main()
{
	printf("%d",(int)30/16);
}




/*
массив функций
void function1()
{
	printf("comment1 \n");
}
void function2()
{
	printf("comment2 \n");
}
void function3()
{
	printf("comment3 \n");
}

void main()
{
	void (*arr[3])();
	arr[0] = function1;
	arr[1] = function2;
	arr[2] = function3;
	int i=0;
	
	scanf("%d", &i);
	
	arr[i]();
}
*/

/*
проверка случайности
void main() {
	srand(time(NULL));
	int a1=0;
	int a2=0;
	int a3=0;
	int a4=0;
	int a5=0;
	int n=0;
	for (int i=0; i < 32768; i++)
	{
		n=rand();
		if(n >= 0 && n < 10) a1++;
		if(n >= 10 && n < 100) a2++;
		if(n >= 100 && n < 1000) a3++;
		if(n >= 1000 && n < 10000) a4++;
		if(n >= 10000 && n < 100000) a5++;
	}
	printf("one %d\n", a1);
	printf("two %d\n", a2);
	printf("three %d\n", a3);
	printf("four %d\n", a4);
	printf("five %d\n", a5);

}
*/
