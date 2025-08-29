#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,n;
    int *ptr;

    printf("enter the number of element: ");
    scanf("%d",&n);

    ptr=(int*)calloc(n,(sizeof(int)));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    

    for(i=0;i<n;i++)
    {
    printf("enter the element %d:",i+1);
    scanf("%d",(ptr+i));
    }


    
    printf("The elements you entered are:");
    for(i=0;i<n;i++)
    {
        printf("%d\n",*(ptr+i));
    }
    free(ptr);
    return 0;


}
