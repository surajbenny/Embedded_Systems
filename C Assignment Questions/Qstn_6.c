/*
    6. Write a C program that uses a recursive function to find the GCD of two
    numbers using the Euclidean algorithm.

    Description: The program should prompt the user to enter two positive integers. A
    recursive function must be written that repeatedly applies the Euclidean method
    replacing the larger number with the remainder of dividing the two until the
    remainder is zero. The GCD should be returned to the main function and displayed on
    the screen.
    Pre-requisites: Functions, Recursion, Modulus Operator.
*/

#include<stdio.h>

int GCD(int a, int b);

int GCD(int a, int b)
{
    if (b == 0)
        return a;

    return GCD(b, a % b);   // remainder = (a % b)
}


int main()
{
    int num1,num2,result;

    printf("enter two potitive integers ");
    scanf("%d%d",&num1,&num2);

    if(num1 < 0 || num2 < 0)
        printf("\n invalid entry");
    
    result = GCD(num1, num2 );

    printf("\n GCD of %d and %d :  %d", num1,num2,result);

    
    return 0;
}
