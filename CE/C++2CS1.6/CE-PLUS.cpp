#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>  
#include <stdlib.h>

int main(int argc, char* argv[])
{
	DWORD  getLastError;  
    //1.���ݴ�������ȡ����  
	HWND hWinmine = FindWindow(NULL,"Counter-Strike");
    DWORD dwPID = 0;  //���ڽ��̱�ʾ
	//2.���ݴ��ڻ�ȡpid 
    GetWindowThreadProcessId(hWinmine, &dwPID);  
    if (dwPID == 0)  
    {  
        printf("��ȡPIDʧ��\n");  
        return -1;  
    }  
	//3.����pid��ȡ����
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dwPID);  
    if (hProcess == NULL) 
    {  
        printf("���̴�ʧ��\n");  
        getLastError = GetLastError();  
        return -1;  
    }  
  
    DWORD dwNum = 0, dwSize = 0;  
      
    //��ַ  
    DWORD CSBaseAddress = 0x025069BC;  
    //��ֵַ  
    DWORD CSBaseAddressValue = 0;  
    if (0 == ReadProcessMemory(hProcess, (LPVOID)CSBaseAddress, &CSBaseAddressValue, sizeof(DWORD), &dwSize))  
    {  
        printf("��ַ̬��ȡʧ��\n");  
        getLastError = GetLastError();  
        return -1;  
    }  

    //һ��ƫ��  
    DWORD CSOffsetFirst = 0x7C;  
    //һ��ƫ��ֵ  
    DWORD CSOffsetFirstValue = 0;  
    if (0 == ReadProcessMemory(hProcess, (LPVOID)(CSBaseAddressValue + CSOffsetFirst), &CSOffsetFirstValue, sizeof(DWORD), &dwSize))  
    {  
        printf("һ��ƫ�ƻ�ȡʧ��\n");  
        getLastError = GetLastError();  
        return -1;  
    }  
  
    //����ƫ��  
    DWORD CSOffsetSecond =  0x5EC;  
    //����ƫ��ֵ  
    DWORD CSOffsetSecondValue = 0;  
    if (0 == ReadProcessMemory(hProcess, (LPVOID)(CSOffsetFirstValue + CSOffsetSecond), &CSOffsetSecondValue, sizeof(DWORD), &dwSize))  
    {  
        printf("����ƫ�ƻ�ȡʧ��\n");  
        getLastError = GetLastError();  
        return -1;  
    }

	//����ƫ��  
    DWORD CSOffsetThird = 0xCC;  
    DWORD CSNum=0;  //�����ǵ�ǰ�ӵ�ֵ
    if (0 == ReadProcessMemory(hProcess, (LPVOID)(CSOffsetSecondValue + CSOffsetThird), &CSNum, sizeof(DWORD), &dwSize))  
    {  
        printf("����ƫ�ƻ�ȡʧ��\n");  
        getLastError = GetLastError();  
        return -1;  
    }

    int modifyCS;  
    printf("CSNum:%d\n", CSNum);  
    printf("������Ҫ�޸ĺ��ֵ��");  
    scanf("%d", &modifyCS);  
	//����ֵ
    WriteProcessMemory(hProcess, (LPVOID)(CSOffsetSecondValue + CSOffsetThird), &modifyCS, sizeof(DWORD), &dwSize);  
      
    CloseHandle(hProcess);  //�رս���
    system("pause");  //����ͣ��
	return 0;
}

