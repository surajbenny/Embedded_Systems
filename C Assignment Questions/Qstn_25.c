/*
25.Write a C program that finds all pairs of elements in an array whose sum equals
a given target value.

Description: The program should prompt the user to enter the size of the array, its
elements, and a target sum. It must then examine all possible pairs of elements in the
array and identify every pair whose sum matches the target. Each valid pair should be
printed on the screen. If no such pair exists, an appropriate message should be
displayed. The same element should not be paired with itself.
Pre-requisites: Arrays, Nested Loops, Conditional Statements.


*/

#include<stdio.h>

int main()
{
    int arr[100];
    int size, target;
    int i, j;
    int found = 0;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter array elements: ");

    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

       printf("Pairs are:\n");

       for(i=0;i<size;i++)
       {
         for(j=i+1;j<size;j++)
         {
            if(target == (arr[i]+arr[j]))

            {
                printf("(%d,%d)\n",arr[i],arr[j]);
                
                found =1;
            }
         }
       }

       if (found == 0)
       {
        printf("No pairs found");
       }
}

