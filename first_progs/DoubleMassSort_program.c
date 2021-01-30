#include <stdio.h>


void main(void)
{
	int among[5][3]={{10,2,5},{1,1,4},{2,5,6},{7,9,11},{7,8,10}};
	int size1 = sizeof(among)/sizeof(among[0]);
	int size2 = sizeof(among[0])/sizeof(int);
	
	
	for (int i=0; i < size1; i++)			//вывод двухмерного массива на экран
	{
		for (int j=0; j < size2; j++)
		{
			printf("%d ", among[i][j]);
		}
		printf("\n");
	}
	
	
	int number=0;							//сортировка
	int count=0;
	int b[size2];
	for (int i=0; i < size1; i++)
	{
		number=0;
		for (int j=0; j < size1-i; j++)
		{
			count=0;
			for (int h=0; h < size2; h++)
			{
				if (count==0)
				{
					if (among[j][h] > among[number][h]) 
					{
						number=j;
						count=1;
					}
					if (among[j][h] < among[number][h])	count=1;
				}
			}
		}
		for (int f=0; f < size2; f++)		//замена строки
		{
			b[f]=among[size1-1-i][f];
			among[size1-1-i][f]=among[number][f];
			among[number][f]=b[f];
		}
	}
	
	
	printf("\n\n");
	
	
	for (int i=0; i < size1; i++)			//вывод полученного массива на экран
	{
		for (int j=0; j < size2; j++)
		{
			printf("%d ", among[i][j]);
		}
		printf("\n");
	}
}