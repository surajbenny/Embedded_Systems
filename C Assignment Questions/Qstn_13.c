/*
 13.Write a C program that takes a string from the user and reverses its characters using
an iterative approach.

Description: The program should prompt the user to enter a sequence of characters. It
must then swap or move the characters within the string using a loop until the entire
string is reversed. The final resulting string should be displayed on the screen.
Pre-requisites: Loops, Strings. Operators.
*/

#include<stdio.h>
#include<string.h>

int main()
{
    int start=0,end;
    char str[100],t;

    printf("Enter a sequence of characters: ");
    scanf("%s",str);

    end = strlen(str)-1;

    while(start < end)
    {
        t = str[start];
        str[start]= str[end];
        str[end] = t;

        start++;
        end--;
    }

    printf("Reversed string: %s",str);
}

