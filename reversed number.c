#include <stdio.h>
int main() {

	int num,i,div;
	printf("Enter a number: ");
	scanf("%d" ,&num);
	
	printf("\nReversed number is: \n");
	
	for(i=num;num>0;num=num/10) {
		div=num%10;
		printf("%d",div);
	}

return 0;
}

