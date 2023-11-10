
#include <stdio.h>
int main (){
    int n = 0;
    int Line = 0;
    int iNum = 0;
    scanf("%d", &n);
    while(1){
        iNum += 1;
        if(iNum <10){
			printf("  %d",iNum);
		}else if(iNum >= 10){
			printf(" %d",iNum);
		}
        
        
        if(iNum % n == 0){
            printf("\n");
            Line += 1;
        }
        if(Line == n){
            break;
        }
    }
    return 0;
}
