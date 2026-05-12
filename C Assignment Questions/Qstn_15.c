/*
 15. Write a C program that takes a string from the user and replaces every sequence of
multiple consecutive spaces with a single space.

Description: The program should prompt the user to enter a sentence that may
contain several spaces between words. It must then process the string to ensure that
any instance where two or more blank spaces appear together is reduced to just one
blank space. The final cleaned string should be displayed on the screen.
Pre-requisites: Loops, Strings, Conditional Statements, ASCII, Operators

*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[200];
    int j=0,i;

    printf("enter a sentence that may contain several spaces between words: ");
    fgets(str,sizeof(str),stdin);

    for(i=0;str[i] != '\0';i++)
    {
        str[j]=str[i];

        if((str[i] == ' ') && (str[i+1] == ' '))
        {
            continue;    // skips j++ and move on to next iteration
        }

        j++;
    }

    str[j]='\0';

    printf("cleaned string : %s",str);


}
