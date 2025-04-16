#include <stdio.h>
#include <stdlib.h>

int main() {

	int i,j,k,row,column,r;
	
	printf("Enter row number: ");
	scanf("%d" ,&row);
	
	printf("Enter column number: ");
	scanf("%d" ,&column);
	
	printf("\n");

for(i=0;i<row;i++) {
	printf(" ");
}
	printf("@\n");

for(r=0;r<column;r++) {
	for(i=row-r;i>0;i--) {
		if(i==1) {
			printf("@"); 
		}
		for(j=i+1;j>1;j--) {
		
			printf(" ");
		}
		
	if(i==1) {
		for(k=row-i;k>0;k--) {
			printf("* ");
		}
		printf("@");
	}
	else {
		for(k=row-i+1;k>0;k--) {
			printf("* ");
		}
	}
		printf("\n");
	}
}
system("COLOR 04");
for(i=0;i<row;i++) {
	for(j=row/3*2;j>0;j--) {
		printf(" ");
	}
	for(k=row/3;k>0;k--) {
		printf("* ");
	}
	printf("\n");
}



return 0;
}

