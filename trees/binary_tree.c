#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createTree()
{
    struct node *newnode;
    int value;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &value);

    if(value == -1)
        return NULL;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;

    printf("Enter left child of %d\n", value);
    newnode->left = createTree();

    printf("Enter right child of %d\n", value);
    newnode->right = createTree();

    return newnode;
}

int main()
{
    struct node *root;

    root = createTree();

    printf("\nBinary Tree created successfully");

    return 0;
}