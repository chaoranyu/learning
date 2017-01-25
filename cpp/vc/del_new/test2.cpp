#include <iostream>
#include <cstdio>
using namespace std;

struct foo
{
    ~foo(){}; //去掉后,就不会记录个数了.
};


int main(int argc,char *argv[])
{

     foo* f = new foo;
     delete f;
     f=0;
     //delete f;

     foo* fa = new foo[8];
     printf("%u\n", *((char *)fa - 8)); //输出8:辅助析构函数.
     /*
     对于有显式析构函数的对象的数组，
     编译器会在数组前分配4个字节储存数组元素的个数
     （也就是需要调用析构函数的次数），
     因为必须知道数组实际的元素合个数，
     delete[]才能知道需要调用几次析构函数。
     */
     //delete fa; //有的编译器这里会有异常.
     //用delete而不是delete[]释放用new[]分配的空间这种行为是undefined的，
     //也就是由编译器实现所决定的
     //fa = 0;
     delete []fa;
     fa = 0;

     return 0;
}
