/*

*/

#include<stdio.h>

int GCD(int a, int b);

int GCD(int a, int b)
{
    if (b == 0)
        return a;

    return GCD(b, a % b);   // remainder = (a % b)
}


int main()
{
    int num1,num2,result;

    printf("enter two potitive integers ");
    scanf("%d%d",&num1,&num2);

    if(num1 < 0 || num2 < 0)
        printf("\n invalid entry");
    
    result = GCD(num1, num2 );

    printf("\n GCD of %d and %d :  %d", num1,num2,result);

    
    return 0;
}
