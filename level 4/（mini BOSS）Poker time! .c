/*
˼·���������� 
1. ���A1 A2 A3 B1 B2 B3
2. ���A1_R A1_C��������С����������,��1��С��3��� 
3. ת��ΪInt_A1������HΪ400��SΪ300��DΪ200��CΪ100��Ȼ�����������10��Ϊ1��
4. ������������Ƚ�����ͬ
5. ��������˭���� 
*/
#include<stdio.h>
#include<string.h>
////////////////////////////////////////////////////
 /*Global Variables*/
char* card[4][13] = {
	{"C2","C3","C4","C5","C6","C7","C8","C9","C1","CJ","CQ","CK","CA"},
	{"D2","D3","D4","D5","D6","D7","D8","D9","D1","DJ","DQ","DK","DA"},
	{"S2","S3","S4","S5","S6","S7","S8","S9","S1","SJ","SQ","SK","SA"},
	{"H2","H3","H4","H5","H6","H7","H8","H9","H1","HJ","HQ","HK","HA"},
};
char* Output_card[4][13] = {
	{"C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK","CA"},
	{"D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK","DA"},
	{"S2","S3","S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK","SA"},
	{"H2","H3","H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK","HA"},
};
int Number[4][13] = {
	{102,103,104,105,106,107,108,109,110,111,112,113,114},
	{202,203,204,205,206,207,208,209,210,211,212,213,214},
	{302,303,304,305,306,307,308,309,310,311,312,313,314},
	{402,403,404,405,406,407,408,409,410,411,412,413,414},
};
int Flag = 1; // 1��ʾ�Ϸ���0��ʾ���Ϸ� 
int counter_one = 0; // �����������������ĳ��λ�� 
int A1_R,A1_C,A2_R,A2_C,A3_R,A3_C,B1_R,B1_C,B2_R,B2_C,B3_R,B3_C; // ��ά�������� 
///////////////////////////////////////////////////
 /*Private Function*/
void Card_Record(char *Card_Name_1,char *rxBuffer) // �ӻ��������뿨������ 
{
	char Char_Register;
	int counter_two = 0;
	while(1)
	{
		Char_Register = rxBuffer[counter_one];
		if(Char_Register == ' ') // �󵨼�������ֻ���һ���ո� 
		{
			Card_Name_1[counter_two] = '\0';
			counter_one++;
			break;
		}else if(Char_Register == '\0')
		{
			Card_Name_1[counter_two] = '\0';
			break;
		}else if(Char_Register=='C' || Char_Register=='D' || Char_Register=='S' || Char_Register=='H')
		{
			Card_Name_1[counter_two] = Char_Register;
			counter_two++;
		}else if(Char_Register=='1')
		{
			Card_Name_1[counter_two] = Char_Register;
			counter_two++;
			if(rxBuffer[counter_one+1] == '\0') // ��ͷ�� 
			{
				Card_Name_1[counter_two] = '\0';
				break;
			}else if(rxBuffer[counter_one+1] == '0') // 10��Ϊ1 
			{
				Card_Name_1[counter_two] = '\0';
				counter_one++;
			}else // ���Ϸ�
			{
				Flag = 0;
				break;
			}
		}else
		{
			Card_Name_1[counter_two] = Char_Register;
			counter_two++;	
		}
		counter_one++;
	}
}
int Judgement(char *Char_A1,char *Char_A2,char *Char_A3,char *Char_B1,char *Char_B2,char *Char_B3) // �Ϸ����ж�
{
	int Row,Column;
	int Flag_2 = 0; // ��������forѭ�� ,С��3����δ������н⣬������ 
	int test = 0; 
	 // ������A���� 
	for(Row = 0,Flag_2 = 0;Row<4 && Flag_2!=3;Row++)
	{
		for(Column = 0;Column<13 && Flag_2!=3;Column++)
		{
			if(strcmp(Char_A1,card[Row][Column]) && strcmp(Char_A2,card[Row][Column]) && strcmp(Char_A3,card[Row][Column])) // ��ͬʱ����0 
			{
				// Do nothing
			}else // ��ͬ 
			{
				if(Flag_2 == 0)
				{
					A1_R = Row;
					A1_C = Column;
					Flag_2 += 1;
				}else if(Flag_2 == 1)
				{
					A2_R = Row;
					A2_C = Column;
					Flag_2 += 1;
				}else if(Flag_2 == 2)
				{
					A3_R = Row;
					A3_C = Column;
					Flag_2 += 1;
				}
			}
		}
	}
	 // ���������򲻺Ϸ�
	if(Flag_2 != 3)
	{
		Flag = 0; // ���Ϸ�
		return 0; 
	}
	 // ������B���� 
	for(Row = 0,Flag_2 = 0;Row<4 && Flag_2!=3;Row++)
	{
		for(Column = 0;Column<13 && Flag_2!=3;Column++)
		{
			if(strcmp(Char_B1,card[Row][Column]) && strcmp(Char_B2,card[Row][Column]) && strcmp(Char_B3,card[Row][Column])) // ��ͬʱ����0 
			{
				// Do nothing
			}else // ��ͬ 
			{
				if(Flag_2 == 0)
				{
					B1_R = Row;
					B1_C = Column;
					Flag_2 += 1;
				}else if(Flag_2 == 1)
				{
					B2_R = Row;
					B2_C = Column;
					Flag_2 += 1;
				}else if(Flag_2 == 2)
				{
					B3_R = Row;
					B3_C = Column;
					Flag_2 += 1;
				}
			}
		}
	}
	 // ���������򲻺Ϸ�
	if(Flag_2 != 3)
	{
		Flag = 0; // ���Ϸ�
		return 0; 
	}
	 // �ж��Ƿ�һ�������������ͬ��
	if(A1_R==A2_R && A1_C==A2_C)
	{
		Flag = 0; // ���Ϸ�
		return 0; 
	}
	if(A1_R==A3_R && A1_C==A3_C)
	{
		Flag = 0; // ���Ϸ�
		return 0; 
	}
	if(A3_R==A2_R && A3_C==A2_C)
	{
		Flag = 0; // ���Ϸ�
		return 0; 
	}
	if(B1_R==B2_R && B1_C==B2_C)
	{
		Flag = 0; // ���Ϸ�
		return 0; 
	}
	if(B1_R==B3_R && B1_C==B3_C)
	{
		Flag = 0; // ���Ϸ�
		return 0; 
	}
	if(B3_R==B2_R && B3_C==B2_C)
	{
		Flag = 0; // ���Ϸ�
		return 0; 
	}
}
//////////////////////////////////////////////////	
 /*Main Function*/ 
int main()
{
//	char test[4] = "C2";
//	printf("%s\n",card[0][1]);
//	printf("%s\n",test);
//	if(strcmp(test,card[0][0]))
//	{
//		printf("not success\n");
//	}else
//	{
//		printf("success\n");
//	}
	char rxBuffer_A[50],rxBuffer_B[50]; // A��B������ 
	char Char_A1[3],Char_A2[3],Char_A3[3],Char_B1[3],Char_B2[3],Char_B3[3]; // �������
	char Winner; // Ӯ������ 
	 // ʵ�ֿ��ƶ�ȡ��洢
	gets(rxBuffer_A);
	gets(rxBuffer_B);
	Card_Record(Char_A1,rxBuffer_A);
	Card_Record(Char_A2,rxBuffer_A);
	Card_Record(Char_A3,rxBuffer_A);
	counter_one = 0;
	Card_Record(Char_B1,rxBuffer_B);
	Card_Record(Char_B2,rxBuffer_B);
	Card_Record(Char_B3,rxBuffer_B); 
	if(Flag == 0)
	{
		printf("Input Error!\n");
		return 0;
	}
//	printf("Char_A1 = %s\tChar_A2 = %s\tChar_A3 = %s\n",Char_A1,Char_A2,Char_A3);
//	printf("Char_B1 = %s\tChar_B2 = %s\tChar_B3 = %s\n",Char_B1,Char_B2,Char_B3);
	 // ʵ�ֿ������궨λ���Լ��Ϸ����ж� ��A1��С��A3��� 
	Judgement(Char_A1,Char_A2,Char_A3,Char_B1,Char_B2,Char_B3);
	if(Flag == 0)
	{
		printf("Input Error!\n");
		return 0;
	}
//	printf("A1_R = %d\tA1_C = %d\nA2_R = %d\tA2_C = %d\nA3_R = %d\tA3_C = %d\n",A1_R,A1_C,A2_R,A2_C,A3_R,A3_C);
	 // ʵ��ʤ���ж�
	if(A3_R==B3_R && A3_C==B3_C) // ��������ͬ 
	{
		if(A2_R==B2_R && A2_C==B2_C) // �ڶ��������ͬ 
		{
			if(A1_R==B1_R && A1_C==B1_C) // ��С������ͬ 
			{
				Winner = 'X'; 
			}else  // ��С���Ʋ���ͬ 
			{
				if(Number[A1_R][A1_C] > Number[B1_R][B1_C]) // A���� 
				{
					Winner = 'A';
				}else if(Number[A1_R][A1_C] < Number[B1_R][B1_C]) // B���� 
				{
					Winner = 'B';
				}
			}
		}else  // �ڶ�����Ʋ���ͬ 
		{
			if(Number[A2_R][A2_C] > Number[B2_R][B2_C]) // A���� 
			{
				Winner = 'A';
			}else if(Number[A2_R][A2_C] < Number[B2_R][B2_C]) // B���� 
			{
				Winner = 'B';
			}
		}
	}else // �����Ʋ���ͬ 
	{
		if(Number[A3_R][A3_C] > Number[B3_R][B3_C]) // A���� 
		{
			Winner = 'A';
		}else if(Number[A3_R][A3_C] < Number[B3_R][B3_C]) // B���� 
		{
			Winner = 'B';
		}
	}
//Winner is X!
//A: SA SK SJ
//B: SA SK SJ
	 // ʵ�ֽ�����
	printf("Winner is %c!\n",Winner);
	printf("A: %s %s %s\n",Output_card[A3_R][A3_C],Output_card[A2_R][A2_C],Output_card[A1_R][A1_C]);
	printf("B: %s %s %s\n",Output_card[B3_R][B3_C],Output_card[B2_R][B2_C],Output_card[B1_R][B1_C]);
	return 0;	
}
 
