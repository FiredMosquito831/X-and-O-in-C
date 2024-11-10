#include <stdio.h>


void show_game_table(char game_table[5][5])
{
	printf("\n---------\n");
	for (int i = 1; i < 4; i ++)
	{
		for (int j = 0; j < 5; j ++)
		{
			printf("%c ", game_table[i][j]);
		}
		printf("\n");
	}
	printf("---------\n");

}

void user_insert(char turn, char game_table[5][5])
{
	int pos1, pos2;

	printf("It is the turn of %c, please enter the coordinates where you want to write %c: \n", turn, turn);
	while(true)
	{
		scanf_s("%d", &pos1);
		scanf_s("%d", &pos2);
		if (pos1 >= 1 && pos1 <= 3 && pos2 >= 1 && pos2 <= 3)
		{
			if (game_table[pos1][pos2] != '_')
			{
				printf("the position %d %d has %c in it try again:\n",pos1, pos2, game_table[pos1][pos2]);
			}
			else {
				break;
			}
		} else
		{
			printf("The positional for x and y should be both between 1 and 3, try again!\n");
		}
	}

	game_table[pos1][pos2] = turn;
}

char check_who_wins(char game_table[5][5])
{
	int win;
	char winner_char;
	winner_char = 'a';
	int j;


	// checking lines
	for (int i = 1; i <= 3; i ++)
	{
		win = 1;
		for (j = 1; j < 3; j ++)
		{
			if (game_table[i][j] != game_table[i][j + 1])
			{
				win = 0;
			}
		}
		if (win == 1) // check if any of the lanes is a winner if it is breaks the loop and returns the winner
		{
			winner_char = game_table[i][j];
			break;
		}
	}

	if (winner_char == 'X' || winner_char == 'O')
	{
		return winner_char;
	}


	// checking columns 
	for (int i = 1; i < 3; i++)
	{
		win = 1;
		for (j = 1; j < 3; j++)
		{
			if (game_table[j][i] != game_table[j + 1][i])
			{
				win = 0;
			}
		}
		if (win == 1)
		{
			winner_char = game_table[j][i];
			break;
		}
	}

	if (winner_char == 'X' || winner_char == 'O')
	{
		return winner_char;
	}




	// checking main diagonal
	win = 1;
	for (j = 1; j < 3; j ++)
	{
		if (game_table[j][j] != game_table[j + 1][j + 1])
		{
			win = 0;
		}
	}
	if (win == 1)
	{
		winner_char = game_table[j][j];
		if (winner_char == 'X' || winner_char == 'O')
		{
			return winner_char;
		}
	}

	// checking second diagonal
	win = 1;
	for (j = 1; j < 3; j++)
	{
		if (game_table[j][4 - j] != game_table[j + 1][4 - j - 1])
		{
			win = 0;
		}
	}
	if (win == 1)
	{
		winner_char = game_table[j][j];
		if (winner_char == 'X' || winner_char == 'O')
		{
			return winner_char;
		}
	}

	// check draw
	win = 0;
	for (int i = 1; i <= 3; i ++)
	{
		for (j = 1; j <= 3; j ++)
		{
			if(game_table[i][j] == '_')
			{
				return '_';
				break;	
			}
		}
	}
	return 'D';
}


void reset_game(char game_table[5][5], char &turn)
{
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			game_table[i][j] = '_';
		}
	}

	turn = 'X';
}

void run_game (char turn, char game_table[5][5])
{
	reset_game(game_table, turn);
	char winner, choice;
	choice = ' ';
	printf("Welcome to X and O!\n\n");

	while (true)
	{
		show_game_table(game_table);
		user_insert(turn, game_table);
		if (turn == 'X')
		{
			turn = 'O';
		}
		else
		{
			turn = 'X';
		}
		winner = check_who_wins(game_table);

		if (winner == 'X' || winner == 'O')
		{
			printf("%c winns\nDo you want to start a new game? (y for yes and n to exit\n", winner);

			scanf_s(" %c", &choice, 1);

			if (choice == 'y')
			{
				reset_game(game_table, turn);
			}
			else
			{
				break;
			}
		}
		else if (winner == '_')
		{

		}
		else if (winner == 'D')
		{
			printf("Draw\n");
			printf("Do you want to start a new game? (y for yes and n to exit");

			scanf_s(" %c ", &choice, 1);
			if (choice == 'y')
			{
				reset_game(game_table, turn);
			}
			else
			{
				printf("I hope you enjoyed the game!\nGoodbye!");
				break;
			}
		}
	}
}

int main()
{

	char turn = 'X', game_table[5][5];
	game_table[1][0] = '|';
	game_table[1][4] = '|';
	game_table[2][0] = '|';
	game_table[2][4] = '|';
	game_table[3][0] = '|';
	game_table[3][4] = '|';
	run_game(turn, game_table);

}
