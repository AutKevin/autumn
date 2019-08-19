// File.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>  
#include<fstream>
#include<iomanip>
using namespace std;

//写入文件
void write(){
	//定义流
    ofstream ofile;                
	//打开流
    ofile.open("f:\\C\\out.txt"); 
    //操作流
    ofile<<setw(6)<<"起风了"<<endl;   
    ofile<<setw(6)<<"   要好好活下去"<<endl;
    //关闭流
    ofile.close();                //关闭文件
}

//读取文件
void read(){
   char buffer[256];  
   ifstream in("f:\\C\\out.txt");   //定义流
   if (! in.is_open())  //判断是否打开
   { 
	   cout << "Error opening file"; exit (1);   //没有打开则报错
   }  
   while (!in.eof() )   //是否到达文件末尾,若没到达,继续读取
   {  
       in.getline (buffer,100);  //读取字符存入buffer
       cout << buffer << endl;  //输出
   }  
   in.close();
   //return 0; 
}
int main(){
    write();
	//read();
    return 0;
}
