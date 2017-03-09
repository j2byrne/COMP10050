#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "operations.h" // operations header

int main(void)
{
	struct players player[6]; // struct players called player
	struct slots slot[20]; // struct slots called slot

	srand(time(NULL)); // seed the rand function

	// ask user for the number of players and verify that it is between 1 and 6

	do
	{
		printf("Please enter the number of players (max = 6): "); // prompt
		scanf("%d", &playerNumber); // read the number of players from the user

	} while (playerNumber > 6 || playerNumber < 1); // validate that it is between 1 and 6

	puts(""); // go to a new line

	playerInitialize(player);

	puts(""); // go to a new line

	// ask user for the number of slots and verify that it is between 1 and 20
	do
	{
		printf("Please enter the number of slots (from %d to 20): ", playerNumber); // prompt
		scanf("%d", &slotNumber); // read the number of slots from the user
	} while (slotNumber > 20 || slotNumber < playerNumber); // validate that it is between 1 and 20

	slotInitialize(slot); // call function to setup slot types

	playerPositionStart(slot, player); // call function to position each player in a slot

	for (int i = 0; i < playerNumber; i++)
	{
		printf("name %s \t type %d \t life %d \t sm %d \t st %d \t ms %d \t l %d \t d %d \t pos %d\t occ %d \n", player[i].name, player[i].type, player[i].lifePoints, player[i].smartness, player[i].strength, player[i].magicSkills, player[i].luck, player[i].dexterity, player[i].position, slot[player[i].position].occupied);
	}

	// loop through each player
	for (int currentPlayer = 0; currentPlayer < playerNumber; currentPlayer++)
	{
		playerTurn(slot, player, currentPlayer); // call playerTurn function

		printPlayers(player); // print the player name, type and lifePoints
	}

	return 0;
}
