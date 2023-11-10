#include<stdio.h>
#include<string.h>
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	int Lines_Number = 0;
	int Counter = 0;

	scanf("%d",&Lines_Number);
	getchar(); // 防止下次读入缓冲区的'\n' 
	
	for(Counter = 0;Counter < Lines_Number;Counter++)
	{
		char String[100];  
		char Char_Register = 'a';
		int i = 0;
		int a = 0; // 用于遍历输出字符串 
		// 技巧：只在一次循环内部使用的“一次性 ”变量在循环内定义，有效避免“历史遗留问题 ”

		while(Char_Register != '\n')
		{
			Char_Register = getchar(); // 先存入中转站，判断是否为元音 
			if(Char_Register=='\n' || 
			Char_Register=='a' || Char_Register=='A' || 
			Char_Register=='e' || Char_Register=='E' || 
			Char_Register=='i' || Char_Register=='I' || 
			Char_Register=='o' || Char_Register=='O' || 
			Char_Register=='u' || Char_Register=='U')
			{
			}else // 不为元音再正式存入字符串 
			{
				String[i] = Char_Register;
				i++;
			}
		}
		for(a = 0;a < i;a++)
		{
			printf("%c",String[a]);
		}
		printf("\n"); // 还是面向结果的编程 
	}
	return 0;
}

