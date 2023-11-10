#include <stdio.h>
#include <math.h> 

int PrimeJudgement(int range,int Prime[]);

int main(){
	
	int range = 0;
	int n,m;
	int Prime[1000];
	
	scanf("%d",&range); 
	if(range > 1)
	{
		m = PrimeJudgement(range,Prime);
		for(n = 0;n < m-1;n++)
		{
			if(n%5 == 4)
			{
				printf("%d\n",Prime[n]);
			}else{
				printf("%d\t",Prime[n]);
			}
		}
		printf("%d\n",Prime[m-1]);	
	}

	return 0;
}

int PrimeJudgement(int range,int Prime[])
{
	int i = 0;
	int n = 0;
	int inum = 0;
	int isprime = 1;
	
	for(inum = 0;inum <= range;inum++)
	{
		for(i = 2;i <= sqrt(inum);i++)
		{
			if(inum%i == 0){
				isprime = 0;
				break;
			}
		}
		
		if(isprime == 1 && inum >=2)
		{
			Prime[n] = inum;
			n++;
		}
		else{
			isprime = 1;
		}
	}
	
	return n;	
}
