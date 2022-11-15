#include<stdio.h>
int main() {
	int choice;
	printf("Enter 1 to convert C to F.\nEnter 2 to convert F to C.\n");
	scanf("%d", &choice);
	double tempIn, tempOut;
	switch(choice) {
		case 1: printf("Enter the temperature in fahrenheit: ");
			scanf("%lf", &tempIn);
			tempOut = tempIn * (9.0 / 5.0) + 32.0;
			if(tempOut < 0)
				tempOut = 0;
			printf("The temperature in celsius: %lf\n", tempOut);
			break;
		case 2: printf("Enter the temperature in celsius: ");
			scanf("%lf", &tempIn);
			tempOut = (tempIn - 32.0) * (5.0 / 9.0);
			if(tempOut < 0)
				tempOut = 0;
			printf("The temperature in fahrenheit: %lf\n", tempOut);
			break;
		default: printf("Wrong Choice.");
	}
	return 0;
}

