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
int i = 0; // 代表找到了几张合法牌
int rx_counter = 0; // 用于记录现在遍历到缓冲区的某个位置  
///////////////////////////////////////////////////
 /*Private Function*/
 // 处理字符串获得卡牌信息（基于逐字分析，保存坐标的字符处理方法） 
int String_Process(char *A_RxBuffer,int A_Card[][13],int Total_Card[][13])
{
 	int Invalid_Input = 0; // 1代表卡牌输入无效
 	char Char_Register;
 	int Flag = 1; // while循环控制器，1为进行，0为终止
 	int counter = 0;
	while(A_RxBuffer[counter]!='\0' && Flag==1)
	{
		int Row,Column; // 行、列数 
		int Continue_Flag = 0;
		Char_Register = A_RxBuffer[counter++];
		if(Char_Register!=' ')
		{
			switch(Char_Register) // 判断花色
			{
				case 'H':Row = 3;break;
				case 'S':Row = 2;break;
				case 'D':Row = 1;break;
				case 'C':Row = 0;break;
				default: // 若为数字、JQKA，则直接continue，剩下的情况为非法输入 
					if(Char_Register>='0'&&Char_Register<='9')
					{
						Continue_Flag = 1;
					}else if(Char_Register=='J'||Char_Register=='Q'||Char_Register=='K'||Char_Register=='A')
					{
						Continue_Flag = 1;
					}else
					{
						Invalid_Input = 1; // 非法输入 
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
			
			switch(A_RxBuffer[counter]) // 判断大小(只有前一位是合法花色才可进入此判断)
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
							Invalid_Input = 1; // 非法输入
						}
					}else
					{
						Invalid_Input = 1; // 非法输入
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
				A_Card[Row][Column] += 1; // 标记A拥有此牌 
				Total_Card[Row][Column] += 1; // 标记此牌已被获得 
				i++; // 增加一个合法牌 
			}else
			{
				Invalid_Input = 1; // 排除卡牌复用问题
			}
		}else if(Char_Register == ' ')
		{
			continue;
		}
	}
	return 0;
}
 // 初步判断牌组类型 
int Judgement_One(int A_Card[][13],int Column_Num[3],int Row_Num[3])
{
	int Row_Counter,Column_Counter;
	int Number = 0;
	int retrn = 0;
	for(Column_Counter = 12;Column_Counter >= 0;Column_Counter--)
	{
		for(Row_Counter = 3;Row_Counter >= 0;Row_Counter--)
		{
			if(A_Card[Row_Counter][Column_Counter]==1 && Number<=2) // 判断有无牌、防止数组越界 
			{
				Row_Num[Number] = Row_Counter; // 记录行数		
				Column_Num[Number] = Column_Counter; // 记录列数 (从大到小)
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
 // 基于先分块，再strcmp的字符处理办法 
int String_Process_Dice(char *RxBuffer,char Card[4])
{
	 // 分块 
	int iscomplete = 0; // 代表是否完成字符分块 
	int counter; 
	while(RxBuffer[rx_counter] == ' ') // 跳过空格 
	{
		rx_counter++;
	}
	for(counter = 0;RxBuffer[rx_counter]!=' ' && RxBuffer[rx_counter]!='\0' && counter <= 2;rx_counter++)
	{
		Card[counter++] = RxBuffer[rx_counter];
	}
	Card[counter] = '\0'; // 封装字符串 
	 
	if(RxBuffer[rx_counter]=='\0')
	{
		iscomplete = 1;
	}
	return iscomplete;
}

int String_Process_Cmp(char Card[4],int Card_Set[][13])
{
	int Row,Column; // 计数器
	int Flag = 0; // 代表卡牌是否合法，0不合法，1合法
	for(Row = 0;Row < 4;Row++)
	{
		for(Column = 0;Column < 13;Column++)
		{
			if(!strcmp(Card,card[Row][Column])) // 与整套牌比较确认属于此套牌
			{
				if(Card_Set[Row][Column] == 0) // 判断是否重复出现某一张牌 
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
 // 计分
int Point_Calc(char Card[4],int *Column_Num,int q)
{
	int Row,Column; // 计数器
	int Point = 0; // 分值 
	int Flag = 0;
	for(Row = 0;Row < 4;Row++)
	{
		for(Column = 0;Column < 13;Column++)
		{
			if(!strcmp(Card,card[Row][Column])) // 与整套牌比较确认属于此套牌
			{
				Column_Num[q] = Column;
				Point += Number[Column];
				Flag = 1;
				break;	
				// 若为A后续单独讨论,Point为0
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
	int Invalid_Flag = 0; // 代表上次无效输入，1为真，0为假 
	do
	{
		char choice_1[Len]; // 游戏模式选项
		char choice_2[Len]; // 结束选项 
		 // 游戏模式选择 
		if(Invalid_Flag == 0) // 上次为有效输入 
		{
			printf("1. Blackjack\n"
				   "2. Tractor\n"
				   "0. Exit\n"
				   "Input your choice:\n");	
		}
		gets(choice_1);
		Invalid_Flag = 0; // 初始化 
		
		if(choice_1[0] == '0')
		{
			break;
		}else if(choice_1[0] == '1')
		{
			// Blackjack Start
			char A_RxBuffer[Len],B_RxBuffer[Len]; // 接收缓冲区 
			char A_Card[10][4],B_Card[10][4]; // 每一行都存储着一个卡牌 
			int iscomplete = 0; // 代表是否完成字符分块
			int j,k,q;
			int A_Card_Num,B_Card_Num; // A、B卡牌数量
			int Legal_Card_Num = 0; // 合法卡牌数 
			int Card_Set[4][13]; // 存储卡牌信息，1代表拥有此处卡牌
			int A_Column[A_Card_Num],B_Column[B_Card_Num]; // 存储卡牌大小（即对应列数）
			int A_Score,B_Score; // 玩家与荷官的分数 
			char Winner = 'X'; // 赢家名称
			 // 初始化数组 
			memset(A_Card,'\0',sizeof(A_Card));
			memset(B_Card,'\0',sizeof(B_Card));
			memset(Card_Set,0,sizeof(Card_Set));
			memset(A_Column,0,sizeof(A_Column));
			memset(B_Column,0,sizeof(B_Column));
			 // 字符串输入输出 
			printf("You're playing Blackjack.\n"
				   "Please input cards for each player:\n");
			gets(A_RxBuffer);
			gets(B_RxBuffer);
			 // “分块 ”
			for(j = 0;j<10 && iscomplete==0;j++)
			{
				iscomplete = String_Process_Dice(A_RxBuffer,A_Card[j]);
			}
			A_Card_Num = j; // A卡牌数恰为j 
			rx_counter = 0; // 遍历缓冲区的计数器初始化为0
			iscomplete = 0; // 字符处理完成标志初始化为0 
			for(j = 0;j<10 && iscomplete==0;j++)
			{
				iscomplete = String_Process_Dice(B_RxBuffer,B_Card[j]);
			}
			B_Card_Num = j; // B卡牌数恰为j 
			rx_counter = 0; // 遍历缓冲区的计数器初始化为0
			iscomplete = 0; // 字符处理完成标志初始化为0 
			 // “strcmp ”判断合法性
			for(k = 0;k < A_Card_Num;k++)
			{
				if(!String_Process_Cmp(A_Card[k],Card_Set))
				{
					printf("Input Error!\n");
					goto PlayAgain; // 跳转到询问再来一次环节
				}
			}
			for(k = 0;k < B_Card_Num;k++)
			{
				if(!String_Process_Cmp(B_Card[k],Card_Set))
				{
					printf("Input Error!\n");
					goto PlayAgain; // 跳转到询问再来一次环节
				}
			}
			 // 计算分值 
			int Point;
			int Times = 0; // 出现A的次数
			A_Score = 0;
			B_Score = 0;
			Point = 0;
			for(q = 0;q < A_Card_Num;q++)
			{
				Point = Point_Calc(A_Card[q],A_Column,q);
				if(Point == 0) // 代表出现了A
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
				if(Point == 0) // 代表出现了A
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
			 // 判断赢家
			int isBlackJack = 0; // 是否BlackJack
			if(A_Score>B_Score && A_Score<=21 && B_Score<=21)
			{
				Winner = 'A'; // A赢了
				if(A_Score == 21)
				{
					int u = 0;
					int A,T; // 分别代表有无A、10 
					A = 0; 
					T = 0;
					for(u = 0;u<A_Card_Num;u++)
					{
						if(A_Column[u]==8||A_Column[u]==9||A_Column[u]==10||A_Column[u]==11) // 10的列数为8,9,10,11
						{
							T = 1; 
						}else if(A_Column[u]==12) // A的列数为12
						{
							A = 1; 
						}
					}
					if(A==1 && T==1 && A_Card_Num ==2)
					{
						isBlackJack = 1; // 是BlackJack
					}
				} 
			}else if(A_Score>B_Score && A_Score>21 && B_Score<=21)
			{
				Winner = 'B'; // B赢了
				if(B_Score == 21)
				{
					int u = 0;
					int A,T; // 分别代表有无A、10 
					A = 0; 
					T = 0;
					for(u = 0;u<B_Card_Num;u++)
					{
						if(B_Column[u]==8||B_Column[u]==9||B_Column[u]==10||B_Column[u]==11) // 10的列数为8,9,10,11
						{
							T = 1; 
						}else if(B_Column[u]==12) // A的列数为12
						{
							A = 1; 
						}
					}
					if(A==1 && T==1 && B_Card_Num ==2)
					{
						isBlackJack = 1; // 是BlackJack
					}
				}
			}else if(A_Score>21 && B_Score>21)
			{
				Winner = 'X'; // 平局 
			}else if(A_Score==21 && B_Score==21)
			{
				int A_isBlack,B_isBlack;
				A_isBlack = 0;
				B_isBlack = 0;
				if(A_Score == 21)
				{
					int u = 0;
					int A,T; // 分别代表有无A、10 
					A = 0; 
					T = 0;
					for(u = 0;u<A_Card_Num;u++)
					{
						if(A_Column[u]==8||A_Column[u]==9||A_Column[u]==10||A_Column[u]==11) // 10的列数为8,9,10,11
						{
							T = 1; 
						}else if(A_Column[u]==12) // A的列数为12
						{
							A = 1; 
						}
					}
					if(A==1 && T==1 && A_Card_Num ==2)
					{
						A_isBlack = 1; // 是BlackJack
					}
				} 
				if(B_Score == 21)
				{
					int u = 0;
					int A,T; // 分别代表有无A、10 
					A = 0; 
					T = 0;
					for(u = 0;u<B_Card_Num;u++)
					{
						if(B_Column[u]==8||B_Column[u]==9||B_Column[u]==10||B_Column[u]==11) // 10的列数为8,9,10,11
						{
							T = 1; 
						}else if(B_Column[u]==12) // A的列数为12
						{
							A = 1; 
						}
					}
					if(A==1 && T==1 && B_Card_Num ==2)
					{
						B_isBlack = 1; // 是BlackJack
					}
				}
				if(A_isBlack==0&&B_isBlack==0)
				{
					Winner = 'X'; // 平局
				}else if(A_isBlack==1&&B_isBlack==0)
				{
					Winner = 'A';
					isBlackJack = 1; // 是BlackJack
				}else if(A_isBlack==0&&B_isBlack==1)
				{
					Winner = 'B';
					isBlackJack = 1; // 是BlackJack
				}else if(A_isBlack==1&&B_isBlack==1)
				{
					Winner = 'X'; // 平局
				}
				 
			}else if(A_Score<B_Score && A_Score<=21 && B_Score<=21)
			{
				Winner = 'B'; // B赢了
				if(B_Score == 21)
				{
					int u = 0;
					int A,T; // 分别代表有无A、10 
					A = 0; 
					T = 0;
					for(u = 0;u<B_Card_Num;u++)
					{
						if(B_Column[u]==8||B_Column[u]==9||B_Column[u]==10||B_Column[u]==11) // 10的列数为8,9,10,11
						{
							T = 1; 
						}else if(B_Column[u]==12) // A的列数为12
						{
							A = 1; 
						}
					}
					if(A==1 && T==1 && B_Card_Num ==2)
					{
						isBlackJack = 1; // 是BlackJack
					}
				}
			}else if(A_Score<B_Score && A_Score<=21 && B_Score>21)
			{
				Winner = 'A'; // A赢了
				if(A_Score == 21)
				{
					int u = 0;
					int A,T; // 分别代表有无A、10 
					A = 0; 
					T = 0;
					for(u = 0;u<A_Card_Num;u++)
					{
						if(A_Column[u]==8||A_Column[u]==9||A_Column[u]==10||A_Column[u]==11) // 10的列数为8,9,10,11
						{
							T = 1; 
						}else if(A_Column[u]==12) // A的列数为12
						{
							A = 1; 
						}
					}
					if(A==1 && T==1 && A_Card_Num ==2)
					{
						isBlackJack = 1; // 是BlackJack
					}
				}
			}
			
			 // 输出结果
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
			char A_RxBuffer[Len],B_RxBuffer[Len]; // 接收缓冲区 
			int A_Card[4][13],B_Card[4][13],Total_Card[4][13]; // 存储卡牌信息，1代表拥有此处卡牌 
			int A_Column_Num[3],B_Column_Num[3]; // 卡牌面值（即卡牌所在列数）
			int A_Row_Num[3],B_Row_Num[3]; // 卡牌花色（即卡牌所在行数） 
			char Winner = 'X'; // 赢家名称 
			 // 初始化元素均为0
			memset(A_Card,0,sizeof(A_Card));
			memset(B_Card,0,sizeof(B_Card));
			memset(Total_Card,0,sizeof(Total_Card));
			memset(A_Row_Num,0,sizeof(A_Row_Num));
			memset(B_Row_Num,0,sizeof(B_Row_Num));
			memset(A_Column_Num,0,sizeof(A_Column_Num));
			memset(B_Column_Num,0,sizeof(B_Column_Num));
			 // 字符串输入输出 
			printf("You're playing Tractor.\n"
				   "Please input cards for each player:\n");
			gets(A_RxBuffer);
			gets(B_RxBuffer);
			 // 字符串处理获得卡牌信息
			String_Process(A_RxBuffer,A_Card,Total_Card);
			if(i != 3)
			{
				printf("Input Error!\n");
				i = 0;
				goto PlayAgain; // 跳转到询问再来一次环节 
			}else
			{
				i = 0; // 初始化i 
			}
			String_Process(B_RxBuffer,B_Card,Total_Card);
			if(i != 3)
			{
				printf("Input Error!\n");
				i = 0;
				goto PlayAgain; // 跳转到询问再来一次环节 
			}else
			{
				i = 0; // 初始化i 
			}
			 // 判断牌组类型
			/*
			4：straight flush
			3：bomb
			2：flush
			1：pair
			0：single 
			*/ 
			int Retrn_A = Judgement_One(A_Card,A_Column_Num,A_Row_Num);
			int Retrn_B = Judgement_One(B_Card,B_Column_Num,B_Row_Num); // 获得牌组类型 
			 // 判断胜负(先比类型、再比大小，最后比花色)
			Winner = 'X'; // 初始化赢家名称 
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
					int A_Pair_Num,B_Pair_Num; // 对子大小
					int A_Other_Num,B_Other_Num; // 另一张牌大小 
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
					 // 比较对子大小 
					if(A_Pair_Num > B_Pair_Num)
					{
						Winner = 'A'; // Winner is A!
					}else if(A_Pair_Num < B_Pair_Num)
					{
						Winner = 'B'; // Winner is B!
					}else if(A_Pair_Num == B_Pair_Num) // 对子大小相等，比较另一张牌大小 
					{
						if(A_Other_Num > B_Other_Num)
						{
							Winner = 'A'; // Winner is A!	
						}else if(A_Other_Num < B_Other_Num)
						{
							Winner = 'B'; // Winner is B!	
						}else if(A_Other_Num == B_Other_Num)
						{
							Winner = 'X'; // 大小均一致，进入下一步比较花色	
						}
					}
				}else // 比大小 (从大往小比较)
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
			if(Winner == 'X') // 比花色(大小意义上，从大往小比较)
			{
				int Counter;
				for(Counter = 0;Counter < 3;Counter++)
				{
					if(A_Row_Num[Counter] == B_Row_Num[Counter])
					{
						printf("Input Error!\n");
						goto PlayAgain; // 跳转到询问再来一次环节
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
			 // 输出结果
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
			Invalid_Flag = 1; // 代表无效输入 
			continue;
		}
		
		
		 // 询问是否再玩亿次
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
