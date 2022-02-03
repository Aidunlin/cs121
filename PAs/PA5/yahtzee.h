/*
	Programmer: Aidan Linerud
	Assignment: PA 5
	Description: Implements the game of Yahtzee
	NOTE: this includes aidanlib.h
*/

#ifndef YAHTZEE_H
#define YAHTZEE_H

#include "aidanlib.h"

// NOT TO BE CHANGED

#define CHOSEN 1
#define NOT_CHOSEN 0
#define TOTAL_COMBINATIONS 13

#define COMBINATION_THREE_OF_A_KIND 7
#define COMBINATION_FOUR_OF_A_KIND 8
#define COMBINATION_FULL_HOUSE 9
#define COMBINATION_SMALL_STRAIGHT 10
#define COMBINATION_LARGE_STRAIGHT 11
#define COMBINATION_YAHTZEE 12
#define COMBINATION_CHANCE 13

// These can be (reasonably) changed

#define TOTAL_DICE 5
#define DICE_MIN_VALUE 1
#define DICE_MAX_VALUE 6

#define TOTAL_PLAYERS 2
#define TOTAL_ROUNDS 14
#define TOTAL_ROLLS_PER_ROUND 3

#define SCORE_FULL_HOUSE 25
#define SCORE_SMALL_STRAIGHT 30
#define SCORE_LARGE_STRAIGHT 40
#define SCORE_YAHTZEE 50
#define SCORE_BONUS_THRESHOLD 63
#define SCORE_BONUS 35

typedef struct player
{
	int upper_score;
	int lower_score;
	int combinations[TOTAL_COMBINATIONS];
} Player;

/*
	Prints the game rules and pauses the console
*/
void print_game_rules(void);

/*
	Runs a complete game of Yahtzee
*/
void game_loop(void);

/*
	Initializes a player struct
*/
void init_player(Player* player);

/*
	Initializes all of the player structs within the struct array
*/
void init_players(Player players[]);

/*
	Rolls every dice
	Post: dice is updated with random values
*/
void roll_dice(int dice[]);

/*
	Rerolls every dice chosen
	diceChosen is an int array with boolean values
	If a value is 1, than the corresponding value in dice is rerolled
	Post: diceChosen and dice are potentially updated with new values
*/
void reroll_dice(int dice_chosen[], int dice[]);

/*
	Lets the current player choose and reroll their dice
	Post: dice is potentially updated with new values
*/
void reroll_loop(int dice[]);

/*
	Ensures the player has chosen a combination
	Post: The combination chosen is updated in the current player's struct
*/
void combination_loop(int current_player, int dice[], Player players[]);

/*
	Displays the results of the game
*/
void print_scores_and_winner(Player players[]);

/*
	Prints dice with enumerations
*/
void print_dice(int dice[]);

/*
	Prints any/all unchosen combinations with score values
*/
void print_combinations(int combinations[]);

/*
	Updates score values based on what combination is chosen, and what combinations are available
	upperScorePtr and lowerScorePtr are output parameters
*/
void score_combination(int combination_input, int dice[], int* upper_score_ptr, int* lower_score_ptr);

/*
	Returns true if the array of dice contains an exact number (x) of duplicate values
*/
int has_x_of_a_kind(int dice[], int x);

/*
	Returns true if the array of dice contains two exact sets of duplicate values
	If the number of dice is even, each set is exactly half the number of dice
	If the number of dice is odd (5, for example), one set will have one less die than the other (2 and 3, for example)
*/
int has_full_house(int dice[]);

/*
	Returns true if the array of dice contains a straight with at least x amount of elements
	Pre: integers in sorted_dice must be in ascending order
*/
int has_x_straight(int sorted_dice[], int x);

/*
	Gets the total score of a player, including a bonus if applicable
*/
int get_total_score(Player player);

#endif
