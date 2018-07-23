#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Binary Search Tree implementation
/* Insert elements in tree.
   Then search.
Is 8 in tree? Yes, Found.
Is 22 in tree? No, Not Found. */

typedef struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
}BstNode;

//struct BstNode* root; // store address of root node
//BstNode* Insert(BstNode* root, int data);

BstNode* GetNewNode(int data)
{
    BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
BstNode* Insert(BstNode* root, int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);

    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);

    }
    else
    {
        root->right = Insert(root->right, data);

    }
    return root;
}
bool Search(BstNode* root, int data)
{
    if(root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return Search(root->left, data);
    else return Search(root->right, data);
}
int main()
{
    BstNode* root = NULL; // Create an empty tree
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    int number;
    printf("Enter a number to search: \n");
    scanf("%d", &number);

    if(Search(root,number) == true)
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}
