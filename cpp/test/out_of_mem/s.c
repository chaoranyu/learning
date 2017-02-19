#include<stdio.h>

void func1();
void func2();

void func1()
{
    int a=0;
    printf("%x\n", &a);
}
void func2()
{
    int b=0;
    printf("%x\n", &b);
}


int main()
{
    func1();
    func2();
}
