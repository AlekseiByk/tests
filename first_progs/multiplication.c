#include <stdio.h>
#include <math.h>
#include <string.h>


void main(void)
{
	char b[75], a[75];
		scanf("%s\n",a);
		scanf("%s",b);
		int fa=strlen(a);
		int fb=strlen(b);
		int balance=0;
		int sum0=0;
		int m=fa+fb;
		
	char answer[m];
		for (int i=0; i < m; i++)
		{
			answer[i]=48;
		}
		printf("%s\n",answer);
		
		for (int x = fa-1; x >= 0; x--)
		{
			for (int y = fb-1; y >= 0; y--)
			{
				sum0=answer[m+y-fb]-48;
				answer[m+y-fb]=(((int)a[x]-48)*((int)b[y]-48) + sum0 + balance)%10 + 48;
				balance=(((int)a[x]-48)*((int)b[y]-48) + sum0 + balance)/10;
				}
			answer[m-fb-1]=balance+48;
			balance=0;
		
			m--;
		}
	printf("%s\n",answer);
	
}