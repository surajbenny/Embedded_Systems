#include<stdio.h>
int main()
{
    int i,j,n;
    printf("enter the number of rows");
    scanf("%d",&n);
    for(i=n;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            printf("* ");
        }
        printf("\n");

    }
}

/*  alternate way
#include<stdio.h>
int main()
{
    int i,j,n;
    printf("enter the number of rows");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=n;j>i;j--)
        {
            printf("* ");
        }
        printf("\n");
    }
} */
