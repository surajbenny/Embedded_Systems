/*
18.Write a C program that takes an integer from the user and extracts (n) bits starting
from a specific bit position.

Description: The program should prompt the user to enter a number, a starting
position, and the number of bits to be retrieved. It must then isolate that specific
sequence of bits from the original value and display the resulting number on the
screen. The other bits in the number should not affect the final output.
Pre-requisites: Bitwise Operators.


*/

#include<stdio.h>

int main()
{
    int num,pos,n,mask;

    printf("Enter an integer: ");
    scanf("%d",&num);

    printf("Enter starting bit position: ");
    scanf("%d", &pos);

    printf("Enter number of bits to be retrieved: ");
    scanf("%d", &n);


    //extractiom of bits
    num = num >> pos;
    mask = ((1<<n)-1);
    num = num & mask;

    printf("extracted bit: %d",num);
}

