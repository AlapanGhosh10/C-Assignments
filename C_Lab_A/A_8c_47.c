#include<stdio.h>
int main() {
	long double x;
	printf("Enter value of x: ");
	scanf("%Lf", &x);

	long double sum = x;
	long double a = x;
	for(int i = 2 ; i < 10000 ; i++) {
		a = a * -1 * x;
		sum += a / i;
	}
	printf("log(1 + %Lf) = %Lf\n", x, sum);
	return 0;
}
