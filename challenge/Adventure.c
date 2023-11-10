/*
Welcome to Lost Fortune!

Please enter the following for your personalized adventure.

Enter a number:
Enter a number, smaller than the first:
Enter your name:

A brave group of 100 set out on a quest -- in search of the lost treasure of the Ancient Dwarves.
The group was led by the legendary rogue, Lucky.

Along the way, a band of marauding ogres ambushed the party. All fought bravely under the command of Lucky, and the ogres were defeated, but at a cost.
Of the adventurers, 93 were vanquished, leaving just 7 in the group.

The party was about to give up all hope. But while laying the deceased to rest, they stumbled upon the buried fortune.
So the adventurers split 1000 gold pieces. Each got 142 gold pieces. Lucky held on to the extra 6 pieces to keep things fair of course.
*/

#include <stdio.h>
#include <string.h>
int main()
{
	int PeopleNumber = 0, VanquishedNumber = 0, TotalGold = 1000, ExtraGold = 0, PerGold = 0;
	char Name[100];
//initialize player information
	printf("Welcome to Lost Fortune!\n\n");
	printf("Please enter the following for your personalized adventure.\n\n");
	printf("Enter a number:\n");
	scanf("%d",&PeopleNumber);

	printf("Enter a number, smaller than the first:\n");
	scanf("%d",&VanquishedNumber);

	printf("Enter your name:\n\n");
	getchar();
	gets(Name);

//telling the story
	printf("A brave group of %d set out on a quest -- in search of the lost treasure of the Ancient Dwarves.\n"
	"The group was led by the legendary rogue, %s.\n\n",PeopleNumber,Name);
	
	printf("Along the way, a band of marauding ogres ambushed the party. All fought bravely under the command of %s, and the ogres were defeated, but at a cost.\n"
	"Of the adventurers, %d were vanquished, leaving just %d in the group.\n\n"
	"The party was about to give up all hope. But while laying the deceased to rest, they stumbled upon the buried fortune.\n",Name,VanquishedNumber,PeopleNumber-VanquishedNumber);
	PeopleNumber = PeopleNumber-VanquishedNumber;
	ExtraGold = TotalGold % PeopleNumber;
	PerGold = (TotalGold - ExtraGold)/PeopleNumber;
	printf("So the adventurers split %d gold pieces. Each got %d gold pieces. %s held on to the extra %d pieces to keep things fair of course.\n",TotalGold,PerGold,Name,ExtraGold);

	return 0;
}
