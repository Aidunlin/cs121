#include "connect4.h"

/* Displays main menu options (clears console) */
void display_main_menu()
{
	system("cls");
	printf("CONNECT4\n");
	printf("1) Play\n");
	printf("2) Rules\n");
	printf("3) Exit\n");
}

/* Returns an integer from the user */
int get_input()
{
	int result = 0;
	scanf("%d", &result);
	return result;
}

/* Plays a game of Connect4 */
void play_game()
{
	Game game = initialize_game();

	while (game.turns < game.max_turns)
	{
		TurnResult turn_result = play_turn(&game);

		if (turn_result == RESULT_INVALID)
		{
			printf("Invalid column\n");
			system("pause");
		}
		else if (turn_result == RESULT_NORMAL)
		{
			alternate_player(&game.current_player);
			game.turns++;
		}
		else if (turn_result == RESULT_WIN)
		{
			system("cls");
			display_board(game.board);
			printf("Player %c won\n", game.current_player);
			system("pause");
			return;
		}
	}

	system("cls");
	display_board(game.board);
	printf("Tie\n");
	system("pause");
}

/* Displays rules (clears, pauses console) */
void display_rules()
{
	system("cls");
	printf("RULES\n");
	printf("You and your opponent take turns inserting one chip into any column.\n");
	printf("Whoever lines up four of their chips first wins!\n");
	system("pause");
}

/* Initializes a new game struct with default/empty values */
Game initialize_game()
{
	Game new_game;

	new_game.current_player = PLAYER_RED;
	new_game.turns = 0;
	new_game.max_turns = TOTAL_ROWS * TOTAL_COLUMNS;

	for (int row = 0; row < TOTAL_ROWS; row++)
	{
		for (int column = 0; column < TOTAL_COLUMNS; column++)
		{
			new_game.board[row][column] = CELL_EMPTY;
		}
	}

	return new_game;
}

/* Plays a turn and returns its result */
TurnResult play_turn(Game* game)
{
	system("cls");
	display_board(game->board);
	printf("Player %c, pick a column\n", game->current_player);
	int column = get_input() - 1;

	if (!is_valid_column(game->board, column))
	{
		return RESULT_INVALID;
	}

	int row = get_lowest_row(game->board, column);
	game->board[row][column] = game->current_player;

	if (did_player_win(*game))
	{
		return RESULT_WIN;
	}

	return RESULT_NORMAL;
}

/* Displays the board with column numbers */
void display_board(char board[TOTAL_ROWS][TOTAL_COLUMNS])
{
	for (int column = 0; column <= TOTAL_COLUMNS; column++)
	{
		printf("%d ", column + 1);
	}

	printf("\n");

	for (int row = 0; row < TOTAL_ROWS; row++)
	{
		for (int column = 0; column < TOTAL_COLUMNS; column++)
		{
			printf("%c ", board[row][column]);
		}

		printf("\n");
	}
}

/* Alternates the current player */
void alternate_player(char* current_player)
{
	if (*current_player == PLAYER_RED)
	{
		*current_player = PLAYER_BLACK;
	}
	else
	{
		*current_player = PLAYER_RED;
	}
}

/* Returns whether the column a valid choice */
bool is_valid_column(char board[TOTAL_ROWS][TOTAL_COLUMNS], int column)
{
	bool is_column_in_range = column >= 0 && column < TOTAL_COLUMNS;
	return is_column_in_range && board[0][column] == CELL_EMPTY;
}

/* Returns the lowest empty spot in a column of the board */
int get_lowest_row(char board[TOTAL_ROWS][TOTAL_COLUMNS], int column)
{
	for (int row = 0; row < TOTAL_ROWS; row++)
	{
		if (board[row][column] != CELL_EMPTY)
		{
			return row - 1;
		}
	}

	return TOTAL_ROWS - 1;
}

/* Returns whether the current player won the game */
bool did_player_win(Game game)
{
	bool won_horizontal = did_player_win_horizontal(game);
	bool won_vertical = did_player_win_vertical(game);
	bool won_diagonal_down = did_player_win_diagonal_down(game);
	bool won_diagonal_up = did_player_win_diagonal_up(game);

	return won_horizontal || won_vertical || won_diagonal_down || won_diagonal_up;
}

/* Returns whether the current player won horizontally */
bool did_player_win_horizontal(Game game)
{
	for (int row = 0; row < TOTAL_ROWS; row++)
	{
		for (int column = 0; column < TOTAL_COLUMNS - 3; column++)
		{
			bool won_horizontal = true;

			for (int i = 0; i < 4; i++)
			{
				if (game.board[row][column + i] != game.current_player)
				{
					won_horizontal = false;
					break;
				}
			}

			if (won_horizontal)
			{
				return true;
			}
		}
	}

	return false;
}

/* Returns whether the current player won vertically */
bool did_player_win_vertical(Game game)
{
	for (int row = 0; row < TOTAL_ROWS - 3; row++)
	{
		for (int column = 0; column < TOTAL_COLUMNS; column++)
		{
			bool won_vertical = true;

			for (int i = 0; i < 4; i++)
			{
				if (game.board[row + i][column] != game.current_player)
				{
					won_vertical = false;
					break;
				}
			}

			if (won_vertical)
			{
				return true;
			}
		}
	}

	return false;
}

/* Returns whether the current player won diagonally down */
bool did_player_win_diagonal_down(Game game)
{
	for (int row = 0; row < TOTAL_ROWS - 3; row++)
	{
		for (int column = 0; column < TOTAL_COLUMNS - 3; column++)
		{
			bool won_diagonal_down = true;

			for (int i = 0; i < 4; i++)
			{
				if (game.board[row + i][column + i] != game.current_player)
				{
					won_diagonal_down = false;
					break;
				}
			}

			if (won_diagonal_down)
			{
				return true;
			}
		}
	}

	return false;
}

/* Returns whether the current player won diagonally up */
bool did_player_win_diagonal_up(Game game)
{
	for (int row = 0; row < TOTAL_ROWS - 3; row++)
	{
		for (int column = 3; column < TOTAL_COLUMNS; column++)
		{
			bool won_diagonal_up = true;

			for (int i = 0; i < 4; i++)
			{
				if (game.board[row + i][column - i] != game.current_player)
				{
					won_diagonal_up = false;
					break;
				}
			}

			if (won_diagonal_up)
			{
				return true;
			}
		}
	}

	return false;
}
