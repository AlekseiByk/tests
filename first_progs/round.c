#include <stdio.h>
#include <math.h>

void main(void){
	for (int r;r != 1;){
	
	scanf("%d", &r);
	int a=r+5;
	int b=r+5;
	for (int y = 0; y <= 2*r+10; y++)
	{
		for (int x = 0; x <= 2*r+10; x++)
		{
			if (abs(r*r - (x-a)*(x-a) - (y-b)*(y-b)) <= r*0.8) {printf("00");}
			else {printf("  ");}
		}
	printf("\n");
	}

}}