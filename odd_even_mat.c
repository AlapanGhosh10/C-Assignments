#include<stdio.h>
int main() {
	int size;
	printf("Enter the number of total elements: ");
	scanf("%d", &size);
	int odd[size], even[size], in;
	int a = 0, b = 0;
	for(int i = 0 ; i < size ; i++) { 
		scanf("%d", &in);
		if(in % 2 == 0)
			even[b++] = in;
		else
			odd[a++] = in;
	}
	int odds = sizeof(odd) / sizeof(int);
	int evens = sizeof(even) / sizeof(int);
	printf("%d %d", odds, evens
	
