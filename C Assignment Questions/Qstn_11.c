/*
11.Write a C program that takes an integer from the user and converts it into a
string of characters.

Description:The program should prompt the user to enter a whole number. It must
then process this integer and store each of its digits as characters within a character
array (string). The resulting string should represent the number exactly as it was
entered, including a negative sign if the number is less than zero. Finally, the program
should display the resulting string on the screen.
Pre-requisites: Strings, Loops, Operators.

*/

#include<stdio.h>

int main()
{
   int i=0,temp,num,isNegative=0,digit;
   char str[100];


    printf("Enter a whole number: ");
    scanf("%d",&num);

    // number zero comes
    if(num == 0)
    {
        str[i] = '0';
        i++;
    }

// negative number handling
    if (num <0)
    {
        isNegative = 1;
        num = -num;
    }

    temp =num;

    while(temp > 0)
    {
        digit = temp%10;
        str[i] = digit + '0';
        temp= temp/10;
        i++;
    }
   
    if (isNegative)
    {
        str[i] = '-';
        i++;
    }

    str[i]= '\0';

    int start =0, end = i-1;
    char t;

    while(start < end)
    {
        t = str[start];
        str[start] = str[end];
        str[end] = t;

        start ++;
        end --;
    }

    printf("String form : %s",str);
}