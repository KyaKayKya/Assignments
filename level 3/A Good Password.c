#include<stdio.h>
#include<string.h>
//////////////////////////////////////////////////
 /*Function Prototype*/
int Password_Judge(char* Password); // �ж�����û� 
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
	int Result = 1; // 1����Good 2����Bad 
	int Str_Len = 0;
	int Flag = 1; // FlagΪ1�ż����ж� 
	int i = 0;
	int Uppercase_Flag = 0; // ��д��ĸ���ڱ�־ 
	int lowercase_Flag = 0; // Сд��ĸ���ڱ�־ 
	int Number_Flag = 0; // ���ִ��ڱ�־ 
	
	Str_Len = strlen(Password);
	
	if(Str_Len < 8) // ��������Ϊ8 
	{
		Result = 0;
		Flag = 0;
	}
	
	for(i = 0;Flag==1 && i<Str_Len;i++)
	{
		if(Password[i] <= 'Z' && Password[i] >= 'A') // ������һ����д��ĸ 
		{
			Uppercase_Flag = 1;
		}else if(Password[i] <= 'z' && Password[i] >= 'a') // Сд��ĸ
		{
			lowercase_Flag = 1;
		}else if(Password[i] <= '9' && Password[i] >= '0') // ���� 
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
