/*
16. Write a C program that takes a string from the user and converts all uppercase letters
into their corresponding lowercase letters.

Description: The program should prompt the user to enter a sequence of characters. It
must then check each character individually. If a character is an uppercase letter, the
program should convert it to its lowercase equivalent. If the character is already
lowercase or is not a letter at all, the program should leave it exactly as it is. The final
modified string should be displayed on the screen.
Pre-requisites: Loops, Strings, Conditional Statements, ACII.

*/

#include<stdio.h>
#include<string.h>

int main()
{
    int i=0;
    char str[200];

    printf("Enter a sequence of characters: ");
    fgets(str,sizeof(str),stdin);

    for(i=0;(str[i]) != '\0';i++)
    {
       
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i]-'A'+ 'a'; 
        }

    }

    printf("%s",str);
}
