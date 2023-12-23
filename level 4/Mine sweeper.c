#include<stdio.h>
//////////////////////////////////////////////////
/*Function Prototype*/
void Output_Map_Calc(char **Output_Map,int row_counter,int column_counter,int row_num,int column_num); // ���������ͼ 
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	int Flag = 1; // �����Ƿ���� 
	int x = 0; // Field Number
	
	while(Flag == 1)
	{
		int row_num,column_num,i;
		char rxbuffer[50];
		 // ͳ������ 
		x++;
		 // ��ȡ������ 
		scanf("%d",&row_num);
		scanf("%d",&column_num);

		if(row_num==0 && column_num==0) // ���� 
		{
			Flag = 0;
		}else // ����ɨ�� 
		{
			char Input_Map[row_num][column_num],Output_Map[row_num][column_num];
			int row_counter = 0;
			int column_counter = 0;
			 // �����ͼ 
			for(row_counter = 0;row_counter < row_num;row_counter++)
			{
				scanf("%s",&Input_Map[row_counter]);
			}
			 // ��ʼ�������ͼ
			for(row_counter = 0;row_counter < row_num;row_counter++)
			{
				for(column_counter = 0;column_counter < column_num;column_counter++)
				{
					Output_Map[row_counter][column_counter] = '0';
				}
			}
			 // �����λ�Ե����� 
			for(row_counter = 0;row_counter < row_num;row_counter++)
			{
				for(column_counter = 0;column_counter < column_num;column_counter++)
				{
					if(Input_Map[row_counter][column_counter] == '*')
					{
						Output_Map_Calc((char**)Output_Map,row_counter,column_counter,row_num,column_num); 
					}
				}
			}
			 // �����ͼ���ϵ��� 
			for(row_counter = 0;row_counter < row_num;row_counter++)
			{
				for(column_counter = 0;column_counter < column_num;column_counter++)
				{
					if(Input_Map[row_counter][column_counter] == '*')
					{
						Output_Map[row_counter][column_counter] = '*'; 
					}
				}
			}
			if(x > 1)
			{
				printf("\n");
			}
			printf("Field #%d:\n",x);
			for(row_counter = 0;row_counter < row_num;row_counter++)
			{
				for(column_counter = 0;column_counter < column_num;column_counter++)
				{
					printf("%c",Output_Map[row_counter][column_counter]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
///////////////////////////////////////////////////
/*Private Function*/
 // ���������ͼ 
void Output_Map_Calc(char **Output_Map,int row_counter,int column_counter,int row_num,int column_num)
{
	if(row_counter-1 >= 0)
	{
		if(column_counter-1>=0)
		{
			*((char*)Output_Map+column_num*(row_counter-1)+(column_counter-1)) += 1;
		}
		if(column_counter >= 0)
		{
			*((char*)Output_Map+column_num*(row_counter-1)+(column_counter)) += 1;
		}
		if(column_counter+1 < column_num)
		{
			*((char*)Output_Map+column_num*(row_counter-1)+(column_counter+1)) += 1;
		}
	}
	if(row_counter >= 0)
	{
		if(column_counter-1>=0)
		{
			*((char*)Output_Map+column_num*(row_counter)+(column_counter-1)) += 1;
		}
		if(column_counter >= 0)
		{
			*((char*)Output_Map+column_num*(row_counter)+(column_counter)) += 1;
		}
		if(column_counter+1 < column_num)
		{
			*((char*)Output_Map+column_num*(row_counter)+(column_counter+1)) += 1;
		}
	}
	if(row_counter+1 < row_num)
	{
		if(column_counter-1 >= 0)
		{
			*((char*)Output_Map+column_num*(row_counter+1)+(column_counter-1)) += 1;
		}
		if(column_counter >= 0)
		{
			*((char*)Output_Map+column_num*(row_counter+1)+(column_counter)) += 1;
		}
		if(column_counter+1 < column_num)
		{
			*((char*)Output_Map+column_num*(row_counter+1)+(column_counter+1)) += 1;
		}
	}
}
