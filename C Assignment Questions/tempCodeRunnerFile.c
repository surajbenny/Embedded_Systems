#include<stdio.h>
#include<string.h>

int main()
{
    char str[100], temp[100];
    int num,i=0, start=0,isPalindrome=0;

    printf("Enter a String: ");
    scanf("%s",str);

    int end = (strlen(str)-1);  // gives the total number of characters in the string before '\0'

    while(start < end)
    {
        if(str[start] == str[end])
            isPalindrome = 1;
        else
            isPalindrome = 0;
            
        

        start++;
        end--;
    }