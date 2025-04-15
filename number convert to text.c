#include <stdio.h>
int main() {

	int num,i,arr[100],count=0,j;
	printf("Enter a number: ");
	scanf("%d" ,&num);
	
	if(num==0) {
		printf("zero");
	}
	else if(num<0) {
		num=num*(-1);
		printf("-");
	}
	
	for(i=num;num>0;num=num/10) {
		count=count+1;
	}
	
	for(j=0;j<count;j++) {
		arr[j]=i%10;
		i=i/10;	   
	}

	for(j=count-1;j>=0;j--) {
		switch(arr[j]) {
			case 0:
				printf("zero ");
				break;
			case 1:
				printf("one ");
				break;
			case 2:
				printf("two ");
				break;
			case 3:
				printf("three ");
				break;
			case 4:
				printf("four ");
				break;
			case 5:
				printf("five ");
				break;
			case 6:
				printf("six ");
				break;
			case 7:
				printf("seven ");
				break;
			case 8:
				printf("eight ");
				break;
			case 9:
				printf("nine ");
				break;
		}
	}
	
return 0;
}

