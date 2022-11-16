#include<stdio.h>
int main() {
	int n;
	printf("Enter the value of n: ");
	scanf("%d", &n);

	long double x = 1.0;
	long double sum = 1.0;
	for(int i = 2 ; i <= n ; i++) {
		x = x * i;
		sum += i / x;
	}
	printf("e = %.5Lf\n", sum);
	return 0;
}
