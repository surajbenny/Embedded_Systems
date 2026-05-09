/*
    Write a C program that uses a function to count the frequency of each digit (0–9)
    in a given integer.
    
    Description: The program should prompt the user to enter an integer. A separate
    function must be written that takes the number, extracts each digit using a loop, and
    updates a frequency array accordingly. The function should not return a single value
    but instead update the array directly. The main function should then print how many
    times each digit appears in the number.
    Pre-requisites: Functions, Arrays, Loops, Pass by Reference (Pointers).
*/

#include<stdio.h>

void count(int num,int *pArray);

void count(int num, int *pArray)
{
    int digit;

    if(num==0)
        pArray[0]++;

    while(num > 0)
    {
        digit= num%10;
        pArray[digit] = pArray[digit]+1;      // count increased by 1 if digits repeat

        num = num/10;
    }
}

int main()

{
 
    int n,freq[10]={0};


    printf("Enter an Integer: ");
    scanf("%d",&n);

    count(n,freq);                      //freq array is passing the address of first element only

    printf("Digit frequencies : \n");

    for(int i=0;i<10;i++)
    {
        printf("digit %d = %d times \n",i,freq[i]);
    }

    return 0;

}

// Don’t return or use addresses of local variables after the function ends
// Local variables are fine inside functions, but you must not use their memory after the function ends.

