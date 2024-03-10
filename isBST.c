#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *buildTree()
{
    int value;
    printf("Enter a value (or -1 to skip): ");
    scanf("%d", &value);

    if (value == -1)
    {
        return NULL;
    }

    struct Node *newNode = createNode(value);
    printf("Enter the left node of the tree (%d)\n", value);
    newNode->left = buildTree();
    printf("Enter the right node of the tree (%d)\n", value);
    newNode->right = buildTree();
    return newNode;
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct Node *root = NULL;
    int rootValue;
    printf("Enter the root value :");
    scanf("%d", &rootValue);

    if (rootValue != -1)
    {
        root = createNode(rootValue);
        printf("Enter the left node of the tree (%d)\n", rootValue);
        root->left = buildTree();
        printf("Enter the right node of the tree (%d)\n", rootValue);
        root->right = buildTree();
    }

    if (isBST(root))
    {
        printf("This is a bst");
    }
    else
    {
        printf("This is not a bst");
    }
    return 0;
}