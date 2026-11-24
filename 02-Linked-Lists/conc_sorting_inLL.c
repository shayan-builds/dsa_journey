#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Create new node
struct node *createNode(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

// STACK OPERATIONS

// Push - Insert at beginning
struct node *push(struct node *top, int value)
{
    struct node *newnode;

    newnode = createNode(value);

    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully\n");

    return top;
}

// Pop - Delete from beginning
struct node *pop(struct node *top)
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return top;
    }

    temp = top;

    printf("Popped element: %d\n", temp->data);

    top = top->next;

    free(temp);

    return top;
}

// Display Stack
void displayStack(struct node *top)
{
    struct node *temp = top;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("TOP -> ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


// QUEUE OPERATIONS

// Enqueue - Insert at end
struct node *enqueue(struct node *front, int value)
{
    struct node *newnode, *temp;

    newnode = createNode(value);

    if (front == NULL)
    {
        front = newnode;
        printf("Element inserted successfully\n");
        return front;
    }

    temp = front;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;

    printf("Element inserted successfully\n");

    return front;
}

// Dequeue - Delete from beginning
struct node *dequeue(struct node *front)
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return front;
    }

    temp = front;

    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    free(temp);

    return front;
}

// Display Queue
void displayQueue(struct node *front)
{
    struct node *temp = front;

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("FRONT -> ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL <- REAR\n");
}


int main()
{
    struct node *top = NULL;
    struct node *front = NULL;

    int choice, value, ch;

    do
    {
        printf("\n----- MAIN MENU -----");
        printf("\n1. Stack Operations");
        printf("\n2. Queue Operations");
        printf("\n3. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                do
                {
                    printf("\n----- STACK MENU -----");
                    printf("\n1. Push");
                    printf("\n2. Pop");
                    printf("\n3. Display");
                    printf("\n4. Back");

                    printf("\nEnter choice: ");
                    scanf("%d", &ch);

                    switch (ch)
                    {
                        case 1:
                            printf("Enter value: ");
                            scanf("%d", &value);
                            top = push(top, value);
                            break;

                        case 2:
                            top = pop(top);
                            break;

                        case 3:
                            displayStack(top);
                            break;
                    }

                } while (ch != 4);

                break;

            case 2:
                do
                {
                    printf("\n----- QUEUE MENU -----");
                    printf("\n1. Enqueue");
                    printf("\n2. Dequeue");
                    printf("\n3. Display");
                    printf("\n4. Back");

                    printf("\nEnter choice: ");
                    scanf("%d", &ch);

                    switch (ch)
                    {
                        case 1:
                            printf("Enter value: ");
                            scanf("%d", &value);
                            front = enqueue(front, value);
                            break;

                        case 2:
                            front = dequeue(front);
                            break;

                        case 3:
                            displayQueue(front);
                            break;
                    }

                } while (ch != 4);

                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 3);

    return 0;
}

