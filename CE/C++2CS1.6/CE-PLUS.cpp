#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>  
#include <stdlib.h>

int main(int argc, char* argv[])
{
	DWORD  getLastError;  
    //1.根据窗口名获取窗口  
	HWND hWinmine = FindWindow(NULL,"Counter-Strike");
    DWORD dwPID = 0;  //窗口进程标示
	//2.根据窗口获取pid 
    GetWindowThreadProcessId(hWinmine, &dwPID);  
    if (dwPID == 0)  
    {  
        printf("获取PID失败\n");  
        return -1;  
    }  
	//3.根据pid获取进程
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dwPID);  
    if (hProcess == NULL) 
    {  
        printf("进程打开失败\n");  
        getLastError = GetLastError();  
        return -1;  
    }  
  
    DWORD dwNum = 0, dwSize = 0;  
      
    //基址  
    DWORD CSBaseAddress = 0x025069BC;  
    //基址值  
    DWORD CSBaseAddressValue = 0;  
    if (0 == ReadProcessMemory(hProcess, (LPVOID)CSBaseAddress, &CSBaseAddressValue, sizeof(DWORD), &dwSize))  
    {  
        printf("静态址获取失败\n");  
        getLastError = GetLastError();  
        return -1;  
    }  

    //一级偏移  
    DWORD CSOffsetFirst = 0x7C;  
    //一级偏移值  
    DWORD CSOffsetFirstValue = 0;  
    if (0 == ReadProcessMemory(hProcess, (LPVOID)(CSBaseAddressValue + CSOffsetFirst), &CSOffsetFirstValue, sizeof(DWORD), &dwSize))  
    {  
        printf("一级偏移获取失败\n");  
        getLastError = GetLastError();  
        return -1;  
    }  
  
    //二级偏移  
    DWORD CSOffsetSecond =  0x5EC;  
    //二级偏移值  
    DWORD CSOffsetSecondValue = 0;  
    if (0 == ReadProcessMemory(hProcess, (LPVOID)(CSOffsetFirstValue + CSOffsetSecond), &CSOffsetSecondValue, sizeof(DWORD), &dwSize))  
    {  
        printf("二级偏移获取失败\n");  
        getLastError = GetLastError();  
        return -1;  
    }

	//三级偏移  
    DWORD CSOffsetThird = 0xCC;  
    DWORD CSNum=0;  //这里是当前子弹值
    if (0 == ReadProcessMemory(hProcess, (LPVOID)(CSOffsetSecondValue + CSOffsetThird), &CSNum, sizeof(DWORD), &dwSize))  
    {  
        printf("三级偏移获取失败\n");  
        getLastError = GetLastError();  
        return -1;  
    }

    int modifyCS;  
    printf("CSNum:%d\n", CSNum);  
    printf("输入你要修改后的值：");  
    scanf("%d", &modifyCS);  
	//更改值
    WriteProcessMemory(hProcess, (LPVOID)(CSOffsetSecondValue + CSOffsetThird), &modifyCS, sizeof(DWORD), &dwSize);  
      
    CloseHandle(hProcess);  //关闭进程
    system("pause");  //窗口停留
	return 0;
}

