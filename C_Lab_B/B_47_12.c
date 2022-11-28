#include<stdio.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void search(node *root,int key){
    node *ptr = root;
    while(ptr!=NULL){
        if(ptr->data==key){
            //match
        }
        ptr = ptr->next;
    }
}

void print(node *root){
    node *ptr = root;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

node *insert(node *root,int info){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = info;
}

int main(){
    node n;


    return 0;
}