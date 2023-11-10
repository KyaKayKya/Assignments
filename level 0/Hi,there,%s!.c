#include <stdio.h> 
#include <string.h>

int power(int figure);
int StringTransformation(char str[],int figure);
 
int main(){ 
	int figure = 0,inum1 = 0,inum2 = 0,sum = 0;
    char str1[1000];
	char str2[1000];
  
	scanf("%[^,]",str1);
	figure = strlen(str1);
	inum1 = StringTransformation(str1,figure);
	
	getchar();
	
	scanf("%[^\n]",str2);
	figure = strlen(str2);
	inum2 = StringTransformation(str2,figure);
		
	sum = inum1 + inum2;
	
	printf("%d\n",sum); 
   
	return 0; 
}

int power(int figure)
{
	int Power = 1;
	
	while(figure > 1)
	{
		Power *= 10;
		figure--;
	}
	
	return Power;
}

int StringTransformation(char str[],int figure)
{
	int inum = 0;
	int i = 0;
	int Power = 1;
	
	while (figure>0)
	{
		Power = power(figure);
		inum += str[i]*Power;
		figure--;
		i++;
	}
	
	return inum;
}
