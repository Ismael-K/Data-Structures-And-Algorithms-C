#include <stdio.h>
#include <stdlib.h>

// Array based implementation of Stack

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;  // empty stack

void Push(int x)
{
    if(top == MAX_SIZE - 1){
        printf("Error: Stack Overflow \n");
        return;
    }
    top++;
    A[top]=x;   // equivalent one statement: A[++top] = x;
}
void Pop(){

    if(top == - 1){
        printf("Error: No element to pop\n");
        return;
    }
    top--;

}
int Top()
{
    return A[top];
}
void Print(){
    int i;
    printf("Stack Contents: \n");
    for(i=0;i<=top;i++)
        printf("%d ", A[i]);
    printf("\n");

}
int main()
{
    Push(2);Print();
    Push(5);Print();
    Push(10);Print();
    Pop();Print();
    Push(12);Print();
   // printf("size of stack: %d\n", sizeof(A)/sizeof(A[0]));
    return 0;
}
