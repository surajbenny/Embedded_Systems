#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,n,new_n;
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

    printf("\nEnter new total number of elements: ");
    scanf("%d", &new_n);
    
    ptr=(int*)realloc(ptr,new_n*(sizeof(int)));

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    //input new value
    if(new_n>n)
    {
        for(i=n;i<new_n;i++){
        printf("enter the new element %d:",i+1);
        scanf("%d",(ptr+i)); // ptr+n
        }
    }

    
    printf("The elements you entered are:");
    for(i=0;i<new_n;i++)
    {
        printf("%d\n",*(ptr+i));
    }
    free(ptr);
    return 0;


}
