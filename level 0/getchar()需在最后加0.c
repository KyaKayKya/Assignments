#include <stdio.h> 
 
int main(){ 
	int i = 0; 
	char p; 
    char str[100]; 
  
	while((p = getchar()) != '\n') 
	{ 
    	str[i] = p; 
    	i++; 
	} 
	str[i] ='\0';
	printf("Hi,there,%s!\n",str); 
   
	return 0; 
}  
