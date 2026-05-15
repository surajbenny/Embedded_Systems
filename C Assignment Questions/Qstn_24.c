/*
24.Write a C program that merges two sorted arrays into a single sorted array
without using any sorting function.

Description: The program should prompt the user to enter the sizes and elements of
two arrays, each already sorted in ascending order. It must then merge them into a
third array by comparing elements from both arrays one by one and placing the
smaller element first, continuing until all elements are placed. The final merged sorted
array should be displayed on the screen.
Pre-requisites: Arrays, Loops, Multiple Array Handling.


*/

#include<stdio.h>

int main()
{
    int merg_arr[200],arr1[100],arr2[100],size1,size2;
    int i,j,k;

    printf("Enter the size of array 1: ");
    scanf("%d",&size1);
    printf("Enter the size of array 2: ");
    scanf("%d",&size2);

    printf("Enter elements of 1st sorted array:: ");
    for(i=0;i<size1;i++)
    {
    scanf("%d",&arr1[i]);
    }

    printf("Enter elements of 2nd sorted array:: ");
    for(i=0;i<size2;i++)
    {
    scanf("%d",&arr2[i]);
    }

    i=0;
    j=0;
    k=0;
    
    while(i<size1 && j<size2)
    {
        if (arr1[i] < arr2[j])
        {
            merg_arr[k] = arr1[i];
            i++;
        }

        else
        {
            merg_arr[k]=arr2[j];
            j++;
        }

        k++;
    }

    while(j<size2)
    {
        merg_arr[k] = arr2[j];
        j++;
        k++;
    }

    while(i<size1)
    {
        arr1[k] = arr1[i];
        i++;
        k++;
    }

    printf("Merged elements: \n");
    for(i=0;i<k;i++)
    {
        printf("%d",merg_arr[i]);
    }
}