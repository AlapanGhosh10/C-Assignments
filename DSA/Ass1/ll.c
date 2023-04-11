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
 		node -> next = temp -> next -> next;
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
 		node -> next = temp -> next -> next;
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
 	while(n) {
 		printf("%d ", n -> val);
 		n = n -> next;
 	}
 	printf("\n");
 }
 
 
 struct Node* merge(struct Node* n1, struct Node* n2) {
 	printf("in merge\n");
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
  	printList(head);
  	return head;
  }
 
 struct Node* sort(struct Node* head) {
 	printf("in\n");
 	if(!head -> next)
 		return head;
 	if(!head -> next -> next) {
 		struct Node* hlf = head -> next;
 		head -> next = NULL;
 		return merge(head, hlf);
 	}
 	printf("head -> %d\n", head -> val);
 	struct Node *fast, *slow;
 	fast = head;
 	slow = head;
 	while(fast -> next && fast -> next -> next) {
 		slow = slow -> next;
 		fast = fast -> next -> next;
 	}
 	printf("slow fast -> %d : %d\n", slow -> val, fast -> val); 
 	struct Node *p1, *p2;
 	p2 = slow -> next;
 	p1 = head;
 	slow -> next = NULL;
 	p1 = sort(p1);
 	p2 = sort(p2);
 	// del
 	printf("p1 -> ");
 	printList(p1);
 	printf("p2 -> ");
 	printList(p2);
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
 	


 	
 
 int main() {
  	struct Node* h1;
 	h1 = create();
 	h1 = insertFirst(h1, 100);
 	h1 = insertLast(h1, 300);
 	h1 = insertAfterN(h1, 4, 55);
 	h1 = insertAfterN(h1, 300, 555);
 	h1 = insertAfterK(h1, 3, 777);
 	h1 = insertBeforeK(h1, 3, 000);
 	h1 = insertBeforeK(h1, 1, 999);
 	h1 = insertBeforeK(h1, 10, 999);
 	h1 = sort(h1);
 	printList(h1);
 	h1 = reverse(h1);
 	printList(h1);
 	return 0;
 }
