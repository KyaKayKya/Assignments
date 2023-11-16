#include<stdio.h>
////////////////////////////////////////////////////
 /*Global Variable*/
char uppercase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	int Old_Number;
	int Number_Register;
	char New_Number[16];
	int Number_System;
	int counter = 0;
	
	scanf("%d",&Old_Number);
	scanf("%d",&Number_System);

	if(Number_System != 16)
	{
		printf("%d in %d based system is ",Old_Number,Number_System);
		
		do
		{
			New_Number[counter] = (Old_Number%Number_System)+'0';
			Old_Number /= Number_System;
			counter++;
		}while(Old_Number != 0);
	
		for(counter -= 1;counter >= 0;counter--)
		{
			printf("%c",New_Number[counter]);	
		}
		printf("\n");
	}else if(Number_System == 16)
	{
		printf("%d in %d based system is ",Old_Number,Number_System);
		
		do
		{
			switch(Old_Number%Number_System)
			{
				case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9: 
					New_Number[counter] = (Old_Number%Number_System)+'0';
					break;
				case 10:case 11:case 12:case 13:case 14:case 15:case 16:
					New_Number[counter] = uppercase[(Old_Number%Number_System)-10];
					break;
				default :
					break;
			}
			Old_Number /= Number_System;
			counter++;
		}while(Old_Number != 0);
		
		for(counter -= 1;counter >= 0;counter--)
		{
			printf("%c",New_Number[counter]);	
		}
		printf("\n");
	}
	
	return 0;
} 
