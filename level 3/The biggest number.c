#include<stdio.h>
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	int Int_Number;
 	int Digits_Number = 0; // 位数 
 	int Number[50]; // 用于存储各个位数上的数 
 	int Start_Digit = 0; // 开始比大小的位数
	int End_Digit;  // 结束比大小的位数
	int i = 0;
 	
 	scanf("%d",&Int_Number);

 	for(Digits_Number = 0;Int_Number > 0;Digits_Number++) // 存储各个位数上的数 
 	{
 		Number[Digits_Number] = Int_Number%10;
 		Int_Number /= 10;
	}
	
 	End_Digit = (Digits_Number-1);
 	 // 每次循环两端分别为给区间内最大与最小的两个数 
 	for(Start_Digit = 0;Start_Digit < End_Digit;Start_Digit++,End_Digit--)
 	{
 		int Register = Start_Digit;
 		int Max = 0;
		int Min = 9;
 		while(Register <= End_Digit)
 		{
 			if(Max<Number[Register] && Number[Register]>Number[Start_Digit])
 			{
 				Max = Number[Register];
 				Number[Register] = Number[Start_Digit];
 				Number[Start_Digit] = Max; // 最大数与最高位数互换 
			}
			if(Min>Number[Register] && Number[Register]<Number[End_Digit])
			{
				Min = Number[Register];
 				Number[Register] = Number[End_Digit];
 				Number[End_Digit] = Min; // 最小数与最低位数互换 
			}
			Register++;
		} 
	}
 	
 	for(i = 0;i < Digits_Number;i++)
 	{
 		printf("%d",Number[i]); // 面向结果的编程 
	}
	
	printf("\n");
 	
 	return 0;
}
