
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// ======================================
// INSERT AT INDEX
// ======================================
struct node *insertAtIndex(struct node *head, int data, int pos)
{
    if (pos < 0) {
        printf("Invalid position\n");
        return head;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    newnode->data = data;

    // Case 1: Insert at beginning
    if (pos == 0) {
        newnode->next = head;
        head = newnode;
        return head;
    }

    struct node *ptr = head;
    int i = 0;

    // Move to node before insertion position
    while (ptr != NULL && i < pos - 1) {
        ptr = ptr->next;
        i++;
    }

    // Invalid position
    if (ptr == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return head;
    }

    // Insert node
    newnode->next = ptr->next;
    ptr->next = newnode;

    return head;
}

// ======================================
// DISPLAY LINKED LIST
// ======================================
void display(struct node *head)
{
    struct node *ptr = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

// ======================================
// DELETE FIRST NODE
// ======================================
struct node *deleteAtFirst(struct node *head)
{
    // Case 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    // Case 2: Delete first node
    struct node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

// ======================================
// DELETE AT INDEX
// ======================================
struct node *deleteInbetween(struct node *head, int pos)
{
    // Case 1: Empty list or invalid position
    if (head == NULL || pos < 0) {
        printf("Invalid position or empty list\n");
        return head;
    }

    // Case 2: Delete first node
    if (pos == 0) {
        return deleteAtFirst(head);
    }

    struct node *p = head;
    struct node *q = head->next;
    int i = 1;

    // Move q to node at index pos
    while (q != NULL && i < pos) {
        p = q;
        q = q->next;
        i++;
    }

    // Case 3: Position does not exist
    if (q == NULL) {
        printf("Invalid position\n");
        return head;
    }

    // Case 4: Delete node
    p->next = q->next;
    free(q);

    return head;
}

// ======================================
// DELETE LAST NODE
// ======================================
struct node *deleteAtLast(struct node *head)
{
    // Case 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    // Case 2: Only one node
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node *p = head;
    struct node *q = head->next;

    // Move q to last node, p to previous node
    while (q->next != NULL) {
        p = q;
        q = q->next;
    }

    // Disconnect and delete last node
    p->next = NULL;
    free(q);

    return head;
}

// ======================================
// DELETE BY KEY
// ======================================
struct node *deleteAtKey(struct node *head, int key)
{
    // Case 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    // Case 2: Key is in first node
    if (head->data == key) {
        struct node *p = head;
        head = head->next;
        free(p);
        return head;
    }

    struct node *p = head;
    struct node *q = head->next;

    // Search for key
    while (q != NULL && q->data != key) {
        p = q;
        q = q->next;
    }

    // Case 3: Key not found
    if (q == NULL) {
        printf("Element not found\n");
        return head;
    }

    // Case 4: Key found
    p->next = q->next;
    free(q);

    return head;
}

// ======================================
// MAIN
// ======================================
int main()
{
    struct node *head = NULL;

    // Insert elements
    head = insertAtIndex(head, 10, 0);
    head = insertAtIndex(head, 20, 1);
    head = insertAtIndex(head, 30, 2);
    head = insertAtIndex(head, 40, 3);
    head = insertAtIndex(head, 50, 4);

    printf("Initial list:\n");
    display(head);

    printf("\nDelete first node:\n");
    head = deleteAtFirst(head);
    display(head);

    printf("\nDelete node at index 1:\n");
    head = deleteInbetween(head, 1);
    display(head);

    printf("\nDelete last node:\n");
    head = deleteAtLast(head);
    display(head);

    printf("\nDelete node with key 40:\n");
    head = deleteAtKey(head, 40);
    display(head);

    return 0;
}
