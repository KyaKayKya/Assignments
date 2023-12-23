/*
解题思路：
1. 字符串读入，处理获得两个字符数组和符号

2. 转化为整型数组，顺便反置（个位为0号元素） 

3. +=起来，进位/10获得加到下一位，然后%10获得个位作为这一位

4. 从后往前定位第一个不为0的位置，依次输出到0号元素

5. 考虑到答案为0的情况，单独输出 
*/
#include<stdio.h>
#include<string.h>
////////////////////////////////////////////////////
 /*Global Variables*/
#define MaxLen 600
///////////////////////////////////////////////////
 /*Private Function*/
 // 转化为整型数组，并反置
void Reverse(char *Char_Num,int *Int_Num)
{
	int Length = strlen(Char_Num);
	int i = Length-1;
	int j;
	for(j = 0;i >= 0;i--)
	{
		Int_Num[j++] = Char_Num[i]-'0';
	}
}
 // 高精度加法 
void High_Precision_Add(int *Int_Num_1,int *Int_Num_2,int *Int_Answer,int Length)
{
	int i;
	for(i = 0;i <= Length-1;i++)
	{
		Int_Answer[i] += Int_Num_1[i]+Int_Num_2[i];
		Int_Answer[i+1] = Int_Answer[i]/10;
		Int_Answer[i] %= 10;
	}
}
 // 高精度减法
void High_Precision_Minus(int *Int_Num_1,int *Int_Num_2,int *Int_Answer,int Length)
{
	int i;
	for(i = 0;i <= Length-1;i++)
	{
		Int_Answer[i] += Int_Num_1[i]-Int_Num_2[i];
		if(Int_Answer[i] < 0) // 处理借位
		{
			Int_Answer[i] += 10;
			Int_Answer[i+1]--;
		}
	}
}
 // 输出结果
void Output(int *Int_Answer,int Length)
{
	int i = Length-1;
	while(i >= 0)
	{
		printf("%d",Int_Answer[i--]);
	}
	if(Length == 0) // 结果为0 
	{
		printf("0");
	}
	printf("\n");
}
 // 判断answer正负号 
char Sign_Judgement(int digit,char *Char_Num_1,char *Char_Num_2)
{
	char sign;
	int Length_1 = strlen(Char_Num_1);
	int Length_2 = strlen(Char_Num_2);
	if(Length_1 == Length_2) // 位数相同 
	{
		if(Char_Num_1[digit] == Char_Num_2[digit])
		{
			if(digit == Length_1-1) // 两数完全相同 
			{
				sign = '0';
			}else
			{
				sign = Sign_Judgement(digit+1,Char_Num_1,Char_Num_2); // 递归获得符号 
			}
		}else
		{
			if(Char_Num_1[digit]-'0' > Char_Num_2[digit]-'0') // 1号数更大
			{
				sign = '+';
			}else if(Char_Num_1[digit]-'0' < Char_Num_2[digit]-'0') // 2号数更大 
			{
				sign = '-';
			}
		}
	}else if(Length_1 > Length_2) // 1号数更大 
	{
		sign = '+';
	}else if(Length_1 < Length_2) // 2号数更大 
	{
		sign = '-';
	}
	return sign;
}
//////////////////////////////////////////////////	
 /*Main Function*/ 
int main()
{
	int Repeat_Time; // 重复计算次数 
	int counter; // 记录计算次数 
	scanf("%d",&Repeat_Time);
	
	for(counter = 0;counter < Repeat_Time;counter++)
	{
		char rxBuffer[2*MaxLen+2]; // 接收缓冲区 
		char Char_Num_1[MaxLen],Char_Num_2[MaxLen];
		int Int_Num_1[MaxLen],Int_Num_2[MaxLen],Int_Answer[MaxLen];
		int i,j;
		char Register;
		char Sign_Register;
		 // 初始化数组(全为0) 
		memset(Int_Num_1,0,sizeof(Int_Num_1));
		memset(Int_Num_2,0,sizeof(Int_Num_2));
		memset(Int_Answer,0,sizeof(Int_Answer));
		if(counter == 0)
		{
			getchar(); //清除缓冲区'\n'	
		}
		gets(rxBuffer);
//		printf("%s",rxBuffer);
		 // 以字符形式提取第一个数 
		i = 0;
		j = 0;
		Register = rxBuffer[i++];
		while(Register!='+' && Register!='-')
		{
			Char_Num_1[j++] = Register;
			Register = rxBuffer[i++];
		}
		Char_Num_1[j] = '\0';
		Reverse(Char_Num_1,Int_Num_1);
		
		Sign_Register = Register; // 记录加减号 
		 // 以字符形式提取第二个数 
		j = 0;
		Register = rxBuffer[i++];
		while(Register != '\0')
		{
			Char_Num_2[j++] = Register;
			Register = rxBuffer[i++];
		}
		Char_Num_2[j] = '\0';
		Reverse(Char_Num_2,Int_Num_2);
//		printf("%s %c %s\n",Char_Num_1,Sign_Register,Char_Num_2);
		
		if(Sign_Register == '+')
		{
			int Length = strlen(Char_Num_1)>=strlen(Char_Num_2) ? strlen(Char_Num_1):strlen(Char_Num_2); // 取最大长度
			High_Precision_Add(Int_Num_1,Int_Num_2,Int_Answer,Length); // 高精度加法
			while(Int_Answer[Length]==0 && Length>=0) // 使Length为第一个不为零的位置 
			{
				Length--;
			}
			Length++; // 使Length为数组长度 
			 // 输出结果 
			Output(Int_Answer,Length);
		}else if(Sign_Register == '-')
		{
			int digit = 0;
			char sign = Sign_Judgement(digit,Char_Num_1,Char_Num_2); // 获得结果正负性 
			if(sign == '+') // 第一个数更大 
			{
				int Length = strlen(Char_Num_1)>=strlen(Char_Num_2) ? strlen(Char_Num_1):strlen(Char_Num_2); // 取最大长度
				High_Precision_Minus(Int_Num_1,Int_Num_2,Int_Answer,Length);
				while(Int_Answer[Length]==0) // 使Length为第一个不为零的位置 
				{
					Length--;
				}
				Length++; // 使Length为数组长度
				Output(Int_Answer,Length);
			}else if(sign == '-') // 第二个数更大 
			{
				int Length = strlen(Char_Num_1)>=strlen(Char_Num_2) ? strlen(Char_Num_1):strlen(Char_Num_2); // 取最大长度
				High_Precision_Minus(Int_Num_2,Int_Num_1,Int_Answer,Length);
				while(Int_Answer[Length]==0) // 使Length为第一个不为零的位置 
				{
					Length--;
				}
				Length++; // 使Length为数组长度
				printf("-");
				Output(Int_Answer,Length);
			}else if(sign == '0')
			{
				printf("0\n");
			}
		}
	}
	return 0;
}

