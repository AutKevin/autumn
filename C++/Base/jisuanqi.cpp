#include "stdafx.h"

int main(int argc, char* argv[])
{
	int num1,num2,result;
	char operater;
	scanf("%d %c %d",&num1,&operater,&num2);
	if(operater=='+'||operater=='-'||operater=='*'||operater=='/'||operater=='%')
	{
		if(operater=='+') result=num1+num2;
		if(operater=='-') result=num1-num2;
		if(operater=='*') result=num1*num2;
		if(operater=='/')
		{
			if(num2!=0)
			result=num1/num2;
		}
		if(operater=='%'){
			if(num2!=0)
			result=num1%num2;
		}
		printf("%d %c %d",num1,operater,num2);
		printf(" = %d",result);
	}
	else {
		printf("只支持+-*/%操作");
	}
	return 0;
}