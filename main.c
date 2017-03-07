#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "operations.h" // operations header

struct player players[6];  // creates an array of 6 structures
int main(void)
{
	int p,i,j,choice;
	printf("How many players are there?: ");  // stores the number of players in playernumber
	scanf("%d",&playernumber);
	
	for(i=0;i<p;i++)     // loop to store data on each player
	{
		int  dex=0, sm=0, st=0, l=0, m=0;  // variables to store data on each player
		printf("Enter your name: ");       // stores name of each player
		scanf("%s",&players[i].name);
		
		printf("Choose your type: \n1 for Ogre \n2 for Human \n3 for Wizard \n4 for Elf\n");   
		scanf("%d",&choice);  // stores class of each player
		
		switch(choice)
			{
			case 1:{
				players[i].class = 0;     
				break;
			}
			case 2:{
				players[i].class = 1;
				break;
			}
			case 3:{
				players[i].class = 2;
				break;
			}
			case 4:{
				players[i].class = 3;
				break;

			}
			default:{
				printf("ERROR!");
				exit(0);   
			}
			}
			
			stats( &dex, &l, &m, &st, &sm, &i); 
			players[i].dexterity =dex;
			players[i].luck = l;
			players[i].magic =m;
			players[i].strength = st;
			players[i].smartness= sm;
			players[i].lifepoints = 100;
	}	

	print(playernumber ,choice);	
	
	
	
	
	srand(time(NULL)); // seed the rand function

	
	struct slots slot[20]; // struct slots called slot

	// ask user for the number of players and verify that it is between 1 and 6
	
	playerInitialize(player);

	// ask user for the number of slots and verify that it is between 1 and 20
	do
	{
		printf("Please enter the number of slots (max = 20): "); // prompt
		scanf("%d", &slotNumber); // read the number of slots from the user
	} while (slotNumber > 20 || slotNumber < 1); // validate that it is between 1 and 20

	slotTypeRandom(slot);

	playerPositionStart(slot, player);

	while (1 == 1)
	{

	}

	return 0;
}
