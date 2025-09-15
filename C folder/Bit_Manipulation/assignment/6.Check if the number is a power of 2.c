//6.Check if the number is a power of 2?
#include<stdio.h>

void ispoweroftwo(int n)
{
    if (n>0 && ((n&(n-1))==0)) 
    printf("%d is power of 2 ",n);
    else
    printf("%d is NOT power of 2 ",n);
}

int main()
{
    int c;
    printf("enter the number: ");
    scanf("%d",&c);
    ispoweroftwo(c);
    return 0;
}