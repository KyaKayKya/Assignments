#include<stdio.h>
#include<string.h>
////////////////////////////////////////////////////
 /*Define*/
#define Len 50
////////////////////////////////////////////////////
 /*Global Variables*/
char *card[4][13] = {
	{"C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK","CA"},
	{"D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK","DA"},
	{"S2","S3","S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK","SA"},
	{"H2","H3","H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK","HA"},
};
int Number[13] = {2,3,4,5,6,7,8,9,10,10,10,10,0};
int i = 0; // �����ҵ��˼��źϷ���
int rx_counter = 0; // ���ڼ�¼���ڱ�������������ĳ��λ��  
///////////////////////////////////////////////////
 /*Private Function*/
 // �����ַ�����ÿ�����Ϣ���������ַ���������������ַ��������� 
int String_Process(char *A_RxBuffer,int A_Card[][13],int Total_Card[][13])
{
 	int Invalid_Input = 0; // 1������������Ч
 	char Char_Register;
 	int Flag = 1; // whileѭ����������1Ϊ���У�0Ϊ��ֹ
 	int counter = 0;
	while(A_RxBuffer[counter]!='\0' && Flag==1)
	{
		int Row,Column; // �С����� 
		int Continue_Flag = 0;
		Char_Register = A_RxBuffer[counter++];
		if(Char_Register!=' ')
		{
			switch(Char_Register) // �жϻ�ɫ
			{
				case 'H':Row = 3;break;
				case 'S':Row = 2;break;
				case 'D':Row = 1;break;
				case 'C':Row = 0;break;
				default: // ��Ϊ���֡�JQKA����ֱ��continue��ʣ�µ����Ϊ�Ƿ����� 
					if(Char_Register>='0'&&Char_Register<='9')
					{
						Continue_Flag = 1;
					}else if(Char_Register=='J'||Char_Register=='Q'||Char_Register=='K'||Char_Register=='A')
					{
						Continue_Flag = 1;
					}else
					{
						Invalid_Input = 1; // �Ƿ����� 
					}
					break;
			}
			if(Continue_Flag == 1)
			{
						continue;
			}
			if(Invalid_Input == 1)
			{
				return 0; 
			}
			
			switch(A_RxBuffer[counter]) // �жϴ�С(ֻ��ǰһλ�ǺϷ���ɫ�ſɽ�����ж�)
			{
				case 'A':Column = 12;break;
				case 'K':Column = 11;break;
				case 'Q':Column = 10;break;
				case 'J':Column = 9;break;
				case '1':
					if(A_RxBuffer[counter+1]=='0')
					{
						if(A_RxBuffer[counter+2]==' ' || A_RxBuffer[counter+2]=='\0')
						{
							Column = 8;
						}else
						{
							Invalid_Input = 1; // �Ƿ�����
						}
					}else
					{
						Invalid_Input = 1; // �Ƿ�����
					}
					break;
				case '9':Column = 7;break;
				case '8':Column = 6;break;
				case '7':Column = 5;break;
				case '6':Column = 4;break;
				case '5':Column = 3;break;
				case '4':Column = 2;break;
				case '3':Column = 1;break;
				case '2':Column = 0;break;
				default :Invalid_Input = 1;break;
			}
			if(Invalid_Input == 1)
			{
				return 0;  
			}
			if(A_Card[Row][Column]==0 && Total_Card[Row][Column]==0)
			{
				A_Card[Row][Column] += 1; // ���Aӵ�д��� 
				Total_Card[Row][Column] += 1; // ��Ǵ����ѱ���� 
				i++; // ����һ���Ϸ��� 
			}else
			{
				Invalid_Input = 1; // �ų����Ƹ�������
			}
		}else if(Char_Register == ' ')
		{
			continue;
		}
	}
	return 0;
}
 // �����ж��������� 
int Judgement_One(int A_Card[][13],int Column_Num[3],int Row_Num[3])
{
	int Row_Counter,Column_Counter;
	int Number = 0;
	int retrn = 0;
	for(Column_Counter = 12;Column_Counter >= 0;Column_Counter--)
	{
		for(Row_Counter = 3;Row_Counter >= 0;Row_Counter--)
		{
			if(A_Card[Row_Counter][Column_Counter]==1 && Number<=2) // �ж������ơ���ֹ����Խ�� 
			{
				Row_Num[Number] = Row_Counter; // ��¼����		
				Column_Num[Number] = Column_Counter; // ��¼���� (�Ӵ�С)
				Number += 1;
				 // straight flush
				if(A_Card[Row_Counter][Column_Counter-1]==1 && A_Card[Row_Counter][Column_Counter-2]==1 && Column_Counter>=2)
				{
					retrn = 4;
				}
			}
		}
	}
	 // straight flush
	if(retrn == 4)
	{
		return 4;
	}
	 // bomb
	if(Column_Num[0]==Column_Num[1] && Column_Num[1]==Column_Num[2])
	{
		return 3;
	}
	 // flush
	if(Column_Num[0]-Column_Num[1]==1 && Column_Num[1]-Column_Num[2]==1)
	{
		return 2;
	}
	 // pair
	if(Column_Num[0]==Column_Num[1] || Column_Num[1]==Column_Num[2])
	{
		return 1;
	}
	 // single
	return 0;
}
/*	Blackjack	*/
 // �����ȷֿ飬��strcmp���ַ�����취 
int String_Process_Dice(char *RxBuffer,char Card[4])
{
	 // �ֿ� 
	int iscomplete = 0; // �����Ƿ�����ַ��ֿ� 
	int counter; 
	while(RxBuffer[rx_counter] == ' ') // �����ո� 
	{
		rx_counter++;
	}
	for(counter = 0;RxBuffer[rx_counter]!=' ' && RxBuffer[rx_counter]!='\0' && counter <= 2;rx_counter++)
	{
		Card[counter++] = RxBuffer[rx_counter];
	}
	Card[counter] = '\0'; // ��װ�ַ��� 
	 
	if(RxBuffer[rx_counter]=='\0')
	{
		iscomplete = 1;
	}
	return iscomplete;
}

int String_Process_Cmp(char Card[4],int Card_Set[][13])
{
	int Row,Column; // ������
	int Flag = 0; // �������Ƿ�Ϸ���0���Ϸ���1�Ϸ�
	for(Row = 0;Row < 4;Row++)
	{
		for(Column = 0;Column < 13;Column++)
		{
			if(!strcmp(Card,card[Row][Column])) // �������ƱȽ�ȷ�����ڴ�����
			{
				if(Card_Set[Row][Column] == 0) // �ж��Ƿ��ظ�����ĳһ���� 
				{
					Card_Set[Row][Column] += 1;
					Flag = 1;
					break;
				}
			}
		}
		if(Flag)
		{
			break;
		}
	}
	
	return Flag;
}
 // �Ʒ�
int Point_Calc(char Card[4],int *Column_Num,int q)
{
	int Row,Column; // ������
	int Point = 0; // ��ֵ 
	int Flag = 0;
	for(Row = 0;Row < 4;Row++)
	{
		for(Column = 0;Column < 13;Column++)
		{
			if(!strcmp(Card,card[Row][Column])) // �������ƱȽ�ȷ�����ڴ�����
			{
				Column_Num[q] = Column;
				Point += Number[Column];
				Flag = 1;
				break;	
				// ��ΪA������������,PointΪ0
			}
		}
		if(Flag)
		{
			break;
		}
	}
	return Point;
} 

//////////////////////////////////////////////////	
 /*Main Function*/ 
int main()
{	
	int Invalid_Flag = 0; // �����ϴ���Ч���룬1Ϊ�棬0Ϊ�� 
	do
	{
		char choice_1[Len]; // ��Ϸģʽѡ��
		char choice_2[Len]; // ����ѡ�� 
		 // ��Ϸģʽѡ�� 
		if(Invalid_Flag == 0) // �ϴ�Ϊ��Ч���� 
		{
			printf("1. Blackjack\n"
				   "2. Tractor\n"
				   "0. Exit\n"
				   "Input your choice:\n");	
		}
		gets(choice_1);
		Invalid_Flag = 0; // ��ʼ�� 
		
		if(choice_1[0] == '0')
		{
			break;
		}else if(choice_1[0] == '1')
		{
			// Blackjack Start
			char A_RxBuffer[Len],B_RxBuffer[Len]; // ���ջ����� 
			char A_Card[10][4],B_Card[10][4]; // ÿһ�ж��洢��һ������ 
			int iscomplete = 0; // �����Ƿ�����ַ��ֿ�
			int j,k,q;
			int A_Card_Num,B_Card_Num; // A��B��������
			int Legal_Card_Num = 0; // �Ϸ������� 
			int Card_Set[4][13]; // �洢������Ϣ��1����ӵ�д˴�����
			int A_Column[A_Card_Num],B_Column[B_Card_Num]; // �洢���ƴ�С������Ӧ������
			int A_Score,B_Score; // �����ɹٵķ��� 
			char Winner = 'X'; // Ӯ������
			 // ��ʼ������ 
			memset(A_Card,'\0',sizeof(A_Card));
			memset(B_Card,'\0',sizeof(B_Card));
			memset(Card_Set,0,sizeof(Card_Set));
			memset(A_Column,0,sizeof(A_Column));
			memset(B_Column,0,sizeof(B_Column));
			 // �ַ���������� 
			printf("You're playing Blackjack.\n"
				   "Please input cards for each player:\n");
			gets(A_RxBuffer);
			gets(B_RxBuffer);
			 // ���ֿ� ��
			for(j = 0;j<10 && iscomplete==0;j++)
			{
				iscomplete = String_Process_Dice(A_RxBuffer,A_Card[j]);
			}
			A_Card_Num = j; // A������ǡΪj 
			rx_counter = 0; // �����������ļ�������ʼ��Ϊ0
			iscomplete = 0; // �ַ�������ɱ�־��ʼ��Ϊ0 
			for(j = 0;j<10 && iscomplete==0;j++)
			{
				iscomplete = String_Process_Dice(B_RxBuffer,B_Card[j]);
			}
			B_Card_Num = j; // B������ǡΪj 
			rx_counter = 0; // �����������ļ�������ʼ��Ϊ0
			iscomplete = 0; // �ַ�������ɱ�־��ʼ��Ϊ0 
			 // ��strcmp ���жϺϷ���
			for(k = 0;k < A_Card_Num;k++)
			{
				if(!String_Process_Cmp(A_Card[k],Card_Set))
				{
					printf("Input Error!\n");
					goto PlayAgain; // ��ת��ѯ������һ�λ���
				}
			}
			for(k = 0;k < B_Card_Num;k++)
			{
				if(!String_Process_Cmp(B_Card[k],Card_Set))
				{
					printf("Input Error!\n");
					goto PlayAgain; // ��ת��ѯ������һ�λ���
				}
			}
			 // �����ֵ 
			int Point;
			int Times = 0; // ����A�Ĵ���
			A_Score = 0;
			B_Score = 0;
			Point = 0;
			for(q = 0;q < A_Card_Num;q++)
			{
				Point = Point_Calc(A_Card[q],A_Column,q);
				if(Point == 0) // ���������A
				{
					Times++;	
				}else
				{
					A_Score += Point;
				}
			}
			for(;Times > 0;Times--)
			{
				if((A_Score+11) > 21)
				{
					A_Score += 1;
				}else
				{
					A_Score += 11;
				}
			}
			for(q = 0;q < B_Card_Num;q++)
			{
				Point = Point_Calc(B_Card[q],B_Column,q);
				if(Point == 0) // ���������A
				{
					Times++;	
				}else
				{
					B_Score += Point;
				}
			}
			for(;Times > 0;Times--)
			{
				if((B_Score+11) > 21)
				{
					B_Score += 1;
				}else
				{
					B_Score += 11;
				}
			}
//			printf("%d\t%d\n",A_Score,B_Score);
//			int y = 0;
//			for(y = 0;y<A_Card_Num;y++)
//			{
//				printf("%d",A_Column[y]);
//			}
			 // �ж�Ӯ��
			int isBlackJack = 0; // �Ƿ�BlackJack
			if(A_Score>B_Score && A_Score<=21 && B_Score<=21)
			{
				Winner = 'A'; // AӮ��
				if(A_Score == 21)
				{
					int u = 0;
					int A,T; // �ֱ��������A��10 
					A = 0; 
					T = 0;
					for(u = 0;u<A_Card_Num;u++)
					{
						if(A_Column[u]==8||A_Column[u]==9||A_Column[u]==10||A_Column[u]==11) // 10������Ϊ8,9,10,11
						{
							T = 1; 
						}else if(A_Column[u]==12) // A������Ϊ12
						{
							A = 1; 
						}
					}
					if(A==1 && T==1 && A_Card_Num ==2)
					{
						isBlackJack = 1; // ��BlackJack
					}
				} 
			}else if(A_Score>B_Score && A_Score>21 && B_Score<=21)
			{
				Winner = 'B'; // BӮ��
				if(B_Score == 21)
				{
					int u = 0;
					int A,T; // �ֱ��������A��10 
					A = 0; 
					T = 0;
					for(u = 0;u<B_Card_Num;u++)
					{
						if(B_Column[u]==8||B_Column[u]==9||B_Column[u]==10||B_Column[u]==11) // 10������Ϊ8,9,10,11
						{
							T = 1; 
						}else if(B_Column[u]==12) // A������Ϊ12
						{
							A = 1; 
						}
					}
					if(A==1 && T==1 && B_Card_Num ==2)
					{
						isBlackJack = 1; // ��BlackJack
					}
				}
			}else if(A_Score>21 && B_Score>21)
			{
				Winner = 'X'; // ƽ�� 
			}else if(A_Score==21 && B_Score==21)
			{
				int A_isBlack,B_isBlack;
				A_isBlack = 0;
				B_isBlack = 0;
				if(A_Score == 21)
				{
					int u = 0;
					int A,T; // �ֱ��������A��10 
					A = 0; 
					T = 0;
					for(u = 0;u<A_Card_Num;u++)
					{
						if(A_Column[u]==8||A_Column[u]==9||A_Column[u]==10||A_Column[u]==11) // 10������Ϊ8,9,10,11
						{
							T = 1; 
						}else if(A_Column[u]==12) // A������Ϊ12
						{
							A = 1; 
						}
					}
					if(A==1 && T==1 && A_Card_Num ==2)
					{
						A_isBlack = 1; // ��BlackJack
					}
				} 
				if(B_Score == 21)
				{
					int u = 0;
					int A,T; // �ֱ��������A��10 
					A = 0; 
					T = 0;
					for(u = 0;u<B_Card_Num;u++)
					{
						if(B_Column[u]==8||B_Column[u]==9||B_Column[u]==10||B_Column[u]==11) // 10������Ϊ8,9,10,11
						{
							T = 1; 
						}else if(B_Column[u]==12) // A������Ϊ12
						{
							A = 1; 
						}
					}
					if(A==1 && T==1 && B_Card_Num ==2)
					{
						B_isBlack = 1; // ��BlackJack
					}
				}
				if(A_isBlack==0&&B_isBlack==0)
				{
					Winner = 'X'; // ƽ��
				}else if(A_isBlack==1&&B_isBlack==0)
				{
					Winner = 'A';
					isBlackJack = 1; // ��BlackJack
				}else if(A_isBlack==0&&B_isBlack==1)
				{
					Winner = 'B';
					isBlackJack = 1; // ��BlackJack
				}else if(A_isBlack==1&&B_isBlack==1)
				{
					Winner = 'X'; // ƽ��
				}
				 
			}else if(A_Score<B_Score && A_Score<=21 && B_Score<=21)
			{
				Winner = 'B'; // BӮ��
				if(B_Score == 21)
				{
					int u = 0;
					int A,T; // �ֱ��������A��10 
					A = 0; 
					T = 0;
					for(u = 0;u<B_Card_Num;u++)
					{
						if(B_Column[u]==8||B_Column[u]==9||B_Column[u]==10||B_Column[u]==11) // 10������Ϊ8,9,10,11
						{
							T = 1; 
						}else if(B_Column[u]==12) // A������Ϊ12
						{
							A = 1; 
						}
					}
					if(A==1 && T==1 && B_Card_Num ==2)
					{
						isBlackJack = 1; // ��BlackJack
					}
				}
			}else if(A_Score<B_Score && A_Score<=21 && B_Score>21)
			{
				Winner = 'A'; // AӮ��
				if(A_Score == 21)
				{
					int u = 0;
					int A,T; // �ֱ��������A��10 
					A = 0; 
					T = 0;
					for(u = 0;u<A_Card_Num;u++)
					{
						if(A_Column[u]==8||A_Column[u]==9||A_Column[u]==10||A_Column[u]==11) // 10������Ϊ8,9,10,11
						{
							T = 1; 
						}else if(A_Column[u]==12) // A������Ϊ12
						{
							A = 1; 
						}
					}
					if(A==1 && T==1 && A_Card_Num ==2)
					{
						isBlackJack = 1; // ��BlackJack
					}
				}
			}
			
			 // ������
			if(isBlackJack == 1)
			{
				printf("%c wins with a Blackjack!\n",Winner);
			}else if(isBlackJack == 0)
			{
				if(Winner == 'X')
				{
					printf("Draw!\n");
				}else if(Winner == 'A')
				{
					printf("%c wins by %d points!\n",Winner,A_Score-B_Score);
				}else if(Winner == 'B')
				{
					printf("%c wins by %d points!\n",Winner,B_Score-A_Score);
				}
			}
				
		}else if(choice_1[0] == '2')
		{
			// Tractor Start
			char A_RxBuffer[Len],B_RxBuffer[Len]; // ���ջ����� 
			int A_Card[4][13],B_Card[4][13],Total_Card[4][13]; // �洢������Ϣ��1����ӵ�д˴����� 
			int A_Column_Num[3],B_Column_Num[3]; // ������ֵ������������������
			int A_Row_Num[3],B_Row_Num[3]; // ���ƻ�ɫ������������������ 
			char Winner = 'X'; // Ӯ������ 
			 // ��ʼ��Ԫ�ؾ�Ϊ0
			memset(A_Card,0,sizeof(A_Card));
			memset(B_Card,0,sizeof(B_Card));
			memset(Total_Card,0,sizeof(Total_Card));
			memset(A_Row_Num,0,sizeof(A_Row_Num));
			memset(B_Row_Num,0,sizeof(B_Row_Num));
			memset(A_Column_Num,0,sizeof(A_Column_Num));
			memset(B_Column_Num,0,sizeof(B_Column_Num));
			 // �ַ���������� 
			printf("You're playing Tractor.\n"
				   "Please input cards for each player:\n");
			gets(A_RxBuffer);
			gets(B_RxBuffer);
			 // �ַ��������ÿ�����Ϣ
			String_Process(A_RxBuffer,A_Card,Total_Card);
			if(i != 3)
			{
				printf("Input Error!\n");
				i = 0;
				goto PlayAgain; // ��ת��ѯ������һ�λ��� 
			}else
			{
				i = 0; // ��ʼ��i 
			}
			String_Process(B_RxBuffer,B_Card,Total_Card);
			if(i != 3)
			{
				printf("Input Error!\n");
				i = 0;
				goto PlayAgain; // ��ת��ѯ������һ�λ��� 
			}else
			{
				i = 0; // ��ʼ��i 
			}
			 // �ж���������
			/*
			4��straight flush
			3��bomb
			2��flush
			1��pair
			0��single 
			*/ 
			int Retrn_A = Judgement_One(A_Card,A_Column_Num,A_Row_Num);
			int Retrn_B = Judgement_One(B_Card,B_Column_Num,B_Row_Num); // ����������� 
			 // �ж�ʤ��(�ȱ����͡��ٱȴ�С�����Ȼ�ɫ)
			Winner = 'X'; // ��ʼ��Ӯ������ 
			if(Retrn_A > Retrn_B)
			{
				Winner = 'A'; // Winner is A! 
			}else if(Retrn_A < Retrn_B)
			{
				Winner = 'B'; // Winner is B! 
			}else if(Retrn_A == Retrn_B)
			{
				int Counter;
				if(Retrn_A==1&&Retrn_B==1) // pair
				{
					int A_Pair_Num,B_Pair_Num; // ���Ӵ�С
					int A_Other_Num,B_Other_Num; // ��һ���ƴ�С 
					if(A_Column_Num[0] == A_Column_Num[1])
					{
						A_Pair_Num = A_Column_Num[0];
						A_Other_Num = A_Column_Num[2];
					}else if(A_Column_Num[1] == A_Column_Num[2])
					{
						A_Pair_Num = A_Column_Num[1];
						A_Other_Num = A_Column_Num[0];
					}
					if(B_Column_Num[0] == B_Column_Num[1])
					{
						B_Pair_Num = B_Column_Num[0];
						B_Other_Num = B_Column_Num[2];
					}else if(B_Column_Num[1] == B_Column_Num[2])
					{
						B_Pair_Num = B_Column_Num[1];
						B_Other_Num = B_Column_Num[0];
					}
					 // �Ƚ϶��Ӵ�С 
					if(A_Pair_Num > B_Pair_Num)
					{
						Winner = 'A'; // Winner is A!
					}else if(A_Pair_Num < B_Pair_Num)
					{
						Winner = 'B'; // Winner is B!
					}else if(A_Pair_Num == B_Pair_Num) // ���Ӵ�С��ȣ��Ƚ���һ���ƴ�С 
					{
						if(A_Other_Num > B_Other_Num)
						{
							Winner = 'A'; // Winner is A!	
						}else if(A_Other_Num < B_Other_Num)
						{
							Winner = 'B'; // Winner is B!	
						}else if(A_Other_Num == B_Other_Num)
						{
							Winner = 'X'; // ��С��һ�£�������һ���Ƚϻ�ɫ	
						}
					}
				}else // �ȴ�С (�Ӵ���С�Ƚ�)
				{
					for(Counter = 0;Counter < 3;Counter++)
					{
						if(A_Column_Num[Counter] == B_Column_Num[Counter])
						{
							continue;
						}else if(A_Column_Num[Counter] > B_Column_Num[Counter])
						{
							Winner = 'A'; // Winner is A!
							break;
						}else if(A_Column_Num[Counter] < B_Column_Num[Counter])
						{
							Winner = 'B'; // Winner is B! 
							break;
						}
					}
				}
			}
			if(Winner == 'X') // �Ȼ�ɫ(��С�����ϣ��Ӵ���С�Ƚ�)
			{
				int Counter;
				for(Counter = 0;Counter < 3;Counter++)
				{
					if(A_Row_Num[Counter] == B_Row_Num[Counter])
					{
						printf("Input Error!\n");
						goto PlayAgain; // ��ת��ѯ������һ�λ���
					}else if(A_Row_Num[Counter] > B_Row_Num[Counter])
					{
						Winner = 'A'; // Winner is A!
						break;
					}else if(A_Row_Num[Counter] < B_Row_Num[Counter])
					{
						Winner = 'B'; // Winner is B! 
						break;
					}
				}
			}
			 // ������
				printf("Winner is %c!\n"
					   "A:",Winner);
				int Counter_1;
				for(Counter_1 = 0;Counter_1 < 3;Counter_1++)
				{
					printf(" %s",card[A_Row_Num[Counter_1]][A_Column_Num[Counter_1]]);
				}
				printf("\nB:");
				for(Counter_1 = 0;Counter_1 < 3;Counter_1++)
				{
					printf(" %s",card[B_Row_Num[Counter_1]][B_Column_Num[Counter_1]]);
				}
				printf("\n");
		}else
		{
			 // invalid input
			printf("Wrong Input. Input Again.\n");
			Invalid_Flag = 1; // ������Ч���� 
			continue;
		}
		
		
		 // ѯ���Ƿ������ڴ�
		PlayAgain:
			printf("Do you want to play again? (Y/N)\n");
				gets(choice_2);
			if(choice_2[0]=='Y' || choice_2[0]=='y')
			{
				continue;
			}else if(choice_2[0]=='N' || choice_2[0]=='n')
			{
				break;
			}
	}while(1);
	
	return 0;
}
