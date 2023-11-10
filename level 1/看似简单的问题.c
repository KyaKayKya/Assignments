#include <stdio.h>

int main(){
	
	int M,N,Sum,Min;
	
	while(1){
		scanf("%d %d",&M,&N);
		if(M == 0 && N == 0)
		{
			break;
		}else
		{
			if(M < N)
			{
				Min = M;
				M = N;
				N = Min;
			}
			Sum = (M + N)*(M-N+1)/2;
			
			printf("%d\n",Sum);
		}
	}
		
	return 0;
}
