/*
19. Write a C program that takes a number and replaces n of its bits, starting from a
given position, with another set of n bits from a second number.

Description: The program should prompt the user to enter two integers, a starting bit
position, and the number of bits n to be modified. It must then clear $n$ bits in the
first number at the specified position and replace them with the corresponding $n$
bits from the second number. The final resulting value should be displayed on the
screen while all other bits in the first number remain unchanged.
Pre-requisites: Bitwise Operators

*/

#include<stdio.h>

int main()
{
    int mask,bits,n,num1,num2,pos;

    printf("enter two integers: ");
    scanf("%d %d",&num1,&num2);

    printf("Enter starting bit position: ");
    scanf("%d",&pos);

    printf("Enter the number of bits n to be modified: ");
    scanf("%d",&n);

    bits = ((1<<n)-1) & (num2);   // extract n bits from num2
    mask = ((1<<n)-1) << pos;     // create mask at position
    num1 &= ~(mask);              // clear bits in num1
    num1 |= ((bits) << pos);      // insert bits into num1

    printf("Final Result: %d", num1);


}

