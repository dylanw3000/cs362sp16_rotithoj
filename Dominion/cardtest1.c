#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.h"
#include <assert.h>


int assertTrue(int test){
	if(test)
		printf("TEST SUCCESSFUL\n");
	else
		printf("TEST FAILED\n");
	
}
//test for the great hall card function
int main(){
	int currentPlayer = 1;
	int kingdomCards [10] = {great_hall, outpost, baron, gardens, smithy, sea_hag, village, adventurer,remodel, minion};
int numplayers = 2;

int randomSeed = 10;
struct gameState * state = malloc(sizeof(struct gameState));

state -> numActions = 0;
//initialize the game
initializeGame(numplayers, kingdomCards, randomSeed, state);
	int handpos = 1;
	hallfunc(currentPlayer, state, handpos);
	//the function should have added an action to numActions
	assertTrue(state -> numActions == 1);
	return 0;
}


//int main(){
	//testHallfunc();
	//return 0;
	
//}

