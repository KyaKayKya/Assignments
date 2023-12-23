#include<stdio.h>
//////////////////////////////////////////////////
/*Function Prototype*/
void invalid_option();  // 无效输入函数
char ask_question(char prompt[],char Answer,char choice1,char msg1[],char choice2,char msg2[]);
//////////////////////////////////////////////////	
/*Main Function*/ 
int main()
{
    char Answer = 'Y';
    char Name[50]; // Name
    int Flag = 0; // 代表是否WIN

    printf("Type your name:\n");
    gets(Name);
    printf("Welcome, %s, to this adventure!\n",Name);
    do
    {
        Backward :
        printf("\nYou are on a dirt road, it has come to an end and you can go left or right. Which way would you like to go? (left(L)/right(R))\n\n");
        scanf("%c",&Answer);

        if(Answer == 'L')
        {
            Answer = ask_question("You come to a river, you can walk around it or swim across? (walk(W)/swim(S))\n\n",
            Answer,
            'W',"You walked for many miles, ran out of water and you died.\n\n",
            'S',"You swam across and were eaten by an alligator. You lose.\n\n");
        }else if(Answer == 'R')
        {
            Answer = ask_question("You come to a bridge, it looks wobbly, do you want to cross it or head back (cross(C)/back(B))?\n\n",
            Answer,
            'C',"You cross the bridge and meet a stranger. Do you talk to them (yes(Y)/no(N))?\n",
            'B',"You go back.\n");
            if(Answer == 'C')
            {
            Answer = ask_question("\n",
            Answer,
            'Y',"You talk to the stranger and they give you gold. You WIN!\n\n",
            'N',"You ignore the stranger and they are offended and attack you. You die.\n\n");
                if(Answer == 'Y')
                {
                    Flag = 1; // WIN WIN WIN
                }
            }else if(Answer == 'B')
            {
            	getchar(); // 清除缓冲区的\n 
                goto Backward; // 回到上一步
            }
        }else
        {
            invalid_option();
        }
        if(Flag == 0) // 若没有WIN
        {
            printf("Do you want to play again? Yes(Y)/No(N)\n");
            getchar(); // 清除缓冲区的\n
	        scanf("%c",&Answer);
            getchar(); // 清除缓冲区的\n 
        }else if(Flag == 1) // WIN WIN WIN
        {
            printf("Thank you for playing, %s.\n",Name);
        }
        
    }while(Answer=='Y' && Flag == 0);

    return 0;
}
///////////////////////////////////////////////////
/*Private Function*/
char ask_question(char prompt[],char Answer,char choice1,char msg1[],char choice2,char msg2[])
{
	printf("%s",prompt); // 输出提示词
	getchar(); // 清除缓冲区的\n
	scanf("%c",&Answer);
	
	if(Answer == choice1)
	{
		printf("%s",msg1);
	}else if(Answer == choice2)
	{
		printf("%s",msg2);
	}else
	{
		invalid_option(); // 无效输入
	}
	
	return Answer;
}

void invalid_option()
{
	printf("Not a valid option. You lose.\n\n");
}
