#include<stdio.h>
#include<math.h>
int main() {
	int size;
	printf("Enter the number of total elements: ");
	scanf("%d", &size);
	int arr[size], odd[size], even[size], n, index;
	int a = 0, b = 0;
	for(int i = 0 ; i < size ; i++)
		scanf("%d", &arr[i]);
	for(int i = 0 ; i < size ; i++) { 
		if(arr[i] % 2 == 0)
			even[b++] = arr[i];
		else
			odd[a++] = arr[i];
	}
	if(a < b)
		n = a;
	else
		n = b;
	n = sqrt(n);
	int odds[n][n], evens[n][n];
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			index = i * n + j;
			odds[i][j] =  odd[index];
			evens[i][j] = even[index];
		}
	}
	printf("\nODD MATRIX\n");
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++)
			printf("%d ", odds[i][j]);
		printf("\n");
	}
	printf("\nEVEN MATRIX\n");
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++)
			printf("%d ", evens[i][j]);
		printf("\n");
	}
	printf("\nEVEN MATRIX + ODD MATRIX\n");
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) 
			printf("%d ", evens[i][j] + odds[i][j]);
		printf("\n");
	}
	printf("\nEVEN MATRIX - ODD MATRIX\n");
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++)
			printf("%d ", evens[i][j] - odds[i][j]);
		printf("\n");
	}
	return 0;
}
	
