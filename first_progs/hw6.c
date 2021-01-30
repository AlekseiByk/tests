#include <stdio.h>
#include <math.h>

float func(int a,int n,int m){
	static float sum;
	sum=sum+1/(a*pow(n,m));
	if (n=1)	return(sum);
	else 	    return(func(a,n-1,m));
	
} 

void main(void){
	
	float s;
	
	s=func(2,1,3);
	printf("%f\n", s);
	}