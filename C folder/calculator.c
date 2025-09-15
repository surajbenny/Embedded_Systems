// Online C compiler to run C program online
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

float division(int num1, int num2) {
    if (num2 == 0) {
        printf("Error: Division by zero is undefined.\n");
        return 0;
}}

int main()
{
    int num1,num2,sum,product,diff,input;
    int divi;
    printf("Enter the operation \n 1) addition \n 2) subtraction \n 3) multiplication \n 4) division \n");
    scanf("%d",&input);
    printf("Enter the first number: ");
    scanf("%d",&num1);
    printf("Enter the second number: ");
    scanf("%d",&num2);
    

    if (input == 1){
    sum=add(num1,num2);
    printf("the sum is %d \n",sum);
    }
    else if(input == 3){ 
    product=multiplication(num1,num2);
    printf("the product is %d \n",product);
    }
    else if(input == 2){
    diff=sub(num1,num2);
    printf("the difference is %d \n",diff);
    }
    else if (input == 4){
    divi=division(num1,num2);
    printf("The division result is %f ",divi);
    }
    else
    {
        printf("invalid selection");
    }
 
    return 0;
}
