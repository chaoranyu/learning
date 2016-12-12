#include <fstream>
#include <cassert>

int main( void )
{
    std::fstream fs;

    fs.open("test.txt", std::fstream::out);//以可写的方式打开一个文件，如果不存在就创建一个同名文件
    assert(fs.is_open());                           //所以这里不会出错
    fs.close();

    fs.open("noexitfile.txt", std::ios::in);//以只读的方式打开一个文件，如果不存在就打开文件失败
    assert(fs.is_open());                           //所以这里出错
    fs.close();                           //程序永远都执行不到这里来

    return 0;
}
