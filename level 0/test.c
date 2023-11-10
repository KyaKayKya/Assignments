#include <stdio.h>

int main(){
	
/*	int num1 = 10, num2 = 10, sum = 0;
	
	sum += num1;
	sum += num2;
	
	printf("sum=%d\n",sum);

	char string[9] = "12345\n";
*/	
//	printf("size of string :%lu\n",sizeof("12345\n"));//字符串内\n仍为“返回  ”
	int x = 2;
	printf("%d\n",++x*++x);//x只有一个，故会被覆盖为4 
	
	return 0;
} 
