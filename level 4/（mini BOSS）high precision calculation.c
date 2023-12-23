/*
����˼·��
1. �ַ������룬�����������ַ�����ͷ���

2. ת��Ϊ�������飬˳�㷴�ã���λΪ0��Ԫ�أ� 

3. +=��������λ/10��üӵ���һλ��Ȼ��%10��ø�λ��Ϊ��һλ

4. �Ӻ���ǰ��λ��һ����Ϊ0��λ�ã����������0��Ԫ��

5. ���ǵ���Ϊ0�������������� 
*/
#include<stdio.h>
#include<string.h>
////////////////////////////////////////////////////
 /*Global Variables*/
#define MaxLen 600
///////////////////////////////////////////////////
 /*Private Function*/
 // ת��Ϊ�������飬������
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
 // �߾��ȼӷ� 
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
 // �߾��ȼ���
void High_Precision_Minus(int *Int_Num_1,int *Int_Num_2,int *Int_Answer,int Length)
{
	int i;
	for(i = 0;i <= Length-1;i++)
	{
		Int_Answer[i] += Int_Num_1[i]-Int_Num_2[i];
		if(Int_Answer[i] < 0) // �����λ
		{
			Int_Answer[i] += 10;
			Int_Answer[i+1]--;
		}
	}
}
 // ������
void Output(int *Int_Answer,int Length)
{
	int i = Length-1;
	while(i >= 0)
	{
		printf("%d",Int_Answer[i--]);
	}
	if(Length == 0) // ���Ϊ0 
	{
		printf("0");
	}
	printf("\n");
}
 // �ж�answer������ 
char Sign_Judgement(int digit,char *Char_Num_1,char *Char_Num_2)
{
	char sign;
	int Length_1 = strlen(Char_Num_1);
	int Length_2 = strlen(Char_Num_2);
	if(Length_1 == Length_2) // λ����ͬ 
	{
		if(Char_Num_1[digit] == Char_Num_2[digit])
		{
			if(digit == Length_1-1) // ������ȫ��ͬ 
			{
				sign = '0';
			}else
			{
				sign = Sign_Judgement(digit+1,Char_Num_1,Char_Num_2); // �ݹ��÷��� 
			}
		}else
		{
			if(Char_Num_1[digit]-'0' > Char_Num_2[digit]-'0') // 1��������
			{
				sign = '+';
			}else if(Char_Num_1[digit]-'0' < Char_Num_2[digit]-'0') // 2�������� 
			{
				sign = '-';
			}
		}
	}else if(Length_1 > Length_2) // 1�������� 
	{
		sign = '+';
	}else if(Length_1 < Length_2) // 2�������� 
	{
		sign = '-';
	}
	return sign;
}
//////////////////////////////////////////////////	
 /*Main Function*/ 
int main()
{
	int Repeat_Time; // �ظ�������� 
	int counter; // ��¼������� 
	scanf("%d",&Repeat_Time);
	
	for(counter = 0;counter < Repeat_Time;counter++)
	{
		char rxBuffer[2*MaxLen+2]; // ���ջ����� 
		char Char_Num_1[MaxLen],Char_Num_2[MaxLen];
		int Int_Num_1[MaxLen],Int_Num_2[MaxLen],Int_Answer[MaxLen];
		int i,j;
		char Register;
		char Sign_Register;
		 // ��ʼ������(ȫΪ0) 
		memset(Int_Num_1,0,sizeof(Int_Num_1));
		memset(Int_Num_2,0,sizeof(Int_Num_2));
		memset(Int_Answer,0,sizeof(Int_Answer));
		if(counter == 0)
		{
			getchar(); //���������'\n'	
		}
		gets(rxBuffer);
//		printf("%s",rxBuffer);
		 // ���ַ���ʽ��ȡ��һ���� 
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
		
		Sign_Register = Register; // ��¼�Ӽ��� 
		 // ���ַ���ʽ��ȡ�ڶ����� 
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
			int Length = strlen(Char_Num_1)>=strlen(Char_Num_2) ? strlen(Char_Num_1):strlen(Char_Num_2); // ȡ��󳤶�
			High_Precision_Add(Int_Num_1,Int_Num_2,Int_Answer,Length); // �߾��ȼӷ�
			while(Int_Answer[Length]==0 && Length>=0) // ʹLengthΪ��һ����Ϊ���λ�� 
			{
				Length--;
			}
			Length++; // ʹLengthΪ���鳤�� 
			 // ������ 
			Output(Int_Answer,Length);
		}else if(Sign_Register == '-')
		{
			int digit = 0;
			char sign = Sign_Judgement(digit,Char_Num_1,Char_Num_2); // ��ý�������� 
			if(sign == '+') // ��һ�������� 
			{
				int Length = strlen(Char_Num_1)>=strlen(Char_Num_2) ? strlen(Char_Num_1):strlen(Char_Num_2); // ȡ��󳤶�
				High_Precision_Minus(Int_Num_1,Int_Num_2,Int_Answer,Length);
				while(Int_Answer[Length]==0) // ʹLengthΪ��һ����Ϊ���λ�� 
				{
					Length--;
				}
				Length++; // ʹLengthΪ���鳤��
				Output(Int_Answer,Length);
			}else if(sign == '-') // �ڶ��������� 
			{
				int Length = strlen(Char_Num_1)>=strlen(Char_Num_2) ? strlen(Char_Num_1):strlen(Char_Num_2); // ȡ��󳤶�
				High_Precision_Minus(Int_Num_2,Int_Num_1,Int_Answer,Length);
				while(Int_Answer[Length]==0) // ʹLengthΪ��һ����Ϊ���λ�� 
				{
					Length--;
				}
				Length++; // ʹLengthΪ���鳤��
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

