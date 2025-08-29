#include<stdio.h>

void printBin(int n){
    int i,mask;
    for(i=31;i>=0;i--){
    mask=1<<i;
    if(n&mask)
    printf("1");
    else
    printf("0");
    }

printf("\n");
}

void setBit(int n,int pos){
    int mask;

    mask=1<<pos;
    n=n|mask;
    printf("value after setting the bit at position %d:\n",pos);
    printBin(n);
    
}

void clearBit(int n,int pos){
    int mask;
    mask=~(1<<pos);
    n=n&mask;
    printf("Value after clearing the bit at position %d:\n", pos);
    printBin(n);

}
int main()

{
    int a,c,s;
    printf("enter a number:");
    scanf("%d",&a);
    printBin(a);
    printf("enter the position to set bit");
    scanf("%d",&s);
    setBit(a,s);
    printf("enter the position to clear bit");
    scanf("%d",&c);
    clearBit(a,c);

    return 0;



   }
