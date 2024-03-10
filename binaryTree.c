#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* buildTree() {
    int value;
    printf("Enter a value (or -1 to skip): ");
    scanf("%d", &value);
    if (value == -1) {
        return NULL; // Skip this node
    }
    struct Node* newNode = createNode(value);
    printf("Enter the left subtree for %d:\n", value);
    newNode->left = buildTree(); 
    printf("Enter the right subtree for %d:\n", value);
    newNode->right = buildTree();
    return newNode;
}

int main() {
    struct Node* root = NULL;

    printf("Enter the root node value: ");
    int rootValue;
    scanf("%d", &rootValue);

    if (rootValue != -1) {
        root = createNode(rootValue);
        printf("Enter the left subtree for %d:\n", rootValue);
        root->left = buildTree();
        printf("Enter the right subtree for %d:\n", rootValue);
        root->right = buildTree();
    }
}
