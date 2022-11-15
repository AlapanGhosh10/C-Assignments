#include<stdio.h>
int main() {
	long double x;
	printf("Enter value of x: ");
	scanf("%Lf", &x);

	long double a = 1.0;
	long double sum = 1.0;
	for(int i = 1 ; i < 10000 ; i++) {
		a  = (a * (-1) * x * x) / ((2 * i) * (2 * i - 1));
		sum += a;
	}
	printf("cos(%Lf) = %Lf\n", x, sum);
	return 0;
}
