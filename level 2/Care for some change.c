// 10:10  50:12  100:9  ---> 100+600+900=1600

#include<stdio.h>
#define Pack 1600

int main(){
		
	int TenNum = 0;
	int Coefficient = 0;
	int Total = 0;

	scanf("%d",&TenNum);
	Total = TenNum*1000;	
	if(Total % Pack == 0)
	{
		Coefficient = Total/Pack;
		printf("%d,%d,%d\n",Coefficient*10,Coefficient*12,Coefficient*9);
	}else printf("No change.\n");
		
		
	return 0;
}
