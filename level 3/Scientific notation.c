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
	CharExponent[Count_Two] = '\0'; // 获得幂次 
	
	Int_Exponent = Atoi(CharExponent)*sign; // 将字符转换为整形 
	
	Count_Three = 0;
	while(Count_Three < strlen(Real_Number))
	{
		if(Real_Number[Count_Three] == '.')
		{
			Flag = 1; // 代表找到'.' 
			break;
		}else
		{
			Count_Three++;
		}
	} // 找到'.'的位置 
	
	// 若没有小数点 
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
	// 现在有小数点了 
	
		Target = Count_Three+Int_Exponent; // 变换后“. ”的位置
		 // 若幂次为负的 
		if(Int_Exponent < 0) 
		{
			if(Target < 1)
			{
				Target = 1; // 小数点前自动补零，所以最小为1 
				Count_Four =  Target+8+Int_Exponent; // 得到最后一个有效数字的位置
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
				// 前面填补0 
				for(;(Count_Four-Int_Exponent)>=0;Count_Four--)
				{
					Real_Number[Count_Four-Int_Exponent] = '0';
				}
				// 变换小数点位置 
				Count_Three -= Int_Exponent; // 让Count_Three为小数点位置 
				for(;(Count_Three-1)>=Target;Count_Three--)
				{
					Real_Number[Count_Three] = Real_Number[Count_Three-1];
					Real_Number[Count_Three-1] = '.';
				}
				// 不用处理小数点后的数据 
			}else if(Target >= 1)
			{
				int Register = Count_Three;
				// 变换小数点位置 
				for(;(Count_Three-1)>=Target;Count_Three--)
				{
					Real_Number[Count_Three] = Real_Number[Count_Three-1];
					Real_Number[Count_Three-1] = '.';
				}
				// 处理小数点后的数据
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
			
			Real_Number[Target+9] = '\0'; // 统一封装 
		}
		 // 若幂次为正的 
		else 
		{
			for(;Count_Three < Target;Count_Three++)
			{
			if(Real_Number[Count_Three+1] == '\0') // 小数点位置没有数时 
			{
				for(;Count_Three <= (Target+8);Count_Three++)
				{
					Real_Number[Count_Three] = '0';	
				}
				Real_Number[Target] = '.';
				Real_Number[Count_Three] = '\0';
				Flag = 2;
				break;
			}else if(Real_Number[Count_Three+1] != '\0') // 小数点位置有数时,将小数点换到该位置 
			{
				Real_Number[Count_Three] = Real_Number[Count_Three+1];
				Real_Number[Count_Three+1] = '.';
			}
			}
		
			if(Flag != 2) // 这说明小数点后面数据未处理 
			{
			// 此时 Count_Three 等于 Target
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
			Real_Number[Target+9] = '\0'; // 统一封装 
			}
		}
		
	printf("%s\n",Real_Number);
	return 0;
}
