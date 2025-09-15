#include <stdio.h>

int add(int num1,int num2)
{
  int sum=num1+num2;
  return sum;
}

int sub(int num1,int num2)
{
    int sub= num1-num2;
    return sub;
}

int multiplication(int num1,int num2)
{
    int product= num1*num2;
    return product;
}

float division(int num1, int num2)
{
    float division=(float)num1/num2;
    return division;
}
int main()
{
    int num1,num2,sum,product,diff;
    float divi;
    printf("Enter the first number: ");
    scanf("%d",&num1);
    printf("Enter the second number: ");
    scanf("%d",&num2);
    
    sum=add(num1,num2);
    printf("the sum is %d \n",sum);
    
    product=multiplication(num1,num2);
    printf("the product is %d \n",product);
    
    diff=sub(num1,num2);
    printf("the difference is %d \n",diff);
    
    divi=division(num1,num2);
    printf("The division result is %f ",divi);
 

    return 0;
}
