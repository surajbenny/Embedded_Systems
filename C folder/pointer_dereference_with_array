#include<stdio.h>
int main()
{
    int i;
    int arr[5];
    void *ptr=arr; // &arr[0]
    printf("enter the values");
    for(i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<5;i++)
    {
        printf("index value  %d is  : %d\n",i,*((int*)ptr+i));
    }
}
