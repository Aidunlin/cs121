#ifndef CONNECT4_H
#define CONNECT4_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TOTAL_ROWS 6
#define TOTAL_COLUMNS 7

#define CELL_EMPTY '-'
#define PLAYER_RED 'R'
#define PLAYER_BLACK 'b'

typedef enum turnResult
{
	RESULT_INVALID,
	RESULT_NORMAL,
	RESULT_WIN,
} TurnResult;

typedef struct game
{
	char current_player;
	int turns;
	int max_turns;
	char board[TOTAL_ROWS][TOTAL_COLUMNS];
} Game;

/* Displays main menu options (clears console) */
void display_main_menu();

/* Returns an integer from the user */
int get_input();

/* Plays a game of Connect4 */
void play_game();

/* Displays rules (clears, pauses console) */
void display_rules();

/* Initializes a new game struct with default/empty values */
Game initialize_game();

/* Plays a turn and returns its result */
TurnResult play_turn(Game* game);

/* Displays the board with column numbers */
void display_board(char board[TOTAL_ROWS][TOTAL_COLUMNS]);

/* Alternates the current player */
void alternate_player(char* current_player);

/* Returns whether the column a valid choice */
bool is_valid_column(char board[TOTAL_ROWS][TOTAL_COLUMNS], int column);

/* Returns the lowest empty spot in a column of the board */
int get_lowest_row(char board[TOTAL_ROWS][TOTAL_COLUMNS], int column);

/* Returns whether the current player won the game */
bool did_player_win(Game game);

/* Returns whether the current player won horizontally */
bool did_player_win_horizontal(Game game);

/* Returns whether the current player won vertically */
bool did_player_win_vertical(Game game);

/* Returns whether the current player won diagonally down */
bool did_player_win_diagonal_down(Game game);

/* Returns whether the current player won diagonally up */
bool did_player_win_diagonal_up(Game game);

#endif
