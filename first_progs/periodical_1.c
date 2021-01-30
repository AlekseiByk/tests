#include <stdio.h>
#include <math.h>
#include <string.h>

int hasPeriod (char *str,char* period)
	{
		int a=0;
		if (strlen(str)%strlen(period) == 0)
		{
			a=1;
			for (int i=0; i < strlen(str)-strlen(period)+1; i=i+strlen(period))
			{
				if (strlen ( strstr (str+i,period)) != strlen(str+i) ){
					a=0;
				}
			}
		}
	return (a);		
	}




void main(void)
{
	char b[1000];
	scanf("%s", b);
	int answer=0;
	for (int i=strlen(b)-1; i >= strlen(b)/2; i--)
	{
		if (answer==0) 
		{
			answer=hasPeriod(b,b+i);
		}
	}
	printf("%d\n",answer);
}