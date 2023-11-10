#include<stdio.h>
//////////////////////////////////////////////////
/*Function Prototype*/
void invalid_option();  // 无效输入 
char ask_question(char prompt[],char Answer,char choice1,char msg1[],char choice2,char msg2[]);
//////////////////////////////////////////////////
/* Global Variable */

//////////////////////////////////////////////////	
/*Main Function*/ 
int main()
{
	char Name[50]; // Name
	char Answer;
 // start the game
	printf("Type your name:\n");
	gets(Name);
	printf("Welcome, %s, to this adventure!\n\n"
	"You are on a dirt road, it has come to an end and you can go left or right. Which way would you like to go? (left(L)/right(R))\n\n",Name);
	scanf("%c",&Answer);
	
	if(Answer == 'L')
	{	
		Answer = ask_question("You come to a river, you can walk around it or swim across? (walk(W)/swim(S))\n\n",
		Answer,
		'W',"You walked for many miles, ran out of water and you died.\n",
		'S',"You swam across and were eaten by an alligator. You lose.\n");
		
		return 0;
	}else if(Answer == 'R')
	{
		Answer = ask_question("You come to a bridge, it looks wobbly, do you want to cross it or head back (cross(C)/back(B))?\n\n",
		Answer,
		'C',"You cross the bridge and meet a stranger. Do you talk to them (yes(Y)/no(N))?\n",
		'B',"There is no heading back. Stupid. You lose.\n");
		
		if(Answer == 'C')
		{
			Answer = ask_question("\n",Answer,
			'Y',"You talk to the stranger and they give you gold. You WIN!\n\n",
			'N',"You ignore the stranger and they are offended and attack you. You die.\n");
			if(Answer == 'N')
			{
				return 0;
			}else if(Answer == 'Y')
			{
				printf("Thank you for playing, %s.\n",Name);
			}else
			{
				invalid_option(); // 无效输入
				return 0;
			}
		}else if(Answer == 'B')
		{
			return 0;
		}else
		{
			invalid_option(); // 无效输入
			return 0;
		}
	}else
	{
		invalid_option(); // 无效输入 
		return 0;
	}
	
	
	return 0;
}
///////////////////////////////////////////////////
/*Private Function*/
char ask_question(char prompt[],char Answer,char choice1,char msg1[],char choice2,char msg2[])
{
	printf("%s",prompt); // 给出提示词
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
	printf("Not a valid option. You lose.\n");
}
