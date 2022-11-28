#include<stdio.h>
int main() {
	long double x;
	printf("Enter value of x: ");
	scanf("%Lf", &x);

	long double a = x;
	long double sum = x;
	for(int i = 1; i < 10000 ; i++) {
		x = (x * (-1) * a * a) / ((2 * i) * (2 * i + 1));
		sum += x;
	}
	printf("sin(%Lf) = %Lf\n", a, sum);
	return 0;
}
