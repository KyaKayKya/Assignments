#include <stdio.h>

typedef enum {FtoC = 1,CtoF}Type_t;

int main(){
	
	Type_t type;
	int i;
	double num,result;
	for(i = 0;i < 3;i++)
	{
		scanf("%d %lf",&type,&num);
		if(type == FtoC){
			result = (num - 32.00)/1.80;
			printf("The Centigrade is %.2f\n",result);
		}else if(type == CtoF){
			result = num*1.80 + 32.00;
			printf("The Fahrenheit is %.2f\n",result);
		}else{
			printf("Wrong input!\n");
		}
	}
	
	
	return 0;
}
