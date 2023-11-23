#include<stdio.h>
#include<string.h>
//////////////////////////////////////////////////
 /*Private Define*/
#define Minus -1
#define Plus 1
//////////////////////////////////////////////////
 /*Function Prototype*/
int Atoi(char *CharExponent)
{
	int StringLen;
	int Power = 1;
	int Counter = 0;
	int Sum = 0;
	
	StringLen = strlen(CharExponent);
	
	for(Counter = (StringLen-1);Counter >= 0;Counter--)
	{
		int number = (CharExponent[Counter]-'0');
		Sum += (number*Power);
		Power *= 10;
	}
	
	return Sum;
}

//////////////////////////////////////////////////
 /*Main*/
int main()
{
	char Real_Number[100];
	char CharExponent[100];
	int Int_Exponent;
	int sign = Plus;
	int Count_One,Count_Two,Count_Three,Count_Four,Count_Five;
	int Flag = 0;
	int Target;
	
	scanf("%s",Real_Number);
	gets(CharExponent);
	
	Count_Two = 0;
	for(Count_One = 0;CharExponent[Count_One] != '\0';Count_One++)
	{
		if(CharExponent[Count_One] == '-')
		{
			sign = Minus;
		}else if(CharExponent[Count_One] >= '0' && CharExponent[Count_One] <= '9')
		{
			CharExponent[Count_Two] = CharExponent[Count_One];
			Count_Two++;
		}
	}
	CharExponent[Count_Two] = '\0'; // ����ݴ� 
	
	Int_Exponent = Atoi(CharExponent)*sign; // ���ַ�ת��Ϊ���� 
	
	Count_Three = 0;
	while(Count_Three < strlen(Real_Number))
	{
		if(Real_Number[Count_Three] == '.')
		{
			Flag = 1; // �����ҵ�'.' 
			break;
		}else
		{
			Count_Three++;
		}
	} // �ҵ�'.'��λ�� 
	
	// ��û��С���� 
	if(Flag == 0)
	{
		int i = 0;
		int Register = Count_Three;
		Real_Number[Count_Three] = '.';
		for(i = 1;i<=8;i++)
		{
			Real_Number[++Count_Three] = '0';
		}
		Real_Number[++Count_Three] = '\0'; 
		
		Count_Three = Register;
	}
	// ������С������ 
	
		Target = Count_Three+Int_Exponent; // �任��. ����λ��
		 // ���ݴ�Ϊ���� 
		if(Int_Exponent < 0) 
		{
			if(Target < 1)
			{
				Target = 1; // С����ǰ�Զ����㣬������СΪ1 
				Count_Four =  Target+8+Int_Exponent; // �õ����һ����Ч���ֵ�λ��
				for(;Count_Four>=0;Count_Four--)
				{
					if(Real_Number[Count_Four] == '\0')
					{
						Real_Number[Count_Four-Int_Exponent] = '0';
					}else if(Real_Number[Count_Four] != '\0')
					{
						Real_Number[Count_Four-Int_Exponent] = Real_Number[Count_Four];
					}
				}
				// ǰ���0 
				for(;(Count_Four-Int_Exponent)>=0;Count_Four--)
				{
					Real_Number[Count_Four-Int_Exponent] = '0';
				}
				// �任С����λ�� 
				Count_Three -= Int_Exponent; // ��Count_ThreeΪС����λ�� 
				for(;(Count_Three-1)>=Target;Count_Three--)
				{
					Real_Number[Count_Three] = Real_Number[Count_Three-1];
					Real_Number[Count_Three-1] = '.';
				}
				// ���ô���С���������� 
			}else if(Target >= 1)
			{
				int Register = Count_Three;
				// �任С����λ�� 
				for(;(Count_Three-1)>=Target;Count_Three--)
				{
					Real_Number[Count_Three] = Real_Number[Count_Three-1];
					Real_Number[Count_Three-1] = '.';
				}
				// ����С����������
				Count_Three = Register;
				for(Count_Three++;Count_Three <= Target+8;Count_Three++)
				{
					if(Real_Number[Count_Three] == '\0')
					{
						for(;Count_Three <= Target+8;Count_Three++)
						{
							Real_Number[Count_Three] = '0';
						}
					}
				}
			}
			
			Real_Number[Target+9] = '\0'; // ͳһ��װ 
		}
		 // ���ݴ�Ϊ���� 
		else 
		{
			for(;Count_Three < Target;Count_Three++)
			{
			if(Real_Number[Count_Three+1] == '\0') // С����λ��û����ʱ 
			{
				for(;Count_Three <= (Target+8);Count_Three++)
				{
					Real_Number[Count_Three] = '0';	
				}
				Real_Number[Target] = '.';
				Real_Number[Count_Three] = '\0';
				Flag = 2;
				break;
			}else if(Real_Number[Count_Three+1] != '\0') // С����λ������ʱ,��С���㻻����λ�� 
			{
				Real_Number[Count_Three] = Real_Number[Count_Three+1];
				Real_Number[Count_Three+1] = '.';
			}
			}
		
			if(Flag != 2) // ��˵��С�����������δ���� 
			{
			// ��ʱ Count_Three ���� Target
			for(Count_Three++;Count_Three <= Target+8;Count_Three++)
			{
				if(Real_Number[Count_Three] == '\0')
				{
					for(;Count_Three <= Target+8;Count_Three++)
					{
						Real_Number[Count_Three] = '0';
					}
				}
			}
			Real_Number[Target+9] = '\0'; // ͳһ��װ 
			}
		}
		
	printf("%s\n",Real_Number);
	return 0;
}
