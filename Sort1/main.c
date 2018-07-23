#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no, temp, i, j, a[20];
    printf("Enter the size of the array:\n");
    scanf("%d", &no);
    for(i=0;i<no;i++)
    {
        printf("Enter the element:\n");
        scanf("%d", &a[i]);
    }
    for(i=0;i<no-1;i++)
    {
        for(j=0;j<no-1;j++)
        {
           if(a[j] > a[j+1])
            {
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
            }

        }

    }
    printf("Sorted array is: \n");
    for(i=0;i<no;i++)
        printf("%d\n", a[i]);

}
