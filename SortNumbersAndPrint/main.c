#include <stdio.h>
#include <stdlib.h>
// Find and print the Smallest Number in the array
//Input :  {9, 5, 6, 8, 2, 7, 4}
//Output : Smallest number in the array is 2

int main()
{
    int a[7] = {9, 5, 6, 8, 2, 7, 4};
    //int a[7] = {90, 53, 6, -8, 2, 7, 49};
    int small= a[0];
    for(int i=0; i<6;i++)
    {


        if((a[i] < small))
            small = a[i];


    }
    printf("The smallest number in the array is: %d \n", small);
    return 0;
}
