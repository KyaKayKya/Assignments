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
		printf("There is %d way of climbing the stairs!\n",ways); // ֻ�𲻵�?��ġ�is �����ġ�stairs ���� 
	}
	
	
	return 0;
}
//////////////////////////////////////////////////
/*ԭ��n���������������һ���ƶ���һ����֮����ƶ���ʽ��Ŀ��n-1��һ������һ���ƶ���������֮����ƶ���ʽ��Ŀ��n-2��һ����
��F��n�� =  F(n-1) + F(n-2)*/  
int F(int n){
	if(n == 1){
		return 1;
	}else if(n == 2){
		return 2;
	}else {
		return F(n-1)+F(n-2);
	}
}
