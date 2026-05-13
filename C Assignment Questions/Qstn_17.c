/*
17. Write a C program that takes a number and toggles a specific number of bits (n)
starting from a given position.

Description: The program should prompt the user to enter an integer, a starting bit
position, and the number of bits to be modified. It must then change the state of those
(n) consecutive bits—switching 0s to 1s and 1s to 0s—while keeping all other bits in
the number exactly as they were. The final value of the number after the toggle
operation should be displayed on the screen.
Pre-requisites: Bitwise operators, Loops, Assignment operators.


*/

#include<stdio.h>

int main()
{
    int num,pos,n,mask;
    printf("Enter an integer: ");
    scanf("%d",&num);

    printf("Enter starting bit position: ");
    scanf("%d", &pos);

    printf("Enter number of bits to toggle: ");
    scanf("%d", &n);

    mask = ((1<<n)-1) << pos ;

    num = num ^ mask;

    printf("After toggle: %d",num);
}

