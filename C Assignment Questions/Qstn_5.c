/*
5. Write a C program that uses a function to check whether a given number is a
Perfect Number.

Description: The program should prompt the user to enter a positive integer. A
separate function must be written that computes the sum of all proper divisors of the
number (excluding the number itself) and returns whether the sum equals the original
number. The main function should display whether the number is perfect or not.
(Example: 6 = 1+2+3, 28 = 1+2+4+7+14)
Pre-requisites: Functions, Loops, Return Values.
*/

#include<stdio.h>

int perfect_number(int n);

int main()
{
    int num,result;

    printf("Enter a Positive Integer: ");
    scanf("%d",&num);

    result = perfect_number(num);

    if(result)
    {
        printf("\n %d is a Perfect number",num);
    }
    else
        printf("\n %d is not Perfect number",num);


    return 0;
    


}

int perfect_number(int n)
{
    int i,sum=0;

    printf("Divisors of %d: ",n);
    for(i=1;i<n;i++)
    {
        if(n%i == 0)
        {
            printf("%d \n",i);
            sum = sum +i;
        }
    }

    return (sum == n);
    

}