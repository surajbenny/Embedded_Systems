/*
21.Write a C program to remove duplicate elements from a given array.

Description: The program should prompt the user to enter the size of the array and its
elements. It must then identify and remove any duplicate values, ensuring that each
element appears only once in the resulting array. The program should finally display
the updated array containing only unique elements.
Pre-requisites: Arrays, Loops, Conditional Statements


*/

#include<stdio.h>

int main()
{
    int arr[200],size;
    int i,j,k;

    printf("Enter the size of array: ");
    scanf("%d",&size);

    printf("Enter the elements of array: ");
    for(i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }

    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[i] == arr[j])
            {
                for(k=j;k<size;k++)
                {
                    arr[k] = arr[k+1];
                }

                size--;
                j--;      // to check the same index before moving forward
            }
        }
    }
printf("Array after removing duplicates:\n");

    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

}