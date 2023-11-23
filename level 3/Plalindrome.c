#include<stdio.h>
#include<string.h>
//////////////////////////////////////////////////
 /*Private Define*/
#define Yes 0
#define No 1
//////////////////////////////////////////////////
 /*Function Prototype*/
int Palindrome_Judgement(char *String,int NumberOne,int NumberTwo)
{
	if(NumberOne >= NumberTwo)
	{
		return Yes;
	}else if(String[NumberOne] != String[NumberTwo])
	{
		return No;
	}else if(String[NumberOne] == String[NumberTwo])
	{
		return Palindrome_Judgement(String,NumberOne+1,NumberTwo-1);
	}
}

//////////////////////////////////////////////////
 /*Main*/
int main()
{
	char String[100];
	int StringLen = 0;
	int Result;
	
	gets(String);
	StringLen = strlen(String);

	Result = Palindrome_Judgement(String,0,StringLen-1);
	
	if(Result == Yes)
	{
		printf("Yes\n");
	}else if(Result == No)
	{
		printf("No\n");
	}
	
	return 0;
}
