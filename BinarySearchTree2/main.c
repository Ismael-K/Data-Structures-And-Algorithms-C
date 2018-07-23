#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Find the minimum and maximum value in Binary Search Tree.
   */

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
int FindMin(BstNode* root)
{
    if(root == NULL)
    {
        printf("Error: Tree is Empty\n");
        return -1;
    }
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int FindMax(BstNode* root)
{
    if(root == NULL)
    {
        printf("Error: Tree is Empty\n");
        return -1;
    }
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
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
    root = Insert(root, 17);

    int MinValue;
    MinValue = FindMin(root);
    printf("The MINIMUM value in the Binary Search tree is: %d \n", MinValue);

    int MaxValue;
    MaxValue = FindMax(root);
    printf("The MAXIMUM value in the Binary Search tree is: %d \n", MaxValue);

    

    return 0;
}
