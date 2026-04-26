/*
3. Write a C program that takes a positive integer from the user and calculates its
factorial.

Description: The program should prompt the user to enter a single whole number. It
must then calculate the factorial of that number, which is the product of all positive
integers from 1 up to the number entered. The final result should be displayed clearly
on the screen. The program should also account for the fact that the factorial of 0 is
Pre-requisites: Operators, Data Types, Loops.
*/

#include<stdio.h>

int main()
{
    int num,i,fact=1;

    printf("Enter a single whole number : ");
    scanf("%d",&num);

    if (num < 0)
    {
        printf("invalid entry");
        return 0;
    }

    for(i=1;i<=num;i++)
    {
        fact = fact*i;
    }

    printf("Factorial of %d is %d ",num,fact);
    
    
}

   

        

    
