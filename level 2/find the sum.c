#include<stdio.h>
//////////////////////////////////////////////////
 /*Function*/
int Get_Sign(int Denominator);
//////////////////////////////////////////////////
 /*Main*/
int main()
{
	int n = 0;
	double Denominator = 2.0;
	double output = 1.0;

	scanf("%d",&n);
	
	for(Denominator = 2;Denominator <= n;Denominator++)
	{
		output += Get_Sign(Denominator)*(1/Denominator);
	}
	if(n == 1)
	{
		printf("%d\n",(int)output);
	}else
	{
		printf("%f\n",output);
	}
	
	
	return 0;
}

//////////////////////////////////////////////////
 /*Definition*/
int Get_Sign(int Denominator)
{
	int sign = 0;
	
	if(Denominator%2 == 0)
	{
		sign = 1;
	}else if(Denominator%2 == 1)
	{
		sign = -1;
	}
	
	return sign;
}
