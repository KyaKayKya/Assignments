#include <stdio.h>
#include <math.h>

enum {FALSE,TRUE};

int main(){
	
	int digit = 0,min = 0,max = 0,sum = 0,NUM = 0,num = 0,n = 0,i = FALSE; 
	
	scanf("%d",&digit);
	min = pow(10,digit-1);
	max = pow(10,digit)-1;

	for(;min <= max;min++)
	{
		NUM = min;
		sum = 0;
		for(n = 0;n < digit;n++)
		{
			num = NUM%10;
			sum += pow(num,digit);
			NUM /= 10;
		}
		if(sum == min){
			printf("%d\n",min);
			i = TRUE;
		}
	}
	
	if(i == FALSE){
		printf("No output.\n");
	}
	
	return 0;
}
