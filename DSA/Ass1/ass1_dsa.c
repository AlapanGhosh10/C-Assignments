#include<stdio.h>
#include<stdlib.h>

void create(int *arr, int *size) {
	if(*size > 0) {
		printf("The array is already created.\n");
		return;
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
	printf("The created array is: ");
        for(int i = 0 ; i < *size ; i++)
                printf("%d ", arr[i]);
        printf("\n");

}

void display(int* arr, int size) {
	printf("The array is: %d: ", size);
	for(int i = 0 ; i < size ; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void count(int* arr, int size) {
	printf("The number of elements in the list is: %d\n", size);
}


void reverse(int* arr, int size) {
	int i = 0, j = size - 1, temp;
	while(i < j) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
	printf("The reversed array is: ");
        for(int i = 0 ; i < size ; i++)
                printf("%d ", arr[i]);
        printf("\n");

}


void indexOf(int* arr, int size, int n) {
	printf("The number %d is present at indices: ", n);
	int present = 0;
	for(int i = 0 ; i < size ; i++) {
		if(arr[i] == n) {
			present = 1;
			printf("%d ", i);
		}
	}
	if(!present)
		printf("None");
	printf("\n");
} 

void indexElement(int* arr, int size, int i) {
	if(i < 0 || i >= size) {
		printf("Invalid Index\n");
		return;
	}
	printf("The number at index %d is %d\n", i, arr[i]);
}

void insert(int *arr, int *size, int n) {
	arr = realloc(arr,(*size + 1) * sizeof(int));
        arr[*size] = n;
        (*size)++;	
}

void delete(int *arr, int *size) {
	arr = realloc(arr, (*size - 1) * sizeof(int));
	(*size)--;
}
/*
void split() {
	int mid = size / 2;
	for(int i = mid ; i < size ; i++) {
		arr1 = realloc(arr1, (size + 1) * sizeof(int));
		arr1[size1] = arr[i];
		size1++;
	}
	arr = realloc(arr, mid * sizeof(int));
	size = mid;
	printf("The first split is: ");
	for(int i = 0 ; i < size ; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("The second split is: ");
	for(int i = 0 ; i < size1 ; i++)
		printf("%d ", arr1[i]);
	printf("\n");
}

void merge() {
	for(int i = 0 ; i < size1 ; i++) {
		arr = realloc(arr, (size + 1) * sizeof(int));
		arr[size] = arr1[i];
		size++;
	}
	arr1 = realloc(arr1, 0 * sizeof(int));
	size1 = 0;
	printf("The merged array is: ");
	for(int i = 0 ; i < size ; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void sort() {
	int i, j, key;
    	for (i = 1; i < size; i++) {
        	key = arr[i];
        	j = i - 1;
        	while (j >= 0 && arr[j] > key) {
            		arr[j + 1] = arr[j];
            		j = j - 1;
        	}
        	arr[j + 1] = key;
    	}
	printf("The sorted array is: ");
        for(int i = 0 ; i < size ; i++)
                printf("%d ", arr[i]);
        printf("\n");

}

void search(int n) {
	for(int i = 0 ; i < size ; i++)
		if(arr[i] == n) {
			printf("%d is present in array\n", n);
			return;
		}
	printf("%d is not present in array\n", n);
}
*/

int main() {
	int choice;
	int *arr1 = (int *)calloc(0, sizeof(int));
	int *arr2 = (int *)calloc(0, sizeof(int));
	int size1 = 0, size2 = 0;
	/*do {
		printf("Enter a choice: \n");
		printf("1. Create\n");
		printf("2. Display\n");
		printf("3. Count\n");
		printf("4. Reverse\n");
		printf("5. Index of given element\n");
		printf("6. Indexed Element\n");
		printf("7. Insert\n");
		printf("8. Delete\n");
		printf("9. Merge\n");
		printf("10. Split\n");
		printf("11. Sort\n");
		printf("12. Search\n");
		printf("13. Exit\n");
		scanf("%d", &choice);
		switch(choice) :
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			count();
			break;
		case 4:
			reverse();
			break;
		case 5:
			printf("Enter
			*/
	create(arr1, &size1);
	display(arr1, size1);
	/*create(arr2, &size2);
	display(arr2, size2);
	printf("%d %d\n", size1, size2);*/
	count(arr2, size2);
	reverse(arr1, size1);
	indexOf(arr1, size1, 2);
	indexOf(arr1, size1, 9999);
	indexElement(arr1, size1, -11);
	indexElement(arr1, size1, 55);
	indexElement(arr1, size1, 3);
	insert(arr1, &size1, 10);
	delete(arr1, &size1);
	display(arr1, size1);
	/*display();
	count();
	reverse();
	display();
	
	split();
	delete();
	insert(11);
	merge();
	sort();
	display();
	search(10);*/
	return 0;
}
