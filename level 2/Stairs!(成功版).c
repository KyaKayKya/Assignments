#include<stdio.h>
//////////////////////////////////////////////////
/*Function*/
int F(int n);
//////////////////////////////////////////////////
/*Main Function*/
int main(){
	
	int ways = 0;
	int stairs = 0;
	
	scanf("%d",&stairs); // input the number of stairs in the staircase
	
	ways = F(stairs);
	if(ways > 1){
		printf("There are %d ways of climbing the stairs!\n",ways);
	}else
	{
		printf("There is %d way of climbing the stairs!\n",ways); // 只火不灯?光改“is ”不改“stairs ”？ 
	}
	
	
	return 0;
}
//////////////////////////////////////////////////
/*原理：n阶有两种情况，第一次移动走一步，之后的移动方式数目与n-1阶一样；第一次移动走两步，之后的移动方式数目与n-2阶一样…
故F（n） =  F(n-1) + F(n-2)*/  
int F(int n){
	if(n == 1){
		return 1;
	}else if(n == 2){
		return 2;
	}else {
		return F(n-1)+F(n-2);
	}
}
