/*
27.Define a structure Complex with real and imaginary parts. Write a C program to add
two complex numbers and display the result.

Description: The program should define a structure to represent a complex number
with two members: real part and imaginary part. It must then create functions to
perform addition of two complex numbers and to display a complex number in a
readable format (e.g., a + bi). The program should take input for two complex
numbers, compute their sum using the defined function, and print the result.
Pre-requisites: Structures, Functions, Basic Arithmetic Operations, Input/Output 

*/

#include<stdio.h>

struct complex         //data type
{
    int real;
    int imag;
};

struct complex add(struct complex c1,struct complex c2 )
{
    struct complex sum;

    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    return sum;
}

void display(struct complex c)
{
     printf("%d + %di", c.real, c.imag);
}


int main()
{
    struct complex c1, c2, result;

    printf("Enter real and imaginary part of first complex number: ");
    scanf("%d %d", &c1.real, &c1.imag);

    printf("Enter real and imaginary part of second complex number: ");
    scanf("%d %d", &c2.real, &c2.imag);

    result = add(c1, c2);

    printf("Sum of complex numbers = ");

    display(result);
}