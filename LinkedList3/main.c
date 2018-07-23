#include <stdio.h>
#include <stdlib.h>
// Linked List: We can Insert Node at the END of the list and Delete a Node

struct Node{
    int data;
    struct Node *next;
};

struct Node* head;  // The head is global variable
void Insert(int x);
void Print();
void Delete(int n);

void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  // first create node
    temp->data = x;

    if(head == NULL)
    {
        head = temp;
        temp->next = NULL;
        return;
    }

    struct Node* temp2 = head;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp;
    temp->next = NULL;

    //temp->data = x;
    //temp->next = head;  //covers when list is empty
    //head = temp;

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
void Delete(int n) //Delete node at position n
{
    struct Node* temp1 = head;
    if(n == 1){
        head = temp1 ->next;    //Special case to delete 1st node
        free(temp1);            //free memory of 1st node
        return;
    }
    int i;
    for(i=0;i<n-2;i++)
        temp1 = temp1->next;   //temp1 now points to (n-1)th position

    struct Node* temp2 = temp1->next;    //fix links and free memory of nth
    temp1->next = temp2->next;
    free(temp2);
}
int main()
{
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();
    int n;
    printf("Enter a position to delete\n");
    scanf("%d", &n);
    Delete(n);
    Print();


}
