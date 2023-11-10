#include<stdio.h>
#include<string.h>
//////////////////////////////////////////////////
 /*Function Prototype*/
int Password_Judge(char* Password); // 判断密码好坏 
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	char Password[50];
	int Good_Password = 1;
	
	gets(Password); // Get Password
	
	Good_Password = Password_Judge(Password);

	if(Good_Password)
	{
		printf("Good password!\n");
	}else
	{
		printf("Bad password!\n");
	}

	return 0;
}

//////////////////////////////////////////////////
 /*Password Judgement*/ 
int Password_Judge(char* Password)
{
	int Result = 1; // 1代表Good 2代表Bad 
	int Str_Len = 0;
	int Flag = 1; // Flag为1才继续判断 
	int i = 0;
	int Uppercase_Flag = 0; // 大写字母存在标志 
	int lowercase_Flag = 0; // 小写字母存在标志 
	int Number_Flag = 0; // 数字存在标志 
	
	Str_Len = strlen(Password);
	
	if(Str_Len < 8) // 长度至少为8 
	{
		Result = 0;
		Flag = 0;
	}
	
	for(i = 0;Flag==1 && i<Str_Len;i++)
	{
		if(Password[i] <= 'Z' && Password[i] >= 'A') // 至少有一个大写字母 
		{
			Uppercase_Flag = 1;
		}else if(Password[i] <= 'z' && Password[i] >= 'a') // 小写字母
		{
			lowercase_Flag = 1;
		}else if(Password[i] <= '9' && Password[i] >= '0') // 数字 
		{
			Number_Flag = 1;
		}
	}
	
	if(Uppercase_Flag==0 || lowercase_Flag==0 || Number_Flag==0)
	{
		Result = 0;
		Flag = 0;
	}
	
	return Result;
}
