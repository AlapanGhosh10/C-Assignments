#include<stdio.h>
#include<math.h>
long long int arr[71];
long long int fibo(int);
long double fiboo(int);
int main() {
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	long long int res = fibo(n);
	printf("%lld\n", res);
	long double fout = fiboo(n);
	printf("%Lf\n", fout);
	return 0;
}

long long fibo(int n) {
	if(arr[n] != 0)
		return arr[n];
	if(n < 3)
		return 1;
	long long int f = fibo(n-1) + fibo(n - 2);
       	arr[n] = f;	
	return f;
}

long double fiboo(int n) {
	long double fv = sqrt(5);
	long double a = (1.0 + fv) / 2.0;
	long double b = (1.0 - fv) / 2.0;
	a = pow(a, n);
	b = pow(b, n);
	long double res = (1.0/fv) * (a - b);
	return res;
}
