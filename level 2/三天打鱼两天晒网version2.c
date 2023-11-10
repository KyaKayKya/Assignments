#include<stdio.h>
//////////////////////////////////////////////////
 /*My function*/
int GetTotal(int Year,int Month); // 判断闰年模块（返回该月天数）
int Validater(int Year,int Month,int Day); // 判断日期合法性 
//////////////////////////////////////////////////
 /*My main*/
int main(){
	
	int Year,Month,Day;
	int DayNum = 0,Total = 0;
	
	scanf("%d",&DayNum); // input the number of days
	
	for(;DayNum > 0;DayNum--)
	{
		
		scanf("%d %d %d",&Year,&Month,&Day); // input the number of days
		
		if(Validater(Year,Month,Day) == 0) 
		{
			break;
		}
		
		int MonthRegister = Month;
		int YearRegister = Year;
		Month--; // 先计算的月份天数和，之后把“零头 ”天数补上
		
		if(Month <= 0)
		{
			Year--;
			Month = 12;
		}
		Total = 0; // 每次先初始化总天数
		for(;Year >= 1990;Year--)
		{
			for(;Month >= 1;Month--)
			{
				Total += GetTotal(Year,Month);
			}
			Month = 12;
		}
		Total += Day; // “零头 ”天数补上 
		Total %= 5; // 五天一个周期 ，前三天打渔 
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
// 判断闰年模块（返回该月天数）
int GetTotal(int Year,int Month){
	int MonthDay = 0;
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

// 判断日期合法性 
int Validater(int Year,int Month,int Day){
	int key = 1,MonthDay = 0;
	if(Year < 1990)
	{
		printf("Year is wrong!\n");
		key = 0;
	}else if(Month < 1 || Month > 12)
	{
		printf("Month is wrong!\n");
		key = 0;
	}else if(Day <1 || Day > GetTotal(Year,Month))
	{
		printf("Day is wrong!\n");
		key = 0;
	}
	
	return key;
}
