/*
20.Write a C program that takes two integers and swaps n bits starting from a given
position in both numbers.

Description: The program should prompt the user to enter two integers, a starting bit
position, and the number of bits (n) to be swapped. It must then exchange the n
consecutive bits at the specified position between the two numbers — the bits from
the first number go into the second, and vice versa — while all remaining bits in both
numbers stay exactly as they were. Both final values should be displayed on the
screen after the swap.
Pre-requisites: Bitwise Operators, Loops, Assignment Operators.

*/

#include<stdio.h>

int main()
{
    int mask,bits1,bits2,n,num1,num2,pos;

    printf("enter two integers: ");
    scanf("%d %d",&num1,&num2);

    printf("Enter starting bit position: ");
    scanf("%d",&pos);

    printf("Enter the number of bits n to be modified: ");
    scanf("%d",&n);

    bits1 = num1 &((1 << n)-1 << pos);
    bits2 = num2 &((1 << n)-1 << pos);

    num1 &= ~(((1 << n)-1)<< pos);
    num2 &= ~(((1<<n)-1 << pos));

    num1 |= (bits2);
    num2 |=(bits1);

    printf("swapped num1: %d\n",num1);
    printf("sswapped num2: %d\n",num2);
}