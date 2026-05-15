/*
23.Write a C program that rotates the elements of an array by n positions in a
specified direction.

Description: The program should prompt the user to enter the array elements, the
number of positions (n) to rotate, and the direction (left or right). It must then shift the
elements accordingly — elements that fall off one end should reappear at the opposite
end. The rotation must work for any value of n, including values larger than the array
size. The final rotated array should be displayed on the screen.
Pre-requisites: Arrays, Loops, Modulus Operator.


*/

#include<stdio.h>

int main()
{
    int size,temp,rot;
    int arr[200];
    int i,j;
    char dir;

    printf("Enter the size of array: ");
    scanf("%d",&size);

    printf("Enter the elements of array: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter number of rotations: ");
    scanf("%d",&rot);

    printf("Enter direction (L for left, R for right): ");
    scanf(" %c", &dir);

    rot = rot % size;        // remaining rotations needed 
    
    if(dir == 'L' || dir == 'l')
    {
        

        for(i=0;i<rot;i++)
        {
            temp =arr[0];
            for(j=0;j<size-1;j++)
            {
                arr[j] = arr[j+1];

            }
            arr[size-1] = temp;
        }
    }

    else if (dir == 'R' || dir == 'r')
    {
        

        for(i=0;i<rot;i++)
        {
            temp = arr[size-1];

            for(j=size-1;j>0;j--)
            {
                arr[j]=arr[j-1];
            }

            arr[0]=temp;

        }

    }

    printf("Rotated Array: \n");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

}

