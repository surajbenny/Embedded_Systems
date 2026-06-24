#include<stdio.h>


int second_largest(int arr[],int size)
{


int largest = -3000;
int sec_larg = -3000;
    int i;
    for(i=0;i<size;i++)
    {
        if (arr[i] > largest )
        {
            sec_larg = largest;
            largest = arr[i];
        }
        else if(arr[i]>sec_larg && (arr[i] != largest))
        {
            sec_larg = arr[i];
        }
    }
    
    return sec_larg;
}
int main()
{ 
    int arr1[100],size,i;
    
    printf("Enter the size of array: \n");
    scanf("%d",&size);
    printf("Enter the elements of array: \n");
    for(i=0;i<size;i++)
    scanf("%d",&arr1[i]);
    
    int result = second_largest(arr1,size);
    printf("Second largest = %d\n", result);
     
  
    }
