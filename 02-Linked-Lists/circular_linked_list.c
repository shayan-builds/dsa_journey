#include <stdio.h>
#include <stdlib.h>


typedef struct node* node;
struct node {
    int data;
    node next;
};

struct node *insertAtfirst(node head, int data){
    node n = (node)malloc((sizeof(struct node)));
    if(n == NULL){
        printf("memory allocation failed\n");
    }
    n->data = data;
    if(head == NULL){
        n->next = n;
        head = n;
        return head;
    }
    node p = head;
    do{
        p = p->next;
    }while(p->next!=head);
    p->next = n;
    n->next = head;
    head = n ;
    return head;
}
void traversal(node head){
    node p = head;
    if(head==NULL){
        printf('list is empty\n');
    }
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
}
struct node *insertAtEnd(node *head,int data){
    node newnode = (node)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("memory allocation failed\n");
    }
    newnode->data = data;
    if(head==NULL){
        newnode->next = newnode;
        head = newnode;
        return head;
    }
    node p = head;
    do{
        p=p->next;
    }while(p->next!=head);
    p->next = newnode;
    newnode->next = head;
    return head;
}

node insertAtpos(node head, int data, int pos) {

    node newnode = malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    newnode->data = data;

    if (head == NULL || pos < 1) {
        printf("Position not found\n");
        free(newnode);
        return head;
    }

    if (pos == 1) {
        node p = head;

        do {
            p = p->next;
        } while (p->next != head);

        newnode->next = head;
        p->next = newnode;

        return newnode;
    }

    node p = head;
    int i = 1;

    while (i < pos - 1 && p->next != head) {
        p = p->next;
        i++;
    }

    if (i != pos - 1) {
        printf("Position not found\n");
        free(newnode);
        return head;
    }

    newnode->next = p->next;
    p->next = newnode;

    return head;
}
struct node *delAtlast(node head){
    if(head == NULL){
        printf("list is empty\n");
        return head;
    }
    if(head->next == head){
        free(head);
        head = NULL;
        return head;
    }
    node p,q;
    p = head;
    q = NULL;
    while(p->next!=head){
        q = p;
        p = p->next;
    }
    q->next = head;
    free(p);
    p = NULL;
    return head;
}

int main(){
    node head = NULL;
    head = insertAtEnd(head,30);
    head = insertAtpos(head,20,2);
    traversal(head);
    head = insertAtpos(head,10,3);
    head = insertAtpos(head,90,4);
    printf("\n");
    traversal(head);
    head = delAtlast(head);
    printf("\n");
    traversal(head);
}


