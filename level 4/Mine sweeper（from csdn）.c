#include<stdio.h>
int main()
{
    int n,m,i,j,num,k=1;
    char t;
    scanf("%d %d\n",&n,&m);
	while (n!=0 && m!=0){
	    int boom[n+2][m+2];//hash,存放炸弹的坐标,有炸弹的地方就是1
	    for (i=0;i<(n+2);i++)//初始化
	        for (j=0;j<(m+2);j++)
	            boom[i][j] = 0;
	    for (i=1;i<=n;i++)//读入地雷位置
	    {
	        for (j=1;j<=m;j++)
	        {
	            t = getchar();
	            if (t=='*')
	                boom[i][j] = 1;
	        }
	        getchar();//读取换行符
	    }
	    printf("Field #%d:\n",k++);
	    for (i=1;i<=n;i++)
	    {
	        for (j=1;j<=m;j++)
	        {
	            num = 0;
	            if (boom[i][j]==1)
	                printf("*");
	            else
	            {
	                num+=(boom[i-1][j]+boom[i+1][j]+boom[i][j-1]+boom[i][j+1]);
	                num+=(boom[i-1][j+1]+boom[i+1][j+1]+boom[i-1][j-1]+boom[i+1][j-1]);
	                printf("%d",num);
	            }
	        }
	        printf("\n");
	    }
	    printf("\n");
	    scanf("%d %d\n",&n,&m);//读取下一组
	}
	return 0;
}

