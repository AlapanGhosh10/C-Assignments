#include <stdio.h>
#define SWAP(a, b, temp) (temp = a, a = b, b = temp)

void sort(int *arr, int n)
{
	int arr_max[4], arr_min[6], temp;
	for (int i = 0; i < 4; i++)
		arr_max[i] = -_INT32_MAX_ + 1;
	for (int i = 0; i < 6; i++)
		arr_min[i] = _INT32_MAX_;

	for (int i = 0; i < n; i++)
	{
		int flag=0;
		for(int k=0;k<=3;k++)
		{
			if(arr[i]==arr_max[k]) flag=1;
		}
		if(!flag)
		{
		arr_max[3] = arr[i];
		for (int j = 2; j >= 0; j--)
		{
			if (arr_max[j + 1] > arr_max[j])
			{
				SWAP(arr_max[j + 1], arr_max[j], temp);
			}
		}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int flag=0;
		for(int k=0;k<=6;k++)
		{
			if(arr[i]==arr_min[k]) flag=1;
		}
		if(!flag)
		{
		arr_min[5] = arr[i];
		for (int j = 4; j >= 0; j--)
		{
			if (arr_min[j + 1] < arr_min[j])
			{
				SWAP(arr_min[j + 1], arr_min[j], temp);
			}
		}
		}
	}

	printf("\nThird max is %d.\n", arr_max[2]);
	printf("Fifth min is %d.\n", arr_min[4]);
	printf("Middle element of the array is %d.\n", arr[n / 2]);
}

int main()
{
	int n;
	printf("Enter the size of array:--");
	scanf("%d", &n);
	int arr[n];
	printf("\n enter the array elements:--\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
		printf("\n The elements are--\n");
	for (int i = 0; i < n; i++)
		printf("%d  ", arr[i]);

	sort(arr, n);
	return 0;
}
