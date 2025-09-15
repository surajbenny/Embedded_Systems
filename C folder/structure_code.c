#include<stdio.h>

struct employee{
    char name[30];
    int id;
    float salary;
};
int main()

{
    int i,ch;
    struct employee e[5];
    for(i=0;i<5;i++)
    {
    printf("Enter the name:%d\n",i+1);
    scanf("%31[^\n]",e[i].name);
    printf("enter the id: %d\n ",i+1);
    scanf("%d",&e[i].id);
    printf("enter the salary:%d\n",i+1);
    scanf("%f",&e[i].salary);
    while(ch=getchar()!='\n'&&ch!=EOF)
    {}
    }

    for(i=0;i<5;i++)
    {

//struct employee e2={"Suraj",102,40}; 
printf("Name %d: %s\nID %d:%d\nsalary%d: %.2f\n",i+1,e[i].name,i+1,e[i].id,i+1,e[i].salary);
//printf("Nme: %s\nid:%d\nsalary:%.2f",e2.name,e2.id,e2.salary);
    }
return 0;
    
}
