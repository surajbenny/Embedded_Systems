/*
4. Write a C program to generate the Fibonacci series up to a given number of terms.


Description: The program should prompt the user to enter the number of terms (n). It
should then generate the Fibonacci sequence, where each number is the sum of the
two preceding ones, starting from 0 and 1. The program must display the sequence up
to the specified number of terms.
Pre-requisites: Loops, Variables, Basic Arithmetic Operations
*/

#include<stdio.h>

int main()
{
    int num,a=0,b=1,result,i;

    printf("Enter the number of terms: ");
    scanf("%d",&num);

  

    if (num < 0)
    {
        printf("invalid entry");
        return 0;
    }

    printf("Fibnocci of %d terms :",num);

    for(i=1;i<=num;i++)
    {
        printf("%d ",a);
        
        result =a+b;
        a=b;
        b=result;
        

    }


    

    
    
}

   

        

    
