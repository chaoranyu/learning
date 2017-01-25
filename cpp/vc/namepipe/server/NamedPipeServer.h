#ifndef NAMED_PIPE_SERVER_H
#define NAMED_PIPE_SERVER_H
#include <Windows.h>
#include <TCHAR.h>
#include <iostream>
using namespace std;

//服务端用来保存创建的命名管道句柄
HANDLE hNamedPipe;
const char *    pStr        =  "Yu";
//const char *    pPipeName    =  "\\\\.\\pipe\\YuPipe";
const LPCWSTR    pPipeName    =  _T("\\\\.\\pipe\\YuPipe");

//创建命名管道
void CreateNamedPipeInServer();

//从命名管道中读取数据
void NamedPipeReadInServer();

//往命名管道中写入数据
void NamedPipeWriteInServer();
#endif         