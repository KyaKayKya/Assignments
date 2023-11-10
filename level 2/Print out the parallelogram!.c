#include <stdio.h>

int main(){
	
	int n = 0;
	int counter = 0;
	int StarCounter = 0;
	int BlockCounter = 0;
	int BlockNum = 0;
	
	scanf("%d",&n);
	
	while(n > counter && n > 0){
		
		for(BlockCounter = 0;BlockNum > BlockCounter;BlockCounter++){
			printf(" ");
		}
		BlockNum++;
		
		for(StarCounter = 0;n > StarCounter;StarCounter++){
			printf("*");
		}
		printf("\n");
		
		counter++;
	}
	
	if(n <= 0){
		printf("Error!\n");
	}
	
	return 0;
}
