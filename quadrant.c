#include <stdio.h>
int main() {

	int x,y;
	printf("Enter x and y: ");
	scanf("%d %d" , &x ,&y);
	
	if(x==0 && y==0) {
		printf("The coordinate point(%d, %d) lies in the Origin.",x,y);
	}
	else if(x==0) {
		printf("The coordinate point(%d, %d) lies in the y-axis.",x,y);
	}
	else if(y==0) {
		printf("The coordinate point(%d, %d) lies in the x-axis.",x,y);
	}
	else if(x>0 && y>0) {
		printf("The coordinate point(%d, %d) lies in the First quadrant.",x,y);
	}
	else if(x<0 && y>0) {
		printf("The coordinate point(%d, %d) lies in the Second quadrant.",x,y);
	}
	else if(x<0 && y<0) {
		printf("The coordinate point(%d, %d) lies in the Third quadrant.",x,y);
	}
	else if(x>0 && y<0) {
		printf("The coordinate point(%d, %d) lies in the Fourth quadrant.",x,y);
	}

return 0;
}

