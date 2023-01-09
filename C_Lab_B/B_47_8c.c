#include<stdio.h>
void print(int *, int);
int main() {
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];
	for(int i = 0 ; i < n ; i++) 
		scanf("%d", &arr[i]);
	print(arr, n);
	return 0;
}

void print(int *a, int size) {
	for(int i = 0 ; i < size ; i++)
		printf("%d", a[i]);
}
