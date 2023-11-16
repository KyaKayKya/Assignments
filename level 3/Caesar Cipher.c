#include<stdio.h>
//////////////////////////////////////////////////
 /*Private Define*/
typedef struct {
	int mode;
	int key;
	char msg[100];
	char output_msg[100];
} Input_Information;

#define exit 0 // mode:exit
#define encrytion 1 // mode:encrytion
#define decryption 2 // mode:decryption
////////////////////////////////////////////////////
 /*Global Variables*/
char lowercase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char uppercase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
//////////////////////////////////////////////////
 /*Function Prototype*/
void string_process(Input_Information *input)
{
	int i = 0;
	if(input->mode == encrytion)
	{
		for(i = 0;i < 100;i++)
		{
			int key = input->key;
			int array_num;
		
			if(input->msg[i]>='A' && input->msg[i]<='Z')
			{
				array_num = input->msg[i] - 'A';
				array_num += key;
				array_num %= 26;
				input->output_msg[i] = uppercase[array_num];
			}else if(input->msg[i]>='a' && input->msg[i]<='z')
			{
				array_num = input->msg[i] - 'a';
				array_num += key;
				array_num %= 26;
				input->output_msg[i] = lowercase[array_num];
			}else
			{
				input->output_msg[i] = input->msg[i];
			}
		}
	}else if(input->mode == decryption)
	{
		for(i = 0;i < 100;i++)
		{
			int key = input->key;
			int array_num;
			key %= 26;
			key = (26-key);
			if(input->msg[i]>='A' && input->msg[i]<='Z')
			{
				array_num = input->msg[i] - 'A';
				array_num += key;
				array_num %= 26;
				input->output_msg[i] = uppercase[array_num];
			}else if(input->msg[i]>='a' && input->msg[i]<='z')
			{
				array_num = input->msg[i] - 'a';
				array_num += key;
				array_num %= 26;
				input->output_msg[i] = lowercase[array_num];
			}else
			{
				input->output_msg[i] = input->msg[i];
			}
		}
	}
}

//////////////////////////////////////////////////
 /*Main*/
int main()
{
	Input_Information input;
	while (1)
	{
		int i = 0;
		char char_register;
		char Bin[100];
		
		scanf("%d",&input.mode);
		if(input.mode == exit) break;
		getchar();
		
		scanf("%d",&input.key);
		getchar();
		
		gets(input.msg);
		
		if(input.mode!=exit && input.mode!=encrytion && input.mode!=decryption)
		{
			printf("Wrong Input. Input Again.\n");	
		}else
		{
			string_process(&input);
		
			printf("%s",input.output_msg);
			printf("\n");
		}
	}
	return 0;
}

