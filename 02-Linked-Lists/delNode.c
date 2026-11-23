#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *insertAtbeggining(struct node *head,int data){
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    if (newnode == NULL) return head;
    newnode->data = data;
    newnode->next = head;
    head = newnode ;
    return head;
}

struct node *delFirstNode(struct node *head){
    if (head == NULL) return NULL;
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *delInbetween(struct node *head,int index){
    if (head == NULL || index <= 0) return head;
    struct node *p = head;
    for (int i = 0; i < index - 1 && p != NULL; i++) p = p->next;
    if (p == NULL || p->next == NULL) return head;
    struct node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}
struct node *delLastElement(struct node *head){
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node *p = head;
    struct node *q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct node *delAtKey(struct node *head, int value){
    if (head == NULL) return NULL;
    if (head->data == value) return delFirstNode(head);

    struct node *p = head;
    while (p->next != NULL && p->next->data != value) p = p->next;
    if (p->next != NULL) {
        struct node *q = p->next;
        p->next = q->next;
        free(q);
    }
    return head;
}
void display(struct node *head){
    struct node *p;
    p = head;
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

int main(){
    struct node *head = NULL;
    head  = insertAtbeggining(head,30);
    head  = insertAtbeggining(head,20);
    head  = insertAtbeggining(head,10);

    head = delAtKey(head,20);
    display(head);

    return 0;
}