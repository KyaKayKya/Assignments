#include <stdio.h>
#include <math.h>

int main(){
	
	int range = 0;
	int i = 0;
	int inum = 0;
	int Prime = 0;
	int isprime = 1;
	
	scanf("%d",&range); 
	
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
			Prime = inum;
		}else{
			isprime = 1;
		}
	}
	
	printf("The max prime number is %d.\n",Prime);
	
	return 0;
}
