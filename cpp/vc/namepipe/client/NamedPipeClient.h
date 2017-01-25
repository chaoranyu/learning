#ifndef NAMED_PIPE_CLIENT_H
#define NAMED_PIPE_CLIENT_H
#include <Windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

//用来保存在客户端通过 CreateFile 打开的命名管道句柄
HANDLE hNamedPipe;
const char * pStr        = "Yu";
//const char * pPipeName    = "\\\\.\\pipe\\YuPipe";
const LPCWSTR    pPipeName    =  _T("\\\\.\\pipe\\YuPipe");

//打开命名管道
void OpenNamedPipeInClient();

//客户端从命名管道中读取数据
void NamedPipeReadInClient();

//客户端往命名管道中写入数据
void NamedPipeWriteInClient(); 

#endif