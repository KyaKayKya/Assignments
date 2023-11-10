#include<stdio.h>
//////////////////////////////////////////////////
/*First Rank Functions*/
int Left(void);
int Right(void);
int Other(void);
/*Second Rank Functions*/
int Walk(void);
int Swim(void);
int Back(void);
int Cross(void);
/*Third Rank Functions*/
int Yes(void);
int No(void);
//////////////////////////////////////////////////
// Global Variable	
char Name[50];
//////////////////////////////////////////////////	
/*Main Function*/ 
int main(){
	char FirstOption;
	// start the game
	printf("Type your name:\n");
	gets(Name);
	
	printf("Welcome, %s, to this adventure!\n\n"
	"You are on a dirt road, it has come to an end and you can go left or right. Which way would you like to go? (left(L)/right(R))\n\n",Name);
	
	scanf("%c",&FirstOption);
	
	if(FirstOption == 'L' ||FirstOption == 'l')
	{
		Left(); // Go left
	}else if(FirstOption == 'R' ||FirstOption == 'r')
	{
		Right(); // Go right
	}else
	{
		Other(); // Not a valid option
	}
	
	return 0;
}

///////////////////////////////////////////////////*First Rank Function*/

// LeftFunction
int Left(void){
	char SecondOption;
	printf("You come to a river, you can walk around it or swim across? (walk(W)/swim(S))\n\n");
	getchar();
	scanf("%c",&SecondOption);
	
		if(SecondOption == 'W' ||SecondOption == 'w')
	{
		Walk(); // Walk
	}else if(SecondOption == 'S' ||SecondOption == 's')
	{
		Swim(); // Swim
	}/*else
	{
		Other(); // Not a valid option
	}*/
	return 0;
}
// RightFunction
int Right(void){
	char SecondOption;
	printf("You come to a bridge, it looks wobbly, do you want to cross it or head back (cross(C)/back(B))?\n\n");
	getchar();
	scanf("%c",&SecondOption);
	
	if(SecondOption == 'C' ||SecondOption == 'c')
	{
		Cross(); // Cross
	}else if(SecondOption == 'B' ||SecondOption == 'b')
	{
		Back(); // Back
	}
	return 0;
}
// OtherFunction
int Other(void){
	printf("Not a valid option. You lose.\n");
	return 0;
}

///////////////////////////////////////////////////*Second Rank Function*/

// WalkFunction
int Walk(void){
	printf("You walked for many miles, ran out of water and you died.\n");
	return 0;
}
// SwimFunction
int Swim(void){
	printf("You swam across and were eaten by an alligator. You lose.\n");
	return 0;
}
// BackFunction
int Back(void){
	printf("There is no heading back. Stupid. You lose.\n");
	return 0;
}
// CrossFunction
int Cross(void){
	char ThirdOption;
	printf("You cross the bridge and meet a stranger. Do you talk to them (yes(Y)/no(N))?\n\n");
	getchar();
	scanf("%c",&ThirdOption);
	
		if(ThirdOption == 'Y' ||ThirdOption == 'y')
	{
		Yes(); // Yes
	}else if(ThirdOption == 'N' ||ThirdOption == 'n')
	{
		No(); // No
	}
	return 0;
}

//////////////////////////////////////////////////*Third Rank Function*/

// YesFunction
int Yes(void){
	printf("You talk to the stranger and they give you gold. You WIN!\n\n"
	"Thank you for playing, %s.\n",Name);
	return 0;
}
// NoFunction
int No(void){
	printf("You ignore the stranger and they are offended and attack you. You die.\n");
	return 0;
}
