#include<stdio.h>
#include<string.h>
//////////////////////////////////////////////////
 /*Private Define*/
#define StringLen 100
//////////////////////////////////////////////////
 /*Function Prototype*/
int RepetiveNum_Deleter(char *String)
{
	int Counter_One,Counter_Two,Counter_Three;
	
	for(Counter_One = 0;String[Counter_One] != '\0';Counter_One++)
	{
		Counter_Two = Counter_One;
		for(Counter_Three=Counter_One;String[Counter_Three] != '\0';Counter_Three++)
		{
			if(String[Counter_Three]!=String[Counter_One] || Counter_Three==Counter_One)
			{
				String[Counter_Two] = String[Counter_Three];
				Counter_Two++;
			}
		}
		String[Counter_Two] = '\0';
	}
	
	return Counter_Two; // ������Ч�ַ���  
}
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	char String_One[StringLen];
	char String_Two[StringLen];
	int Length;
	int Counter_One,Counter_Two,Counter_Three;
	char Register;
	
	scanf("%s",String_One);
	getchar();
	scanf("%s",String_Two);
	
	strcat(String_One,String_Two);

	Length = RepetiveNum_Deleter(String_One);
	
	for(Counter_Three = 0;Counter_Three < Length;Counter_Three++)
	{
		if(String_One[Counter_Three]>='0' && String_One[Counter_Three]<='9')
		{
		}else if(String_One[Counter_Three]>='a' && String_One[Counter_Three]<='z')
		{
		}else if(String_One[Counter_Three]>='A' && String_One[Counter_Three]<='Z')
		{
		}else
		{
			printf("Wrong Input!\n");
			return 0;
		}
	}
	/*
		����˼·��
		����û��0���õ�û�У�����û��1���У���վ��һ������û��2�����õģ���վ�����桭�� 
		
		
	*/
	Counter_Three = 0;
	for(Counter_One = Counter_Three;Counter_One < 10;Counter_One++) // �� numbers������ǰ�� 
	{
		for(Counter_Two = Counter_Three;Counter_Two < Length;Counter_Two++) // �Ż��� Counter_Three֮ǰ������С��Counter_One+'0'�����ÿ��� 
		{
			if(String_One[Counter_Two] == (Counter_One+'0'))
			{
				Register = String_One[Counter_Three];
				String_One[Counter_Three] = String_One[Counter_Two];
				String_One[Counter_Two] = Register;
				Counter_Three++;
			}
		}
	}
	
	for(Counter_One = 0;Counter_One < 26;Counter_One++) // �� uppercase letters������ǰ�� 
	{
		for(Counter_Two = Counter_Three;Counter_Two < Length;Counter_Two++)
		{
			if(String_One[Counter_Two] == (Counter_One+'A'))
			{
				Register = String_One[Counter_Three];
				String_One[Counter_Three] = String_One[Counter_Two];
				String_One[Counter_Two] = Register;
				Counter_Three++;
			}
		}
	}
	
	for(Counter_One = 0;Counter_One < 26;Counter_One++) // �� lowercase letters������ǰ�� 
	{
		for(Counter_Two = Counter_Three;Counter_Two < Length;Counter_Two++)
		{
			if(String_One[Counter_Two] == (Counter_One+'a'))
			{
				Register = String_One[Counter_Three];
				String_One[Counter_Three] = String_One[Counter_Two];
				String_One[Counter_Two] = Register;
				Counter_Three++;
			}
		}
	}
	
	String_One[Counter_Three] = '\0';
	
	printf("%s\n",String_One);
	
	return 0;
}

