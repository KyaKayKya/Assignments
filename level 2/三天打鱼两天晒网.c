#include<stdio.h>
//////////////////////////////////////////////////
 /*My function*/
int GetTotal(int Year,int Month,int MonthDay); // �ж�����ģ�飨���ظ���������
//////////////////////////////////////////////////
 /*My main*/
int main(){
	
	int Year,Month,Day;
	int DayNum = 0,Total = 0,MonthDay = 0;
	
	scanf("%d",&DayNum); // input the number of days
	
	for(;DayNum > 0;DayNum--)
	{
		scanf("%d %d %d",&Year,&Month,&Day);
		int MonthRegister = Month;
		int YearRegister = Year;
		Month--; // �ȼ�����·������ͣ�֮��ѡ���ͷ ���������� 
		
		if(Month <= 0)
		{
			Year--;
			Month = 12;
		}
		Total = 0; // ÿ���ȳ�ʼ�������� 
		for(;Year >= 1990;Year--)
		{
			for(;Month >= 1;Month--)
			{
				Total += GetTotal(Year,Month,MonthDay);
			}
			Month = 12;
		}
		Total += Day; // ����ͷ ���������� 
		Total %= 5; // ����һ������ ��ǰ������� 
		if(Total >= 1 &&Total <= 3)
		{
			printf("He was fishing on %d.%d.%d\n",YearRegister,MonthRegister,Day);
		}else
		{
			printf("He was basking on %d.%d.%d\n",YearRegister,MonthRegister,Day);
		}
		
	}
	
	return 0;
}
//////////////////////////////////////////////////
// �ж�����ģ�飨���ظ��������� 
int GetTotal(int Year,int Month,int MonthDay){
	
	switch (Month)
	{	case 1:case 3:case 5: case 7:case 8:
		case 10:case 12:
		    MonthDay =31;
		    break;
		case 4:case 6:case 9:case 11:
		    MonthDay =30;
		    break;
		case 2:
			if(Year%4 == 0 && (Year%100 != 0 || Year%400 == 0))
			{	
				MonthDay =29;
				break;
			}else
			{
				MonthDay =28;
				break;
			}
			default:break;
	}
	
	return MonthDay;
}
