// File.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>  
#include<fstream>
#include<iomanip>
using namespace std;

//д���ļ�
void write(){
	//������
    ofstream ofile;                
	//����
    ofile.open("f:\\C\\out.txt"); 
    //������
    ofile<<setw(6)<<"�����"<<endl;   
    ofile<<setw(6)<<"   Ҫ�úû���ȥ"<<endl;
    //�ر���
    ofile.close();                //�ر��ļ�
}

//��ȡ�ļ�
void read(){
   char buffer[256];  
   ifstream in("f:\\C\\out.txt");   //������
   if (! in.is_open())  //�ж��Ƿ��
   { 
	   cout << "Error opening file"; exit (1);   //û�д��򱨴�
   }  
   while (!in.eof() )   //�Ƿ񵽴��ļ�ĩβ,��û����,������ȡ
   {  
       in.getline (buffer,100);  //��ȡ�ַ�����buffer
       cout << buffer << endl;  //���
   }  
   in.close();
   //return 0; 
}
int main(){
    write();
	//read();
    return 0;
}
