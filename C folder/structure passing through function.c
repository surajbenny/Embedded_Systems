#include<stdio.h>

struct employee{
    char name[32];
    int id;
    float salary;

};

void increment(struct employee e,float percentage)
{
    e.salary=e.salary+((e.salary*percentage/100));
    printf("new salary in function local copy %f\n",e.salary);
}

int main()
{
    struct employee e= {"suraj",101,3000};
    increment(e,10);
    printf("Salary in main function %f \n",e.salary);
    return 0;
}
