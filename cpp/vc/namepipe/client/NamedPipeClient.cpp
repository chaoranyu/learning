#include "NamedPipeClient.h"

int main(int argc, char * argv)
{
	OpenNamedPipeInClient();
	
	//���շ���˷���������
	NamedPipeReadInClient();
	
	//�������ܵ���д������
	NamedPipeWriteInClient();
	
	system("pause");
}

void OpenNamedPipeInClient()
{
	//�ȴ����������ܵ�
	if(!WaitNamedPipe(pPipeName, NMPWAIT_WAIT_FOREVER))
	{
		cout<<"�����ܵ�ʵ�������� ..."<<endl<<endl;
		return;
	}
	
	//�������ܵ�
	hNamedPipe = CreateFile(pPipeName, GENERIC_READ | GENERIC_WRITE,
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if(INVALID_HANDLE_VALUE == hNamedPipe)
	{
		cout<<"�������ܵ�ʧ�� ..."<<endl<<endl;
		return;
	}
}

void NamedPipeReadInClient()
{
	char *                pReadBuf;
	DWORD                dwRead;
	pReadBuf = new char[strlen(pStr) + 1];
	memset(pReadBuf, 0, strlen(pStr) + 1);
	//�������ܵ��ж�ȡ����
	if(!ReadFile(hNamedPipe, pReadBuf, strlen(pStr), &dwRead, NULL))
	{
		delete []pReadBuf;
		cout<<"��ȡ����ʧ�� ..."<<endl<<endl;
		return;
	}
	
	cout<<"��ȡ���ݳɹ���    "<<pReadBuf<<endl<<endl;
}

void NamedPipeWriteInClient()
{
	DWORD                dwWrite;
	
	//�������ܵ���д������
	if(!WriteFile(hNamedPipe, pStr, strlen(pStr), &dwWrite, NULL))
	{ 
		cout<<"д������ʧ�� ..."<<endl<<endl;
		return;
	}
	
	cout<<"д�����ݳɹ���    "<<pStr<<endl<<endl;
}