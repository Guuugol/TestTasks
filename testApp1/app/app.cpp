// app.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "app.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������������ ������ ����������

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// ���������������� MFC, � ����� ������ � ��������� �� ������� ��� ����
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: �������� ��� ������ �������������� ����� ������������
			_tprintf(_T("����������� ������: ���� ��� ������������� MFC\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: �������� ���� ��� ��� ����������.
		}
	}
	else
	{
		// TODO: �������� ��� ������ �������������� ����� ������������
		_tprintf(_T("����������� ������: ��������� ���������� GetModuleHandle\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
