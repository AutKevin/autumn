#define UNICODE
#define _UNICODE
#include <stdio.h>
#include <windows.h>  
#include "iostream"
#include <stdlib.h>   //引入头文件使用system方法
using namespace std;

int main(){

    //L表示转换成宽字符,Unicode字符集下必须带L表示每个字符占用两个字节
    /*查找窗口，必须用spy++查找窗口功能，不然窗口名后面多一个空格是看不出来的*/
    HWND hGameWnd = FindWindow(L"MainWindow",L"Plants vs. Zombies GOTY ");   

    //1.判断程序是否运行
    if(hGameWnd == NULL){
        printf("程序未运行，请先运行！\n");
        system("pause");  //防止cmd一闪而过
        return 0;
    }else{
        printf("程序已运行！\n");
    }
    
    //2.根据窗口获取进程的ID
    unsigned long dwPID = 0;
    GetWindowThreadProcessId(hGameWnd,&dwPID);
    if(dwPID == 0){
        printf("获取进程PID失败.\n");
        system("pause");  //防止cmd一闪而过
        return 0;
    }

    //3.根据PID获取植物大战僵尸进程句柄
    //进程句柄：用来标记一个exe，句柄：相当于进程的ID
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS,false,dwPID);
    if(hProcess == NULL){
        printf("获取进程失败!\n");
        system("pause");  //防止cmd一闪而过
        return 0;
    }

    //4.读取内存
    unsigned long dwSunshineBaseAddress = 0x00779618;   //基址，CE查到绿色的为止
    unsigned long dwSunshineBaseValue = 0;
    unsigned long dwSize = 0;

    if(FALSE == ReadProcessMemory(
        hProcess,   //进程
        (void*)dwSunshineBaseAddress,  //要读取的内存地址
        &dwSunshineBaseValue,   //独处出来的数据，存到这个变量中
        sizeof(unsigned long),   //读取四个字节
        &dwSize  //实际读取的字节数
    )){
        printf("获取静态地址失败，错误代码:%d\n",GetLastError());
        system("pause");  //防止cmd一闪而过
        return 0;
    }

    //进行第一次偏移，CE最后找到的那一个偏移量
    unsigned long dwSunshineOffsetFirst = 0x868;
    unsigned long dwSunshineOffsetFirstValue = 0;

    if(FALSE == ReadProcessMemory(
        hProcess,   //游戏进程
        (void*)(dwSunshineBaseValue+dwSunshineOffsetFirst),    //第二次读取出来的地址
        &dwSunshineOffsetFirstValue,   //读取出来的内存
        sizeof(unsigned long),   //读取四个字节
        &dwSize  //实际读取的字节数
    )){
        printf("一级偏移失败.错误代号:%d\n",GetLastError());
        system("pause");  //防止cmd一闪而过
        return 0;
    }

    //进行第二次偏移，CE最后找到的倒数第二个偏移量
    unsigned long dwSunshineOffsetSecond = 0x5578;
    unsigned long dwSunshineValue = 0;  //第二次即是阳光值

    if(FALSE == ReadProcessMemory(
        hProcess,   //游戏进程
        (void*)(dwSunshineOffsetFirstValue+dwSunshineOffsetSecond),    //第三次读取出来的地址
        &dwSunshineValue,   //读取出来的内存
        sizeof(unsigned long),   //读取四个字节
        &dwSize  //实际读取的字节数
    )){
        printf("一级偏移失败.错误代号:%d\n",GetLastError());
        system("pause");  //防止cmd一闪而过
        return 0;
    }

    printf("读取阳光值:%d\n",dwSunshineValue);

    int modifyCS;  
    printf("输入你要修改后的值：");  
    scanf("%d", &modifyCS);  
	//更改值
    WriteProcessMemory(hProcess, (LPVOID)(dwSunshineOffsetFirstValue+dwSunshineOffsetSecond), &modifyCS, sizeof(DWORD), &dwSize);  
      
    CloseHandle(hProcess);  //关闭进程
    

    system("pause");  //防止cmd一闪而过
    return 0;
}