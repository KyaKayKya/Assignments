#include <stdio.h>

int main (){
	
	int inum1 = 0,inum2 = 0,inum3 = 0,inum4 = 0,min = 0,max = 0,counter = 0,num = 0;
	
	while (1)
	{
		counter = 0;
		
		scanf("%d %d",&min,&max);
		if(min == 0 && max == 0)
		{
			break;
		}else if(!(min < 10000 && min > 999 && max < 10000 && max > 999) )
		{
			printf("Error\n");
			continue;
		}else {
		
			if(min%2 != 0)
			{
				min++;
			}
		
			for (;min <= max;min += 2)
			{
				num = min;
				inum1 = num%10;
				num /= 10;
				inum2 = num%10;
				num /= 10;
				inum3 = num%10;
				num /= 10;
				inum4 = num%10;
				num /= 10;
			
				if(inum1 != inum2 && inum1 != inum3 && inum1 != inum4 && inum2 != inum3 && inum2 != inum4 && inum3 != inum4)
				{
					printf("%d  ",min);
					counter++;
				}
			}
			printf("\ncounter=%d\n",counter);
		}
	}
	
	return 0;
}
