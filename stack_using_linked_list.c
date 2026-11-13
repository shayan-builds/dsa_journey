#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int isFull(struct node *top){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL){
        printf("stakc overlfow \n");
    }
}
struct node *push(struct node *top,int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(isFull(top)){
        printf("stack over flow\n");
    }
    else{
        newnode->data = data;
        newnode->next = top;
        top = newnode;
        return top;
    }
}
void LLT(struct node *top){
    struct node *ptr;
    ptr = top;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    struct node *top =NULL;
    top=push(top,10);
    top=push(top,12);
    top=push(top,9);
    LLT(top);
}