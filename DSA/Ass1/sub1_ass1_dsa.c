#include<stdio.h>
#include<stdlib.h>

int * create(int *arr, int *size) {
	if(*size > 0) {
		printf("The array is already created.\n");
		return arr;
	}
	int n = 1;
	char x;
	printf("Enter elements into array, press x to stop.\n");
	while(scanf("%d", &n)) {
		arr = realloc(arr,(*size + 1) * sizeof(int));
		arr[*size] = n;
		(*size)++;
	}
	scanf("%c", &x);
	return arr;
}	

void display(int *arr, int size) {
	for(int i = 0 ; i < size ; i++) 
		printf("%d ", arr[i]);
	printf("\n");
}

void count(int size) {
	printf("The number of elements in the array is: %d\n", size);
}

void reverse(int *arr, int size) {
	int i = 0, j = size - 1, temp;
	while(i < j) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
	printf("The reversed array is: ");
	display(arr, size);
}

void indexOf(int *arr, int size, int n) {
	printf("%d is present at indices: ", n);
	int present = 0;
	for(int i = 0 ; i < size ; i++) {
		if(arr[i] == n) {
			printf("%d ", i);
			present = 1;
		}
	}
	if(!present)
		printf("None");
	printf("\n");
}

void indexElement(int *arr, int size, int i) {
	if(i < 0 || i >= size) {
		printf("Invalid Index\n");
		return;
	}
	printf("The element at index %d: %d\n", i, arr[i]);
}

int *insert(int *arr, int *size, int n, int i) {
	if(i > *size)
		i = *size;
	if(i < 0)
		i = 0;
	arr = realloc(arr,(*size + 1) * sizeof(int));
	(*size)++;	
	for(int j = *size  ; j > i ; j--) 
		arr[j] = arr[j - 1];
	arr[i] = n;
	printf("The array is: ");
	display(arr, *size);
	return arr;
}

int *delete(int *arr, int *size, int i) {
	if(i > *size || i < 0) {
		printf("Invalid Index\n");
		return arr;
	}
	for(int j = i ; j < *size - 1 ; j++)
		arr[j] = arr[j + 1];
	arr = realloc(arr,(*size - 1) * sizeof(int));
	(*size)--;
	printf("The array is: ");
	display(arr, *size);
	return arr;
}

int main() {
	int choice;
	int *arr1 = (int *)calloc(0, sizeof(int));
	int *arr2 = (int *)calloc(0, sizeof(int));
	int size1 = 0, size2 = 0, con = 1, ch, n, i;
	do {
		printf("\n\nEnter a choice: \n");
		printf("1. Create\n");
		printf("2. Display\n");
		printf("3. Count\n");
		printf("4. Reverse\n");
		printf("5. Index of given element\n");
		printf("6. Indexed Element\n");
		printf("7. Insert\n");
		printf("8. Delete\n");
		printf("9. Exit\n");
		scanf("%d", &choice);
		switch(choice) {
		case 1:
			printf("Creating array 1 \n");
			arr1 = create(arr1, &size1);
			printf("Creating array 2 \n");
			arr2 = create(arr2, &size2);
			break;
		case 2:
			printf("Enter 1 to display array 1 and 2 to display array 2: ");
			scanf("%d", &ch);
			if(ch == 2)
				display(arr2, size2);
			else
				display(arr1, size1);
			break;
		case 3:
			printf("Enter 1 to count array 1 and 2 to count array 2: ");
			scanf("%d", &ch);
			if(ch == 2)
				count(size2);
			else
				count(size1);
			break;
		case 4:
			printf("Enter 1 to reverse array 1 and 2 to reverse array 2: ");
			scanf("%d", &ch);
			if(ch == 2)
				reverse(arr2, size2);
			else
				reverse(arr1, size1);
			break;
		case 5:
			printf("Enter 1 to find in array 1 and 2 to find in array 2: ");
			scanf("%d", &ch);
			printf("Enter the number: ");
			scanf("%d", &n);
			if(ch == 2)
				indexOf(arr2, size2, n);
			else
				indexOf(arr1, size1, n);
			break;
		case 6:
			printf("Enter 1 to find in array 1 and 2 to find in array 2: ");
			scanf("%d", &ch);
			printf("Enter the index: ");
			scanf("%d", &n);
			if(ch == 2)
				indexElement(arr2, size2, n);
			else
				indexElement(arr1, size1, n);
			break;
		case 7:
			printf("Enter 1 to insert in array 1 and 2 to insert in array 2: ");
			scanf("%d", &ch);
			printf("Enter the index: ");
			scanf("%d", &i);
			printf("Enter the value: ");
			scanf("%d", &n);
			if(ch == 2)
				insert(arr2, &size2, n, i);
			else
				insert(arr1, &size1, n, i);
			break;
		case 8:
			printf("Enter 1 to delete from array 1 and 2 to delete from array 2: ");
			scanf("%d", &ch);
			printf("Enter the index to be removed: ");
			scanf("%d", &n);
			if(ch == 2)
				delete(arr2, &size2, n);
			else
				delete(arr1, &size1, n);
			break;
		case 9:
			con = 0;
			break;
		default:
			printf("Wrong Choice\n");
}
	} while(con);
	return 0;
}
