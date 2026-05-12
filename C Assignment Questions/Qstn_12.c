/*
12.Write a C program that takes a string from the user and checks whether it is a
palindrome.

Description: The program should prompt the user to enter a string. It must determine
if the string reads the same forward and backward. The program should then display a
message to the user stating whether the input is a palindrome or not.
Pre-requisites: Loops, Control Statements, Strings and Operators.

 
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int num,start=0,isPalindrome=1;

    printf("Enter a String: ");
    scanf("%s",str);

    int end = (strlen(str)-1);  // strlen gives the total number of characters in the string before '\0'

    while(start < end)
    {
        if(str[start] != str[end])
        {
            isPalindrome = 0;
            break;
        }
        

        start++;
        end--;
    }

    if (isPalindrome)
    {
        printf("%s is Palindrome string",str);
    }
    else
    {
        printf("%s is Not Palindrome string",str);
    }
}