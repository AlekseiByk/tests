#include <stdio.h>
#include <math.h>

int simple(int m,int a){
	if (a <= sqrt(m)) {
	if (m % a == 0) return(0);
	else return(simple(m,a+1));
	}
	else return(m);
	
} 

void func(int n){
	for (int i=0;n-i>=2;i++){
	if (simple(n-i,2) ==n-i) printf("%d\n",n-i);
	}
}

void main(void){

	func(100);
	}