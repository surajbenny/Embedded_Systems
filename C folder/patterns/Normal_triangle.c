#include<stdio.h>
int main()
{
    int i,j,n,k;
    printf("enter the number of rows");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=n;j>i;j--)
        {
            printf(" ");
        }
        for(k=0;k<=i;k++){
        printf("* ");
        }
        printf("\n");
    }
    return 0;
}
