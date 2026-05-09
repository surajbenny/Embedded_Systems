#include <stdio.h>

void display_array(int *pArray,int n);
void swap_arrays(int *array1,int *array2,int n1,int n2); 

void display_array(int *pArray,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",pArray[i]);
    }
    printf("\n");
}


void swap_arrays(int *array1,int *array2,int n1,int n2)
{
    int min_len = n1<n2 ? n1 : n2;
    int temp;

    for(int i=0;i < min_len ;i++)
    {
        temp = array1[i];
        array1[i]=array2[i];
        array2[i]=temp;
    }
    

}

int main()
{
    int i,n1,n2;
    printf("enter no of elements in array 1 and array2: ");
    scanf("%d%d",&n1,&n2);

    int arr1[n1],arr2[n2];

    for(i=0;i<n1;i++)
    {
        printf("Enter the array1, %d value: ",i+1);
        scanf("%d",&arr1[i]);
    }

    for(i=0;i<n2;i++)
    {
        printf("Enter the array2, %d value: ",i+1);
        scanf("%d",&arr2[i]);
    }

    printf("Array 1 elements before swap \n");
    display_array(arr1,n1);

    printf("Array 2 elements before swap \n");
    display_array(arr2,n2);

    swap_arrays(arr1,arr2,n1,n2);

    printf("Array 1 elements after swap \n");
    display_array(arr1,n1);

    printf("Array 2 elements after swap \n");
    display_array(arr2,n2);

}
