#include<stdio.h>
#include<stdlib.h>
 
 struct Node {
 	int val;
 	struct Node* next;
 };
 
 struct Node* create() {
 	int n;
 	char x;
 	struct Node *head, *temp;
 	head = (struct Node*)malloc(sizeof(struct Node));
 	temp = head;
 	printf("Enter values of linked list: ");
 	scanf("%d", &n);
 	temp -> val = n;
 	while(scanf("%d", &n)) {
 		temp -> next  = (struct Node*)malloc(sizeof(struct Node));
 		temp -> next -> val = n;
 		temp = temp -> next;
 	}
 	scanf("%c", &x);
 	return head;
 }
 
 struct Node* insertFirst(struct Node* head, int n) {
 	struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
 	newHead -> val = n;
 	newHead -> next = head;
 	return newHead;
 }
 
 struct Node* deleteFirst(struct Node* head) {
 	return head -> next;
 }
 
 struct Node* deleteLast(struct Node* head) {
 	struct Node* temp = head;
 	while(temp -> next -> next)
 		temp = temp -> next;
	temp -> next = NULL;
	return head;
 }

 struct Node* insertLast(struct Node* head, int n) {
 	struct Node* temp = head;
 	while(temp -> next)
 		temp = temp -> next;
 	 struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 	 node -> val = n;
 	 temp -> next = node;
 	 return head;
 }
 struct Node* insertAfterK(struct Node* head, int k, int n) {
 	struct Node* temp = head;
 	int i = 1;
 	while(temp && i != k) {
 		temp = temp -> next;
 		i++;
 	}
 	if(!temp) {
 		printf("There are less than %d nodes in the linked list\n", k);
 		return head;
 	}
 	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 	node -> val = n;
 	if(!temp -> next)
 		temp -> next = node;
 	else {
 		node -> next = temp -> next;
 		temp -> next = node;
 	}
 	return head;
 }
 struct Node* insertAfterN(struct Node* head, int n, int v) {
 	struct Node* temp = head;
 	while(temp && temp -> val != n) 
 		temp = temp -> next;
 	if(!temp) {
 		printf("Node with value %d is not present\n", n);
 		return head;
 	}
 	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 	node -> val = v;
 	if(!temp -> next)
 		temp -> next = node;
 	else {
 		node -> next = temp -> next;
 		temp -> next = node;
 	}
 	return head;
 }
 
 struct Node* insertBeforeK(struct Node* head, int k, int v) {
 	struct Node* temp = head;
 	int i = 1;
 	if(k == 1) {
 		struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 		node -> val = v;
 		node -> next = head;
 		return node;
 	}
 	k -= 1;
 	while(temp && i != k) {
 		temp = temp -> next;
 		i++;
 	}
 	if(!temp || !temp -> next) {
 		printf("There are less than %d nodes in the linked list\n", k + 1);
 		return head;
 	}
 	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 	node -> val = v;
 	if(!temp -> next)
 		temp -> next = node;
 	else {
 		node -> next = temp -> next;
 		temp -> next = node;
 	}
 	return head;
 }
 
 struct Node* insertBeforeN(struct Node* head, int n, int v) {
 	if(head -> val == n) {
 		struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 		node -> val = v;
 		node -> next = head;
 		return node;
 	}
 	struct Node* temp = head;
 	while(temp -> next && temp -> next -> val != n) 
 		temp  = temp -> next;
 	if(!temp -> next) {
 		printf("The value %d is not present in the Linked List\n", n);
 		return head;
 	}
 	struct Node* node = (struct Node *)malloc(sizeof(struct Node));
 	node -> val = v;
 	node -> next = temp -> next;
 	temp -> next = node;
 	return head;
 }
 
  void printList(struct Node* n) {
	printf("The contents are: \n");
 	while(n) {
 		printf("%d ", n -> val);
 		n = n -> next;
 	}
 	printf("\n");
 }
 
 
 struct Node* merge(struct Node* n1, struct Node* n2) {
  	struct Node *head, *temp;
  	if(n1 -> val < n2 -> val) {
  			head = n1;
  			n1 = n1 -> next;
  	} else {
  			head = n2;
  			n2 = n2 -> next;
  	}
  	temp = head;
  	while(n1 && n2) {
  		if(n1 -> val < n2 -> val) {
  			temp -> next = n1;
  			temp = temp -> next;
  			n1 = n1 -> next;
  		} else {
  			temp -> next = n2;
  			temp = temp -> next;
  			n2 = n2 -> next;
  		}
  	}
  	while(n1) {
  		temp -> next = n1;
  		temp = temp -> next;
  		n1 = n1 -> next;
  	}
  	while(n2) {
  		temp -> next = n2;
  		temp = temp -> next;
  		n2 = n2 -> next;	
  	}
  	return head;
  }
 
 struct Node* sort(struct Node* head) {
 	if(!head -> next)
 		return head;
 	if(!head -> next -> next) {
 		struct Node* hlf = head -> next;
 		head -> next = NULL;
 		return merge(head, hlf);
 	}
 	struct Node *fast, *slow;
 	fast = head;
 	slow = head;
 	while(fast -> next && fast -> next -> next) {
 		slow = slow -> next;
 		fast = fast -> next -> next;
 	}
 	struct Node *p1, *p2;
 	p2 = slow -> next;
 	p1 = head;
 	slow -> next = NULL;
 	p1 = sort(p1);
 	p2 = sort(p2);
 	return merge(p1, p2);
 }
 
 struct Node* reverse(struct Node* head)
 {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
 }

 int checkEqual(struct Node* h1, struct Node* h2) {
	while(h1 && h2) {
		if(h1 -> val != h2 -> val)
			return 0;
		h1 = h1 -> next;
		h2 = h2 -> next;
	}
	if(h1 || h2)
		return 0;
	else
		return 1;
}

 struct Node* concatenate(struct Node* h1, struct Node* h2) {
	struct Node* temp = h1;
	while(temp -> next)
		temp = temp -> next;
	temp -> next = h2;
	return h1;
 }
 	
 struct Node* deleteK(struct Node* head, int k) {
	struct Node* temp = head;
	if(k < 0) {
		printf("Try higher values of k\n");
		return head;
	}
	if(k == 0)
		return head -> next;
	int i = 1;
	while(temp -> next && k != i) {
		temp = temp -> next;
		i++;
	}
	if(!temp -> next) {
		printf("Try lesser value of k\n");
		return head;
	}
	if(!temp -> next -> next) {
		temp -> next = NULL;
		return head;
	}
	temp -> next = temp -> next -> next;
	return head;
}
 

 struct Node* deleteN(struct Node* head, int n) {
	struct Node* node = head;
	if(node -> val == n)
		return node -> next;
	while(node -> next && node -> next -> val != n) 
		node = node -> next;
	if(!node -> next) {
		printf("There is no node with value %d\n", n);
		return head;
	}
	node -> next = node -> next -> next;
	return head;
 }
 
 int main() {
	int choice, n, v, con = 1;
	struct Node* ll;
	do {
		printf("\n\nEnter a choice: \n");
		printf("1. Create\n");
		printf("2. Print\n");
		printf("3. Insert at Front\n");
		printf("4. Insert at End\n");
		printf("5. Insert after Kth Node\n");
		printf("6. Insert after Node with given value\n");
		printf("7. Insert before Kth Node\n");
		printf("8. Insert before Node with given value\n");
		printf("9. Delete at Front\n");
		printf("10. Delete at End\n");
		printf("11. Delete after Kth Node\n");
		printf("12. Delete before Kth Node\n");
		printf("13. Delete the Kth Node\n");
		printf("14. Delete Node with given value\n");
		printf("15. Reverse\n");
		printf("16. Sort\n");
		printf("17. Search\n");
		printf("18. Merge\n");
		printf("19. Concatenate\n");
		printf("20. Check if equal\n");
		printf("21. Exit\n");
		scanf("%d", &choice);
		switch(choice) {
		case 1:
			printf("Creating Linked List \n");
			ll = create();
			break;
		case 2:
			printList(ll);
			break;
		case 3:
			printf("Value to insert at First: ");
			scanf("%d", &n);
			ll = insertFirst(ll, n);
			printList(ll);
			break;
		case 4:
			printf("Value to insert at Last: ");
			scanf("%d", &n);
			ll = insertLast(ll, n);
			printList(ll);
			break;
		case 5:
			printf("Give value of k: ");
			scanf("%d", &n);
			printf("Insert value to insert: ");
			scanf("%d", &v);
			ll = insertAfterK(ll, n, v);
			printList(ll);
			break;
		case 6:
			printf("Give the value in LinkedList: ");
			scanf("%d", &n);
			printf("Insert value to insert: ");
			scanf("%d", &v);
			ll = insertAfterN(ll, n, v);
			printList(ll);
			break;
		case 7:
			printf("Give value of k: ");
			scanf("%d", &n);
			printf("Insert value to insert: ");
			scanf("%d", &v);
			ll = insertBeforeK(ll, n, v);
			printList(ll);
			break;
		case 8:
			printf("Give the value in LinkedList: ");
			scanf("%d", &n);
			printf("Insert value to insert: ");
			scanf("%d", &v);
			ll = insertBeforeN(ll, n, v);
			printList(ll);
			break;
		case 9:
			ll = deleteFirst(ll);
			printf("After Deleting First Node: \n");
			printList(ll);
			break;
		case 10:
			ll = deleteLast(ll);
			printf("After Deleting Last Node: \n");
			printList(ll);
			break;
		case 11:
			printf("Give value of k: ");
			scanf("%d", &n);
			ll = deleteK(ll, n);
			printf("Deleting the node after kth node.\n");
			printList(ll);
			break;
		case 12:
			printf("Give value of k: ");
			scanf("%d", &n);
			ll = deleteK(ll, n - 2);
			printf("Deleting the node before kth node.\n");
			printList(ll);
			break;
		case 13:
			printf("Give value of k: ");
			scanf("%d", &n);
			ll = deleteK(ll, n - 1);
			printf("Deleting the kth node.\n");
			printList(ll);
			break;
		case 14:
			printf("Enter value of Node to delete: ");
			scanf("%d", &n);
			ll = deleteN(ll, n);
			printf("After Deleting Node\n");
			printList(ll);
			break;
		case 15:
			ll = reverse(ll);
			printf("After Reversing: \n");
			printList(ll);
			break;
		case 16:
			ll = sort(ll);
			printf("After Sorting: \n");
			printList(ll);
			break;
		case 18:
			printf("Creating New Linked List to Merge:\n");
			struct Node* ll2;
			ll2 = create();
			ll2 = sort(ll2);
			ll = merge(ll, ll2);
			printf("After Merging: \n");
			printList(ll);
			break;
		case 19:
			printf("Creating New Linked List to Concatenate:\n");
			struct Node* ll4;
			ll4 = create();
			ll = concatenate(ll, ll4);
			printList(ll);
			break;
		case 20:
			printf("Creating New Linked List to Check:\n");
			struct Node* ll3;
			ll3 = create();
			if(checkEqual(ll, ll3))
				printf("The Linked Lists are equal\n");
			else
				printf("The Linked Lists are not equal\n");
			break;
		case 21:
			con = 0;
			break;
		default:
			printf("Wrong Choice\n");
		}
	} while(con);
		
 	return 0;
 }
