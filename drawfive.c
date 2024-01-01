// includes go here
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// global defines (constants) go here

struct node 
{
	int data;
	struct node* next;
};

// global variables go here

int *scores;
struct node *head = NULL;

// write these functions. This is a requirement. Your code must include the following functions and you must
// invoke them to execute the stated behavior. 

// prints an error message and exits returning an error to the OS
//
void fatal(char* msg)
{
	printf("Error: %s", msg);
	exit(1);
}

// instructs user how to use the program and exits returning an error to the os
//
void usage()
{
	printf("drawfive <number of players> [list of cards]\n");
    printf("\tThe number of players must be at least 2\n");
	exit(1);
}

// pushes an integer onto the stack, exits with error if the stack is full
//
void push(int val)
{
	struct node* n;
	n = malloc(sizeof(struct node));
	n->data = val;
	n->next = head;
	head = n;
}

// returns an integer from the stack, exits with error if the stack is empty
//
int pop()
{
	struct node* n = head;
	if(head) 
    {
		head = head->next;
		int returnValue = n->data;
		free(n);

		return returnValue;
	} 
    else 
    {
		fatal("Stack is empty!");
		exit(1);
	}
}

// fills stack with parameters provided from the command line
//
void fillStack(int argc, char** argv)
{
	
	int numPlayers = atoi(argv[1]);
	int numCards = numPlayers * 5;

	printf("argc: %d numplayers %d\n", argc, 
            numPlayers);
	
	if(argc > (numCards + 2))
    {
		fatal("Stack is full!");
    }
	else
    {
		for(int i = 2; i < argc; i+=1) 
        {
			int currCard = atoi(argv[i]);
			if ((currCard > 0) && (currCard <= 10))
				push(currCard);
			
			else
				fatal("Invalid card index");

		}
		
	}
}

// fills stack with random numbers
//
void fillStackWithRandomNumbers(int numPlayers)
{
   srand((time(NULL)));
   for(int i = 0; i < (numPlayers * 5); i+=1) 
   {
      push((rand() % 10) + 1);
   }
}

// displays the stack in a space separated list. Use this for debugging. 
// It's not necessary to call this function in a normally running program
//
void showStack()
{       // do not display card stack!!
    for (struct node* n = head; n; n = n->next) 
    {
            printf("%d ", n->data);
    }
    printf("\n");
}

// displays scores for all players
//
void showScores(int numPlayers){
	
	printf("\n");
    int i = 0;
    while (i < numPlayers) 
    {
        printf("Player %d scored %d\n", i + 1, scores[i]);
        i += 1;
    }
}

// runs one game for the provided number of players reporting each card
// drawn by each player
//
void runGame(int numPlayers)
{
	for (int i = 0; i < 5; i++) 
    {
		for (int j = 0; j < numPlayers; j+=1) {
			int card = pop();
			printf("Player %d draws %d as %d of 5 cards\n", 
            j + 1, card, i + 1);
			scores[j] += card;
		}
	}
}

// computes the winning player and shows the results, pay careful
// attention to the output, the detail does matter
//
void showWinners(int numPlayers){
	int winner;
    int otherWinners = 0;
    int winningScore = 0;
	int* winners = malloc((numPlayers+1)*sizeof(int));
	
// Find the winner and winning score
    for (int i = 0; i < numPlayers; i++) 
    {
        if (scores[i] > winningScore) 
        {
            winningScore = scores[i];
            winner = i + 1;
        }
    }

// Find other winners with the same score
    for (int i = 0; i < numPlayers; i++)
    {
        if (scores[i] == winningScore && i != winner - 1) 
        {
            winners[otherWinners++] = i + 1;
        }
    }

	printf("\n");

	if(otherWinners != 0)
    {
		printf("Player %d", winner);
        printf(", ");
		for (int i = 0; i < otherWinners - 1; i+=1) 
        {
			printf("%d, ", winners[i]);
		}
		printf("and %d tied with a score of %d\n", winners[otherWinners - 1],\
                winningScore);
	} 
    else
    {
		printf("\nPlayer %d won with a score of %d\n", winner,
                 winningScore);
	}

	free(scores);
	free(winners);
}
	

int main(int argc, char** argv) 
{
    int numPlayers = atoi(argv[1]);
	if ((argc == 1) || (numPlayers <= 1))
    {
		usage();
	}

	if (argc == 2) 
    {
		fillStackWithRandomNumbers(numPlayers);
	
	} 
    else 
    {
		fillStack(argc, argv);
	}
	printf("\n");

	scores = malloc(numPlayers * sizeof(int));

	for (int i = 0; i < numPlayers; i+=1) 
    {
		scores[i] = 0;
	}

    //showStack();
	runGame(numPlayers);
	showScores(numPlayers);
	showWinners(numPlayers);

}