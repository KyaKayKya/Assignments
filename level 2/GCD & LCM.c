#include<stdio.h>
//////////////////////////////////////////////////
 /*My function*/
int GetGCD(int iNum1,int iNum2); // 返回值最大公约数 
int GetLCM(int iNum1,int iNum2); // 返回值最小公倍数 
//////////////////////////////////////////////////
int GCD = 1;
//////////////////////////////////////////////////
 /*My main*/
int main(){
	int iNum1 = 0,iNum2 = 0;
	while(1){
		scanf("%d %d",&iNum1,&iNum2);
		if(iNum1 == 0 && iNum2 == 0)
		{
			break;
		}else
		{
			if(iNum1 <= 0 || iNum2 <= 0) // 0没有最大公约数、最小公倍数 
			{
				printf("Error!\n");
				continue;	
			}else
			{
				printf("The GCD of %d and %d is:%d\n",iNum1,iNum2,GetGCD(iNum1,iNum2));
				printf("The LCM of %d and %d is:%d\n",iNum1,iNum2,GetLCM(iNum1,iNum2));
			}
		}
		
		
	}
	return 0;
}

//////////////////////////////////////////////////
// 求解最大公约数
int GetGCD(int iNum1,int iNum2){
	
	int i = 1;
	
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
	int LCM = (iNum1*iNum2)/GCD;
	
	return LCM;
}
/*int GetLCM(int iNum1,int iNum2){
	
	int LCM = 1,i = 1;
	
	if(iNum1 <= iNum2)
	{
		i = iNum1;
		for(;i <= iNum1*iNum2;i++)
		{
			if(i%iNum1 == 0 && i%iNum2 == 0)
			{
				LCM = i;
				break;
			}
		}
	}else
	{
		i = iNum2;	
		for(;i <= iNum1*iNum2 ;i++)
		{
			if(i%iNum1 == 0 && i%iNum2 == 0)
			{
				LCM = i;
				break;
			}
		}
	}
	
	return LCM;
}*/
