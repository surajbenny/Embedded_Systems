/*
22.Write a C program that uses an array to find the second largest and second
smallest element in a list of numbers.

Description: The program should prompt the user to enter the size of the array and its
elements. It must then scan through the array and determine both the second largest
and second smallest values without sorting the array. The program should handle
duplicate values correctly — if all elements are the same, it should display an
appropriate message. Both results should be displayed on the screen.
Pre-requisites: Arrays, Loops, Conditional Statements.

*/

#include<stdio.h>

int main()
{
    int arr[100],size;
    int largest,second_largest, smallest , second_smallest;
    int i;

    printf("Enter size of array");
    scanf("%d",&size);

    printf("Enter the elemenets: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    largest = second_largest = -3000;
    smallest = second_smallest = 3000;

    for(i=0;i<size;i++)
    {
        if(arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }

        else if ( arr[i]>second_largest && arr[i] != largest )
              {
                second_largest= arr[i];
              }


        if(arr[i] < smallest )
        {
            second_smallest = smallest;
            smallest = arr[i];
        }

        else if( arr[i] < second_smallest && arr[i] != smallest)
        {
            second_smallest = arr[i];
        }




    }

    if( second_largest == -3000 || second_smallest == 3000 )
    {
        printf("All elements are same");
    }
    else
    {
        printf("Second Largest = %d\n", second_largest);
        printf("Second Smallest = %d\n", second_smallest);
    }

}

