#include<stdio.h>
#include<string.h>
//////////////////////////////////////////////////
 /*Private Define*/
#define Minus -1
#define Plus 1
//////////////////////////////////////////////////
 /*Function Prototypes*/
 // �������ת10���� 
int Atoi(char *CharNumber,int Number_System)
{
	int StringLen;
	int Power = 1;
	int Counter = 0;
	int Sum = 0;
	int MaxNumber = 1; // �������һΪ��С������ 
	
	StringLen = strlen(CharNumber);
	
	for(Counter = (StringLen-1);Counter >= 0;Counter--)
	{
		int number;
		if(CharNumber[Counter]>='0' && CharNumber[Counter]<='9')
		{
			number = (CharNumber[Counter]-'0');
		}else if(CharNumber[Counter]>='A' && CharNumber[Counter]<='Z')
		{
			number = Transform(&CharNumber[Counter]);
		}
		Sum += (number*Power);
		Power *= Number_System;
	}
	return Sum;
}
 // ��A~ZתΪ10~35 
int Transform(char *CharNumber)
{
	int number;
	
	number = (*CharNumber-'A')+10;
	
	return number;
}
 // ��ʼ����С������
int Number_System_Init(char *CharNumber)
{
	int Number_System = 2;
	int StringLen;
	int Counter = 0;
	int MaxNumber = 1; // �������һΪ��С������ 
	
	StringLen = strlen(CharNumber);
	
	for(Counter = (StringLen-1);Counter >= 0;Counter--)
	{
		int number;
		if(CharNumber[Counter]>='0' && CharNumber[Counter]<='9')
		{
			number = (CharNumber[Counter]-'0');
		}else if(CharNumber[Counter]>='A' && CharNumber[Counter]<='Z')
		{
			number = Transform(&CharNumber[Counter]);
		}
		if(number > MaxNumber)
		{
			MaxNumber = number;
		}
	}
	Number_System = MaxNumber+1; // ��С������ 
	return Number_System;
} 
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	char Char_Number_1[100];
	char Char_Number_2[100];
	int Flag = 1;
	int sign_1 = Plus;
	int sign_2 = Plus;
	int Int_Number_1;
	int Int_Number_2;
	int Number_System_1 = 2;
	int Number_System_2 = 2;
	int Count_One,Count_Two;
	
	scanf("%s",Char_Number_1);
	gets(Char_Number_2);
	// �����ַ�������ȡ�����ԡ�ȥ���ո�
	Count_Two = 0;
	for(Count_One = 0;Count_One<strlen(Char_Number_1);Count_One++)
	{
		if(Char_Number_1[Count_One]>='0' && Char_Number_1[Count_One]<='9')
		{
			Char_Number_1[Count_Two] = Char_Number_1[Count_One];
			Count_Two++;
		}else if(Char_Number_1[Count_One]>='A' && Char_Number_1[Count_One]<='Z')
		{
			Char_Number_1[Count_Two] = Char_Number_1[Count_One];
			Count_Two++;
		}else if(Char_Number_1[Count_One] == '-')
		{
			sign_1 = Minus;
		}
	}
	Char_Number_1[Count_Two] = '\0'; 
	
	Count_Two = 0;
	for(Count_One = 0;Count_One<strlen(Char_Number_2);Count_One++)
	{
		if(Char_Number_2[Count_One]>='0' && Char_Number_2[Count_One]<='9')
		{
			Char_Number_2[Count_Two] = Char_Number_2[Count_One];
			Count_Two++;
		}else if(Char_Number_2[Count_One]>='A' && Char_Number_2[Count_One]<='Z')
		{
			Char_Number_2[Count_Two] = Char_Number_2[Count_One];
			Count_Two++;
		}else if(Char_Number_2[Count_One] == '-')
		{
			sign_2 = Minus;
		}
	}
	Char_Number_2[Count_Two] = '\0';
//	Int_Number_1 = sign_1*Atoi(Char_Number_1,36);
//	Int_Number_2 = sign_2*Atoi(Char_Number_2,36);
//	printf("%d\n%d",Int_Number_1,Int_Number_2);

	// ��ȡ��С������ 
	Number_System_1 = Number_System_Init(Char_Number_1);
	Number_System_2 = Number_System_Init(Char_Number_2);
	int Register = Number_System_2;
	// �������н��������бȽ� 
	for(;Number_System_1<=36 && Flag==1;Number_System_1++)
	{
		Number_System_2 = Register;
		Int_Number_1 = sign_1*Atoi(Char_Number_1,Number_System_1);
		for(;Number_System_2<=36 && Flag==1;Number_System_2++)
		{
			Int_Number_2 = sign_2*Atoi(Char_Number_2,Number_System_2);
			if(Int_Number_1 == Int_Number_2)
			{
				Flag = 0; // ����ɹ��ҵ��� 
				break;
			}
		}
		if(Flag == 0)
		{
			break;
		}
	}
	// ������ 
	if(Flag == 0) // �ɹ� 
	{
		if(sign_1 == Minus)
		{
			printf("-%s (base %d) = ",Char_Number_1,Number_System_1);
			if(sign_2 == Minus)
			{
				printf("-%s (base %d)\n",Char_Number_2,Number_System_2);
			}else if(sign_2 == Plus)
			{
				printf("%s (base %d)\n",Char_Number_2,Number_System_2);
			}
		}else if(sign_1 == Plus)
		{
			printf("%s (base %d) = ",Char_Number_1,Number_System_1);
			if(sign_2 == Minus)
			{
				printf("-%s (base %d)\n",Char_Number_2,Number_System_2);
			}else if(sign_2 == Plus)
			{
				printf("%s (base %d)\n",Char_Number_2,Number_System_2);
			}
		}
	}else if(Flag == 1) // ʧ��
	{
		if(sign_1 == Minus)
		{
			printf("-%s is not equal to ",Char_Number_1);
			if(sign_2 == Minus)
			{
				printf("-%s in any base 2..36\n",Char_Number_2);
			}else if(sign_2 == Plus)
			{
				printf("%s in any base 2..36\n",Char_Number_2);
			}
		}else if(sign_1 == Plus)
		{
			printf("%s is not equal to ",Char_Number_1);
			if(sign_2 == Minus)
			{
				printf("-%s in any base 2..36\n",Char_Number_2);
			}else if(sign_2 == Plus)
			{
				printf("%s in any base 2..36\n",Char_Number_2);
			}
		}
	} 	
	return 0;
}
