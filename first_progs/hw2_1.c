#include <stdio.h>
#include <math.h>

float func(float min,float max){
	static int n;
	n++;
	if (fabs(max*max - 10)<= 0.0001)	return(max);
	else 		if ((max + min)*(max + min)/4 > 10)  return(func( min, (min+max)/2));
			   else 
		    return(func( (min+max)/2, max)); 
	
} 

void main(void){
	
	float s;
	
	for (int i=0;i<1;i++){	s=func(0,10);	}
	printf("%4.3f\n", s);
	}