#ifndef NAMED_PIPE_CLIENT_H
#define NAMED_PIPE_CLIENT_H
#include <Windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;

//���������ڿͻ���ͨ�� CreateFile �򿪵������ܵ����
HANDLE hNamedPipe;
const char * pStr        = "Yu";
//const char * pPipeName    = "\\\\.\\pipe\\YuPipe";
const LPCWSTR    pPipeName    =  _T("\\\\.\\pipe\\YuPipe");

//�������ܵ�
void OpenNamedPipeInClient();

//�ͻ��˴������ܵ��ж�ȡ����
void NamedPipeReadInClient();

//�ͻ����������ܵ���д������
void NamedPipeWriteInClient(); 

#endif