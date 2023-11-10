#include <stdio.h>

int main(){
	
	int PeopleNumber = 0, VanquishedNumber = 0, TotalGold = 1000, ExtraGold = 0, PerGold = 0;
	char Name[100];
//initialize player information
	
	printf("Welcome to Lost Fortune!\n\n"
	"Please enter the following for your personalized adventure.\n\n"
	"Enter a number:");
	scanf("%d",&PeopleNumber);
	printf("\nEnter a number, smaller than the first:");
	scanf("%d",&VanquishedNumber);
	printf("\nEnter your name:");
	getchar();
	scanf("%[^\n]",Name);
	
	printf("\nPeopleNumber = %d,VanquishedNumber = %d",PeopleNumber,VanquishedNumber);
	printf("\nName:%s",Name);
	return 0;
}
