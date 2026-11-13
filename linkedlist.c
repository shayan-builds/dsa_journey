#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node *ptr){
    while (ptr != NULL){
        printf("element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct node* insertAtbeggining(struct node *head,int data ){//null,50
    struct node *newnode = (struct node *)malloc(sizeof(struct node));//1000 address
    newnode->data = data;
    newnode->next = head;// newnode point to null
    head = newnode;// now head points to newnode created 
    return head;//head has been returned
}
void LLT(struct node *head){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr = head;
    int i=1;
    while(ptr!=NULL){
        printf("ELEMENT %d:%d\n",i,*ptr );
        ptr = ptr->next;
        i = i+1;
    }
}
struct node *insertInBetween(struct node *head, int data, int pos)
{
    struct node *newnode;//newnode pointer which points to another structure pointer 
    struct node *ptr;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    // Insertion at beginning
    if (pos == 0)
    {
        newnode->next = head;
        return newnode;
    }

    ptr = head;

    // Stop at the node just before the required position
    for (int i = 0; i < pos - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Invalid position!\n");
        free(newnode);
        return head;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;

    return head;
}
struct  node *insertAfternode(struct node *head, int key, int data){
    struct node *ptr,*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    ptr = head;
    while(ptr != NULL){
        if(ptr->data == key){
            newnode->next = ptr->next;
            ptr->next = newnode;
            return head;
        }
        ptr = ptr->next;
    }
}
struct node *insertAtend(struct node *head, int data){
    struct node *ptr,*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if(head == NULL){
        printf("list is empty\n");
        head = newnode;
        return head;
    }
    ptr = head;
    while(ptr->next!= NULL){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->next = NULL;
    return head;
}

int main(){

struct node *head = NULL;
head = insertAtbeggining(head,50);//(null,50)
//now head stores address 1000
head = insertAtbeggining(head,40);//(1000,40) after that  struct node * will get 1000 as address, newnode will be storing 40 and its next will point to 1000 not null and then head will again point to newnode now our chain got bigger and fucntion will return head and that will be stored by main head .SO NEWNODE ONLY EXISTS IN FUCNTION?
head = insertAtbeggining(head,90);
LLT(head);
return 0;
}


