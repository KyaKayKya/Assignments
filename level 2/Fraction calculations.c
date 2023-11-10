#include<stdio.h>
//////////////////////////////////////////////////
 /*Functions*/
int Adding(int Numerator_Of_Fraction1,int Numerator_Of_Fraction2,int Denominator_Of_Fraction1,int Denominator_Of_Fraction2); // 加法函数 
int Subtracting(int Numerator_Of_Fraction1,int Numerator_Of_Fraction2,int Denominator_Of_Fraction1,int Denominator_Of_Fraction2); // 减法函数 
int Multiplying (int Numerator_Of_Fraction1,int Numerator_Of_Fraction2,int Denominator_Of_Fraction1,int Denominator_Of_Fraction2); // 乘法函数 
int Dividing (int Numerator_Of_Fraction1,int Numerator_Of_Fraction2,int Denominator_Of_Fraction1,int Denominator_Of_Fraction2); // 除法函数 
int GetGCD(int iNum1,int iNum2); // 返回值最大公约数 
int GetLCM(int iNum1,int iNum2); // 返回值最小公倍数 
//////////////////////////////////////////////////
 /*Global Variables*/
int GCD = 1;
int Numerator_Of_Fraction3 = 0;
int Denominator_Of_Fraction3 = 0;
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	int Numerator_Of_Fraction1 = 1,Numerator_Of_Fraction2 = 1;
	int Denominator_Of_Fraction1 =1,Denominator_Of_Fraction2 =1;
	char Operater;
	// input fractions 
	scanf("%d",&Numerator_Of_Fraction1);
	getchar();
	scanf("%d",&Denominator_Of_Fraction1);
	
	getchar(); // 取空格 
	scanf("%c",&Operater); // 取运算符
	getchar(); // 取空格 
	
	scanf("%d",&Numerator_Of_Fraction2);
	getchar();
	scanf("%d",&Denominator_Of_Fraction2);
	// calculate 
	if(Operater == '+')
	{
		Adding(Numerator_Of_Fraction1,Numerator_Of_Fraction2,Denominator_Of_Fraction1,Denominator_Of_Fraction2);
	}else if(Operater == '-')
	{
		Subtracting(Numerator_Of_Fraction1,Numerator_Of_Fraction2,Denominator_Of_Fraction1,Denominator_Of_Fraction2);
	}else if(Operater == '*')
	{
		Multiplying(Numerator_Of_Fraction1,Numerator_Of_Fraction2,Denominator_Of_Fraction1,Denominator_Of_Fraction2);
	}else if(Operater == '/')
	{
		Dividing(Numerator_Of_Fraction1,Numerator_Of_Fraction2,Denominator_Of_Fraction1,Denominator_Of_Fraction2);
	}
	// output result 
	if(Numerator_Of_Fraction3 != 0 && Denominator_Of_Fraction3 != 1)
	{
		printf("%d/%d %c %d/%d = %d/%d\n",Numerator_Of_Fraction1,Denominator_Of_Fraction1,Operater,Numerator_Of_Fraction2,Denominator_Of_Fraction2,Numerator_Of_Fraction3,Denominator_Of_Fraction3);
	}else if(Numerator_Of_Fraction3 == 0)
	{
		printf("%d/%d %c %d/%d = 0\n",Numerator_Of_Fraction1,Denominator_Of_Fraction1,Operater,Numerator_Of_Fraction2,Denominator_Of_Fraction2);
	}else if(Denominator_Of_Fraction3 == 1)
	{
		printf("%d/%d %c %d/%d = %d\n",Numerator_Of_Fraction1,Denominator_Of_Fraction1,Operater,Numerator_Of_Fraction2,Denominator_Of_Fraction2,Numerator_Of_Fraction3);
	}
	
	return 0;
}


//////////////////////////////////////////////////
 /*Definition*/
// 求解最大公约数
int GetGCD(int iNum1,int iNum2) 
{ 
	
	int i = 1;
	GCD = 1; 
	
	if(iNum1 < 0)
	{
		iNum1 = -1*iNum1;
	}
	if(iNum2 < 0)
	{
		iNum2 = -1*iNum2;
	}
	
	for(i = 1;i <= iNum1 && i <= iNum2;i++)
	{
		if(iNum1%i == 0 && iNum2%i == 0)
		{
			GCD = i;
		}
	}
	return GCD;
}
// 求解最小公倍数 
int GetLCM(int iNum1,int iNum2) 
{
	GetGCD(iNum1,iNum2);
	
	int LCM = (iNum1*iNum2)/GCD;
	
	return LCM;
}
// 加法函数 
int Adding(int Numerator_Of_Fraction1,int Numerator_Of_Fraction2,int Denominator_Of_Fraction1,int Denominator_Of_Fraction2) 
{
	// 先通分 
	Denominator_Of_Fraction3 = GetLCM(Denominator_Of_Fraction1,Denominator_Of_Fraction2);
	Numerator_Of_Fraction3 = Numerator_Of_Fraction1*(Denominator_Of_Fraction3/Denominator_Of_Fraction1) + Numerator_Of_Fraction2*(Denominator_Of_Fraction3/Denominator_Of_Fraction2);
	// 再化简 
	GetGCD(Numerator_Of_Fraction3,Denominator_Of_Fraction3);
	Denominator_Of_Fraction3 = Denominator_Of_Fraction3/GCD;
	Numerator_Of_Fraction3 = Numerator_Of_Fraction3/GCD;
}
// 减法函数 
int Subtracting(int Numerator_Of_Fraction1,int Numerator_Of_Fraction2,int Denominator_Of_Fraction1,int Denominator_Of_Fraction2) 
{
	// 先通分 
	Denominator_Of_Fraction3 = GetLCM(Denominator_Of_Fraction1,Denominator_Of_Fraction2);
	Numerator_Of_Fraction3 = Numerator_Of_Fraction1*(Denominator_Of_Fraction3/Denominator_Of_Fraction1) - Numerator_Of_Fraction2*(Denominator_Of_Fraction3/Denominator_Of_Fraction2);
	// 再化简 
	GetGCD(Numerator_Of_Fraction3,Denominator_Of_Fraction3);
	Denominator_Of_Fraction3 = Denominator_Of_Fraction3/GCD;
	Numerator_Of_Fraction3 = Numerator_Of_Fraction3/GCD;
}
// 乘法函数 
int Multiplying (int Numerator_Of_Fraction1,int Numerator_Of_Fraction2,int Denominator_Of_Fraction1,int Denominator_Of_Fraction2)
{
	// 先乘
	Denominator_Of_Fraction3 = Denominator_Of_Fraction1*Denominator_Of_Fraction2;
	Numerator_Of_Fraction3 = Numerator_Of_Fraction1*Numerator_Of_Fraction2;
	// 再化简 
	GetGCD(Numerator_Of_Fraction3,Denominator_Of_Fraction3);
	Denominator_Of_Fraction3 = Denominator_Of_Fraction3/GCD;
	Numerator_Of_Fraction3 = Numerator_Of_Fraction3/GCD;
}
// 除法函数
int Dividing (int Numerator_Of_Fraction1,int Numerator_Of_Fraction2,int Denominator_Of_Fraction1,int Denominator_Of_Fraction2)
{
	int Register = 0;
	// 将除法转换为乘法
	Register = Numerator_Of_Fraction2;
	Numerator_Of_Fraction2 = Denominator_Of_Fraction2;
	Denominator_Of_Fraction2 = Register;
	// 先乘
	Denominator_Of_Fraction3 = Denominator_Of_Fraction1*Denominator_Of_Fraction2;
	Numerator_Of_Fraction3 = Numerator_Of_Fraction1*Numerator_Of_Fraction2;
	// 再化简 
	GetGCD(Numerator_Of_Fraction3,Denominator_Of_Fraction3);
	Denominator_Of_Fraction3 = Denominator_Of_Fraction3/GCD;
	Numerator_Of_Fraction3 = Numerator_Of_Fraction3/GCD;
}
