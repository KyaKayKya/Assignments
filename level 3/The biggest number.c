#include<stdio.h>
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	int Int_Number;
 	int Digits_Number = 0; // λ�� 
 	int Number[50]; // ���ڴ洢����λ���ϵ��� 
 	int Start_Digit = 0; // ��ʼ�ȴ�С��λ��
	int End_Digit;  // �����ȴ�С��λ��
	int i = 0;
 	
 	scanf("%d",&Int_Number);

 	for(Digits_Number = 0;Int_Number > 0;Digits_Number++) // �洢����λ���ϵ��� 
 	{
 		Number[Digits_Number] = Int_Number%10;
 		Int_Number /= 10;
	}
	
 	End_Digit = (Digits_Number-1);
 	 // ÿ��ѭ�����˷ֱ�Ϊ���������������С�������� 
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
 				Number[Start_Digit] = Max; // ����������λ������ 
			}
			if(Min>Number[Register] && Number[Register]<Number[End_Digit])
			{
				Min = Number[Register];
 				Number[Register] = Number[End_Digit];
 				Number[End_Digit] = Min; // ��С�������λ������ 
			}
			Register++;
		} 
	}
 	
 	for(i = 0;i < Digits_Number;i++)
 	{
 		printf("%d",Number[i]); // �������ı�� 
	}
	
	printf("\n");
 	
 	return 0;
}
