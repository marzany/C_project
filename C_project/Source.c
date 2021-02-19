#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate() {
	int r = rand() % 3 + 1; /*Generates random number for computer*/
	return r;
}
int checkWin(int playerChoice, int computerChoice) { /*Compares user's and computer's choices and returns result (as int).*/
	int result = -2;
	if (playerChoice == 1 && computerChoice == 3) {
		result = 1;
	}
	else if (playerChoice == 1 && computerChoice == 2) {
		result = -1;
	}
	else if (playerChoice == 2 && computerChoice == 1) {
		result = 1;
	}
	else if (playerChoice == 2 && computerChoice == 3) {
		result = -1;
	}
	else if (playerChoice == 3 && computerChoice == 2) {
		result = 1;
	}
	else if (playerChoice == 3 && computerChoice == 1) {
		result = -1;
	}
	else if (playerChoice == computerChoice) {
		result = 0;
	}
	return result;
}
int ask() { /*Asks user for input as char and returns it as int */
	int usersChoice = -2;
	char userChoiceAsChar = 'e';
	printf("\n(R)ock, (P)aper, (S)cissors? ");
	scanf_s(" %c", &userChoiceAsChar, 1);
	do {
		switch (userChoiceAsChar) {
		case 'R':
		case 'r':
			usersChoice = 1;
			break;
		case 'P':
		case 'p':
			usersChoice = 2;
			break;
		case 'S':
		case 's':
			usersChoice = 3;
			break;
		default:
			printf("Invalid choice\n");
			(void)getchar();
			continue;
		}
	} while (userChoiceAsChar == 'e' && usersChoice == -2);
	return usersChoice;
}

void printResult(int computerChoice, int result) { /*Prints final outcome of round in text based on result */
	if (result == 1) {
		printf("You win! ");
		if (computerChoice == 1) {
			printf("Computer chose: Rock\n");
		}
		else if (computerChoice == 2) {
			printf("Computer chose: Paper\n");
		}
		else if (computerChoice == 3) {
			printf("Computer chose: Scissors\n");
		}
	}
	else if (result == -1) {
		printf("You lost! ");
		if (computerChoice == 1) {
			printf("Computer chose: Rock\n");
		}
		else if (computerChoice == 2) {
			printf("Computer chose: Paper\n");
		}
		else if (computerChoice == 3) {
			printf("Computer chose: Scissors\n");
		}
	}
	else if (result == 0) {
		printf("Tie!\n");
	}
}

int main() {
	srand(time(0));
	int wins = 0;
	int computerWins = 0;
	int ties = 0;
	int rounds = 0;

	printf("Welcome! Let's play Rock-Paper-Scissors game!");

	while (rounds == 0) {
		printf("\nHow many rounds you want to play? ");
		scanf_s(" %d", &rounds);
		(void)getchar();
	}

	int remainingRounds = 0;
	do {/* Game continues as long as there are rounds left */
		int computersChoice = generate();
		int userChoiceAsInt = ask();
		if (userChoiceAsInt > 0 && userChoiceAsInt < 4) {
			remainingRounds++;
			int result = checkWin(userChoiceAsInt, computersChoice);
			if (result == 1) {
				wins++;
			}
			else if (result == -1) {
				computerWins++;
			}
			else if (result == 0) {
				ties++;
			}
			printResult(computersChoice, result);
		}
		else {
			continue; /* Continues to ask user for input if given input was incorrect*/
		}

	} while (remainingRounds < rounds);

	printf("You won %d / %d times.\n", wins, rounds);
	printf("Computer won %d / %d times.\n", computerWins, rounds);
	printf("Number of ties: %d", ties);
	return 0;
}