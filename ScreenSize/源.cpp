// #define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<tchar.h>


#include<stdio.h>

int CDECL MessageBoxPrintf(const TCHAR *szCaption, const TCHAR *szFormat, ...)
{
	/*CDECLΪC/C++Ĭ�ϵĺ������÷�ʽ*/
	/*��1��2����ڲ�������Ҫ��const�������޷�����ͨ��*/
	TCHAR szBuffer[1024];
	va_list pArgList;
	va_start(pArgList, szFormat);
	_vsnwprintf_s(szBuffer, sizeof(szBuffer) / sizeof(TCHAR),
		sizeof(szBuffer) / sizeof(TCHAR), szFormat, pArgList);
	va_end(pArgList);

	return MessageBox(NULL, szBuffer, szCaption, 0);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, PSTR szCmdLine, int iCmdShow)
{
	int cxScreen, cyScreen;
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);

	MessageBoxPrintf(TEXT("ScrnSize"),
		TEXT("The screen is %i pixels wide by %i pixels high."),
		cxScreen, cyScreen);

	return 0;
}