#include <stdio.h>
#include <stdlib.h>
// Linked List: Inserting node at beginning

struct Node{
    int data;
    struct Node *next;
};

struct Node* head;  // The head is global variable
void Insert(int x);
void Print();

void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  // first create node
    temp->data = x;
    temp->next = head;  //covers when list is empty
    head = temp;

//    if(head != NULL)
//        temp->next = head;  //only when list is empty
//    head = temp;
}
void Print()
{
    struct Node* temp = head;
    printf("LIST CONTENTS: ");
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    head = NULL;
    printf("How many numbers? \n");
    int n, i, x;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }

}
