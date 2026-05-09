/*
9. Write a C program that uses functions to evaluate a simple arithmetic expression
given two numbers and an operator.

Description: The program should prompt the user to enter two floating-point
numbers and an arithmetic operator (+, -, *, /). A separate function must be written for
each operation (add, subtract, multiply, divide). A selector function should take the
operator as a parameter and call the appropriate function, returning the result to main.
Division by zero must be handled gracefully inside the divide function.
Pre-requisites: Functions, Switch/Conditionals, Float Arithmetic, Error Handling.

*/

#include<stdio.h>

float add(float a, float b);
float div(float a, float b);
float mult(float a, float b);
float sub(float a, float b);

float add(float a, float b)
{
    return a+b;    
}

float div(float a, float b)
{
    if(b==0)
    {
        printf("zero division not allowed\n");
        return 0;
    }
    return a/b;
}

float mult(float a, float b)
{
    return a*b;
}

float sub(float a, float b)
{
    return a-b;
}

float calculate(float a,float b, char operator)
{
    switch(operator)
    {
        case '+':
                return add(a,b);
                
        case '-':
                return sub(a,b);
        case '*':
                return mult(a,b);
        case '/':
                return div(a,b);
        default:
                printf("invalid operatior \n");
                return 0;
    }
}


int main()
{
    
    float num1, num2, result;
    char op;

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);  // space given before %c,so it ignores leftover newline from previous input

    printf("Enter second number: ");
    scanf("%f", &num2);

    result = calculate(num1, num2, op);

    printf("Result = %.2f", result);

    return 0;
}