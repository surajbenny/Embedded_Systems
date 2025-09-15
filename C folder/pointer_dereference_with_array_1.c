#include<stdio.h>
int main()

{
    int i;
    float arr[5]={4,22,43,5,6};
    void *arr_ptr=&arr[0]; //  or arr

    for(i=0;i<5;i++)
    {
        printf("the values of array %d: %f\n",i,*((float*)arr_ptr+i));
    }
    return 0;
}
