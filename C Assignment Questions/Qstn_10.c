/*
 10. Write a C program that takes a string of digits from the user and converts it into its equivalent
integer value.

Description:The program should prompt the user to enter a number as a string (for example,
"1234"). It must then process this string character by character and transform it into an actual
integer variable that can be used for mathematical operations. The program should be able to
handle positive numbers and display the final integer result on the screen.
Pre-requisites: Loops, Strings, Operators.
*/

#include<stdio.h>

int string_to_integer(char str_num[])
{
    int num=0,digit;

    int i=0;

    while(str_num[i] != '\0')
    {

    digit = str_num[i] - '0';   // Convert character to integer digit

    num = num*10 + digit;

    i++;
    }
    
    return num;
}

int main()
{
    char str[100];
    int result;

    printf("Enter a number as a string: ");
    scanf("%s",str);

    result = string_to_integer(str);

    printf("Integer value = %d",result);

    return 0;


}
