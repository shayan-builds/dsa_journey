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

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root;

    root = createTree();

    printf("\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;
}