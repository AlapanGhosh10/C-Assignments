#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
} node;

void search(node *ptr, int key){
    ptr = ptr -> next;
    while(ptr != NULL){
        if(ptr -> val == key) {
            printf("%d is present.\n\n", key);
            return;
        }
        ptr = ptr -> next;
    }
    printf("%d is not present. \n\n", key);
}

void printList(node *ptr){
    ptr = ptr -> next;
    while(ptr != NULL){
        printf("%d ", ptr -> val);
        ptr = ptr -> next;
    }
    printf("\n\n");
}

void insert(node *ptr, int info){
    	while(ptr -> next != NULL)
    		ptr = ptr -> next;
    	node *newNode = (node *)malloc(sizeof(node));
    	newNode -> val = info;
    	ptr -> next = newNode;
    	printf("Inserted Successfully\n\n");
}

void delete(node *ptr, int num) {
	while(ptr -> next != NULL && ptr -> next -> val != num)
		ptr = ptr -> next;
	if(ptr -> next == NULL) {
		printf("Node with value %d is not present.\n\n", num);
		return;
	}
	ptr -> next = ptr -> next -> next;
	printf("Deleted Successfully\n\n");
}
	

int main(){
    int flag = 1;        	
    node *root = (node *)malloc(sizeof(node));
    printf("Available Operations for Linked List: \n");
    printf("1. Insert a new node.\n");
    printf("2. Delete a given node.\n");
    printf("3. Print the Linked List.\n");
    printf("4. Search element.\n");
    printf("5. Exit.\n");
    while(flag) {
    	printf("Enter 1, 2, 3, 4 or 5 depending on the operation to be performed: ");
    	int choice,val;
    	scanf("%d", &choice);
    
    	switch(choice) {
    		case 1: printf("Enter value of node to be inserted: ");
    			scanf("%d", &val);
    			insert(root, val);
    			break;
    		case 2: printf("Enter value of node to be deleted: ");
    			scanf("%d", &val);
    			delete(root, val);
    			break;
    		case 3: printf("The linked list is as follows: ");
    			printList(root);
    			break;
    		case 4: printf("Enter the value of node to be searched: ");
    			scanf("%d", &val);
    			search(root, val);
    			break;
    		case 5: flag = 0;
    			break;
    		default: printf("Invalid Input.\n\n");
    	}
    }
    return 0;
}
