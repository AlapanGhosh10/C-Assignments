#include<stdio.h>
#include<math.h>
void print(int *, int);
int main() {
	int size;
	printf("Enter the number of total elements: ");
	scanf("%d", &size);
	if(size < 8) {
		printf("Try above 8 next time.\n");
		return 0;
	}
	int arr[size], odd[size], even[size], n, index;
	int a = 0, b = 0;
	printf("Enter elements.\n");
	for(int i = 0 ; i < size ; i++)
		scanf("%d", &arr[i]);
	for(int i = 0 ; i < size ; i++) { 
		if(arr[i] % 2 == 0)
			even[b++] = arr[i];
		else
			odd[a++] = arr[i];
	}
	n = a > b ? b : a;
	n = sqrt(n);
	if(n < 2) {
		printf("Try adding 4 or more evens and odds respectively.\n");
		return 0;
	}
	int odds[n][n], evens[n][n], sums[n][n], subs[n][n], muls[n][n];
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			index = i * n + j;
			odds[i][j] =  odd[index];
			evens[i][j] = even[index];

		}
	}
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			sums[i][j] = odds[i][j] + evens[i][j];
			subs[i][j] = odds[i][j] - evens[i][j];
		}
	}
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			muls[i][j] = 0;
			for(int k = 0 ; k < n ; k++)
				muls[i][j] += odds[i][k] * evens[k][j];
		}
	}
	printf("\nODD MATRIX\n");
	print((int *)odds, n);
	printf("\nEVEN MATRIX\n");
	print((int *)evens, n);
	printf("\nODD MATRIX + EVEN MATRIX\n");
	print((int *)sums, n);
	printf("\nODD MATRIX - EVEN MATRIX\n");
	print((int *)subs, n);
	printf("\nODD MATRIX * EVEN MATRIX\n");
	print((int *)muls, n);
	return 0;
}
void print(int *arr, int n) {
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) 
			printf("%d ", *((arr + i * n)  + j));
		printf("\n");
	}
}
