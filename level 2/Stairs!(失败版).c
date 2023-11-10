#include<stdio.h>
//////////////////////////////////////////////////
/*Function*/
void GetWays(int stairs,int NowStairs); // µÝ¹éÇóways of movement  
//////////////////////////////////////////////////
/*Global Variable*/
int ways = 0;
int PreStairs = 0;
//////////////////////////////////////////////////
/*Main Function*/
int main(){
	int stairs = 0;
	int NowStairs = 0;
	
	scanf("%d",&stairs); // input the number of stairs in the staircase
	
	GetWays(stairs,NowStairs);
	
	printf("There are %d ways of climbing the stairs!\n",ways);
	
	return 0;
}
//////////////////////////////////////////////////
// µÝ¹éº¯Êý 
void GetWays(int stairs,int NowStairs){
	// one step
	if(NowStairs < stairs)
	{
		PreStairs = NowStairs;
		NowStairs++; // go up one step
		GetWays(stairs,NowStairs);
	}else if(NowStairs == stairs)
	{
		ways++; // add one possible way of movement
		NowStairs = PreStairs; // initialize NowStairs
	}else if(NowStairs > stairs){
		NowStairs = PreStairs; // initialize NowStairs
	}
	// two steps
	if(NowStairs < stairs)
	{
		PreStairs = NowStairs;
		NowStairs += 2; // go up two steps
		GetWays(stairs,NowStairs);
	}else if(NowStairs == stairs)
	{
		ways++; // add one possible way of movement
		NowStairs = PreStairs; // initialize NowStairs
	}else if(NowStairs > stairs){
		NowStairs = PreStairs; // initialize NowStairs
		break;
	}
}
