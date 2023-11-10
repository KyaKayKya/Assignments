#include <stdio.h>
	
	int main(){
		int inum1 = 0,inum2 = 0,sum = 0;
		
		scanf("%d",&inum1);
		getchar();
		scanf("%d",&inum2);
		
		sum = inum1 + inum2;
		
		if(inum1 > -1 && inum2 >-1){
			printf("%d+%d=%d\n",inum1,inum2,sum);
		}else if(inum1 < 0 || inum2 < 0){
			printf("(%d)+(%d)=(%d)\n",inum1,inum2,sum);
		}
		
		return 0;
	}
