#include <stdio.h>

int factorial(int j) {
	if(j==0 || j==1) {
		return 1;
	}
	
	
	return j*factorial(j-1);	
}

int main() {
	int i;
	for(i=1;i<=20;i++) {
		printf("Factorial of %d is %d\n",i,factorial(i));
	}
return 0;
}





