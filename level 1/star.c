#include <stdio.h>

int main(){
	int Max = 0, Min = 100, AverageScore = 0, Sum = 0;
	int num = 10;
	int score[num];
	int i;
	
	for(i = 0;i < 10;i++)
	{
		scanf("%d",&score[i]);
	}
	
	for(i = 0;i < 10;i++)
	{
		if(Max < score[i])
		{
			Max = score[i];
		}
		if(Min > score[i])
		{
			Min = score[i];
		}
	}
	
	for(i = 0;i < 10;i++)
	{
		Sum += score[i];
	}
	
	AverageScore = (Sum-Min-Max)/(num - 2);
	
	printf("Canceled Max Score:%d\n"
		   "Canceled Min Score:%d\n"
		   "Average Score:%d\n",Max,Min,AverageScore);
	
	return 0;
}
