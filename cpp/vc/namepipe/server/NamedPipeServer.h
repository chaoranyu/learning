#ifndef NAMED_PIPE_SERVER_H
#define NAMED_PIPE_SERVER_H
#include <Windows.h>
#include <TCHAR.h>
#include <iostream>
using namespace std;

//������������洴���������ܵ����
HANDLE hNamedPipe;
const char *    pStr        =  "Yu";
//const char *    pPipeName    =  "\\\\.\\pipe\\YuPipe";
const LPCWSTR    pPipeName    =  _T("\\\\.\\pipe\\YuPipe");

//���������ܵ�
void CreateNamedPipeInServer();

//�������ܵ��ж�ȡ����
void NamedPipeReadInServer();

//�������ܵ���д������
void NamedPipeWriteInServer();
#endif         