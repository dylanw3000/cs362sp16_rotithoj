#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "dominion.h"
#include <assert.h>
int assertTrue(int test){
	if(test)
		printf("TEST SUCCESSFUL\n");
	else
		printf("TEST FAILED\n");
	
}
int main(int argc, char * argv[]){
	srand(time(NULL));
	int card = council_room;
	int choice1 = rand() % 50; 
	int choice2 = rand() % 50; 
	int choice3 = rand() % 50;
	int handpos = rand() % 50;
	int numPlayers = rand() % 50;
	int randomSeed = argv[1];
	int kingdomCards [10] = {great_hall, outpost, baron, gardens, smithy, sea_hag, village, adventurer,remodel, council_room};
		struct gameState *state = malloc(sizeof(struct gameState));
	initializeGame(numPlayers, kingdomCards, randomSeed, state);
     state -> numPlayers = whoseTurn(state) + 3;
	int * bonus = NULL;
	int x = state -> numBuys + 1;
	int z = state -> handCount[7];
	int y = cardEffect(card, choice1, choice2, choice3, state, handpos, bonus);
	
	//assert(state -> handCount[state -> whoseTurn] == 4);
	assertTrue(state -> numBuys == x);
	assertTrue(whoseTurn(state) != state -> numPlayers);
	assertTrue(state -> handCount[7] > z);
	return 0;
}
//tests courcil room