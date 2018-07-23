#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Delete a Node from the Binary Search Tree.  
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
struct Node* Delete(struct BstNode* root, int data)
{
    if(root == NULL)
        return root;
    else if(data < root->data) //Must be in the left subtree
        root->left = Delete(root->left, data);  //recursive call
    else if(data > root->data)
        root->right = Delete(root->right, data);    //recursive call to right
    else //Found the node...now delete it
    {
        //Case 1: No Child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;

        }
        //Case 2: One Child
        else if(root->left == NULL)
        {
            struct Node* temp = root;
            root = root->right;
            free(temp);

        }
        else if(root->right == NULL)
        {
            struct Node* temp = root;
            root = root->left;
            free(temp);

        }
        //Case 3: 2 Children
        else
        {
            struct BstNode* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);

        }
        return root;

    }

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

//    int number;
//    printf("Enter a number to search: \n");
//    scanf("%d", &number);
//
//    if(Search(root,number) == true)
//        printf("Found\n");
//    else
//        printf("Not Found\n");


    root = Delete(root, 8);
    printf("I just deleted the 8 element from the Binary Search Tree\n");
    printf("I will now call the Search function for 8\n");

    if(Search(root,8) == true)
        printf("Found 8\n");
    else
        printf("8 Not Found\n");



    return 0;
}
