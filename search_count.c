
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *insertAtEnd(struct node *head) {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return head;
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void search(struct node *head) {
    struct node *temp = head;
    int key, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &key);
    while (temp != NULL) {
        if (temp->data == key) {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (found)
        printf("Element found!\n");
    else
        printf("Element not found!\n");
}
int countNodes(struct node *head) {
    struct node *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() {
    struct node *head = NULL;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        head = insertAtEnd(head);
    }
    printf("\nLinked List: ");
    display(head);
    search(head);
    printf("Total number of nodes: %d\n", countNodes(head));
    return 0;
}
