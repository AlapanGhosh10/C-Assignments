#include<stdio.h>
int main() {
	int m;
	printf("Enter size of first list: ");
	scanf("%d", &m);
	int arr1[m];
	printf("Enter the content of the first list.\n");
	for(int i = 0 ; i < m ; i++) 
		scanf("%d", &arr1[i]);
	int n;
	printf("Enter size of second list: ");
	scanf("%d", &n);
	int arr2[n];
	printf("Enter the content of the second list.\n");
	for(int i = 0 ; i < n ; i++) 
		scanf("%d", &arr2[i]);
	int res[n + m];
	int i = 0, j = 0, in = 0;
	while(i < m && j < n) 
		if(arr1[i] < arr2[j]) 
			res[in++] = arr1[i++];
		else 
			res[in++] = arr2[j++];
	while(i < m)
		res[in++] = arr1[i++];
	while(j < n)
		res[in++] = arr2[j++];
	printf("The resultant list is.\n");
	for(int k = 0 ; k < in ; k++)
		printf("%d ", res[k]);
	printf("\n");
	return 0;
}
