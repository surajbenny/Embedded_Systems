/*
8. Write a C program that uses functions to convert a decimal number to any base
between 2 and 16.

Description: The program should prompt the user to enter a decimal number and a
target base. A separate function must be written that performs the repeated division
method, stores each remainder, and builds the result in the correct order. For bases
above 9, remainders 10–15 should be represented as letters A–F. The converted value
should be displayed from the main function.
Pre-requisites: Functions, Loops, Arrays, Character Handling.

*/

#include<stdio.h>

void decimal_to_base (int num, int base);

void decimal_to_base (int num, int base)
{
    int rem,i=0;
    char result[32];

    if(num == 0)
        result[0]='0';


    while(num > 0)
    {
        rem = num % base;

        if(rem > 9)
        {
            result[i]= rem-10 + 'A';      // hex value (A is ASCII)
        }
        else
        {
            result[i]= rem + '0';
        }

        num = num /base ;
        i++;
        //printf("i= %d\n",i);
        
    }

    //reversed the array element
    for(int j=(i-1);j>=0;j--)
    {
        printf("%c",result[j]);
    }

}


int main()
{
    int n,b;

    printf("Enter decimal number: ");
    scanf("%d", &n);

    printf("Enter base (2 to 16): ");
    scanf("%d", &b);

    if(b <=2 || b>=16)
    {
        printf("Invalid base");
        return 0;
    }
    

    printf("Converted value: ");
    decimal_to_base(n,b);
    
}