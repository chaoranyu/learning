#include<stdio.h>

void func1();
void func2(int *a);

void func1()
{
    int a=0;
    func2(&a);
}
void func2(int *a)
{
    int b=0;
    printf("%x\n%x\n", a, &b);
}


int main()
{
    func1();
}
