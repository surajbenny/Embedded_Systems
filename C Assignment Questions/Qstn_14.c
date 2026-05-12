/*
 14. Write a C program that takes a string input from the user and determines whether it is
a pangram or not.

Description: The program should prompt the user to enter a sentence or a string of
characters. It must then verify if every letter of the alphabet from A to Z appears at
least once within the provided text, regardless of whether the letters are uppercase or
lowercase. The final output should state if the string is a pangram.
Pre-requisites: Loops, Strings, Conditional Statements, ASCII, Operators
*/

#include<stdio.h>
#include<string.h>

int main()
{
    int isPangram=1, alphabet[26]={0},index;
    char str[100];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);     //standard input ,This reads an entire line (sentence) from keyboard and stores it into str.

    int i=0;

    for(i=0;str[i] !='\0';i++)
    {
        if(str[i]>='A' && str[i] <='Z')
        {
            index = str[i]-'A';
            alphabet[index]= 1;
        }

        else if(str[i] >= 'a' && str[i]<= 'z')
        {
            index = str[i]-'a';
            alphabet[index]=1;

        }
    }

    for(i=0;i<26;i++)
    {
        if(alphabet[i] == 0)
        {
            isPangram=0;
            break;
        }
    }

    if(isPangram)
        printf("Pangram");
    else
        printf("not Pangram");
}
