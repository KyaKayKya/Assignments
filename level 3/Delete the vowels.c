#include<stdio.h>
#include<string.h>
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	int Lines_Number = 0;
	int Counter = 0;

	scanf("%d",&Lines_Number);
	getchar(); // ��ֹ�´ζ��뻺������'\n' 
	
	for(Counter = 0;Counter < Lines_Number;Counter++)
	{
		char String[100];  
		char Char_Register = 'a';
		int i = 0;
		int a = 0; // ���ڱ�������ַ��� 
		// ���ɣ�ֻ��һ��ѭ���ڲ�ʹ�õġ�һ���� ��������ѭ���ڶ��壬��Ч���⡰��ʷ�������� ��

		while(Char_Register != '\n')
		{
			Char_Register = getchar(); // �ȴ�����תվ���ж��Ƿ�ΪԪ�� 
			if(Char_Register=='\n' || 
			Char_Register=='a' || Char_Register=='A' || 
			Char_Register=='e' || Char_Register=='E' || 
			Char_Register=='i' || Char_Register=='I' || 
			Char_Register=='o' || Char_Register=='O' || 
			Char_Register=='u' || Char_Register=='U')
			{
			}else // ��ΪԪ������ʽ�����ַ��� 
			{
				String[i] = Char_Register;
				i++;
			}
		}
		for(a = 0;a < i;a++)
		{
			printf("%c",String[a]);
		}
		printf("\n"); // �����������ı�� 
	}
	return 0;
}

