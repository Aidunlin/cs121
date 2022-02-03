/*
	Programmer: Aidan Linerud
	Assignment: PA 5
	Description: Implements the game of Yahtzee
	NOTE: this includes aidanlib.h
*/

#include "yahtzee.h"

/*
	Prints the game rules and pauses the console
*/
void print_game_rules(void)
{
	print_file("rules.txt");
	printf("\n");
	pause_console("Press any key to return to the menu");
}

/*
	Runs a complete game of Yahtzee
*/
void game_loop(void)
{
	int current_round = 1;
	int current_player = 0;
	int dice[TOTAL_DICE];
	Player players[TOTAL_PLAYERS];
	init_int_array(dice, TOTAL_DICE, 0);
	init_players(players);
	while (current_round <= TOTAL_ROUNDS)
	{
		printf("Player %d is playing\n", current_player + 1);
		pause_console("Press any key to roll");
		roll_dice(dice);
		bubble_sort(dice, TOTAL_DICE);
		reroll_loop(dice);
		combination_loop(current_player, dice, players);
		current_player++;
		if (current_player == TOTAL_PLAYERS)
		{
			// All players have played this round, start a new one
			current_player = 0;
			current_round++;
		}
	}
	// All rounds have been played at this poitn
	print_scores_and_winner(players);
}

/*
	Initializes a player struct
*/
void init_player(Player* player_ptr)
{
	player_ptr->upper_score = 0;
	player_ptr->lower_score = 0;
	init_int_array(player_ptr->combinations, TOTAL_COMBINATIONS, NOT_CHOSEN);
}

/*
	Initializes all of the player structs within the struct array
*/
void init_players(Player players[])
{
	for (int i = 0; i < TOTAL_PLAYERS; i++)
	{
		init_player(&players[i]);
	}
}

/*
	Rolls every dice
	Post: dice is updated with random values
*/
void roll_dice(int dice[])
{
	for (int i = 0; i < TOTAL_DICE; i++)
	{
		dice[i] = rand_int(DICE_MIN_VALUE, DICE_MAX_VALUE);
	}
}

/*
	Rerolls every dice chosen
	diceChosen is an int array with boolean values
	If a value is 1, than the corresponding value in dice is rerolled
	Post: diceChosen and dice are potentially updated with new values
*/
void reroll_dice(int dice_chosen[], int dice[])
{
	for (int i = 0; i < TOTAL_DICE; i++)
	{
		if (dice_chosen[i] == CHOSEN)
		{
			dice[i] = rand_int(DICE_MIN_VALUE, DICE_MAX_VALUE);
			dice_chosen[i] = NOT_CHOSEN;
		}
	}
}

/*
	Lets the current player choose and reroll their dice
	Post: dice is potentially updated with new values
*/
void reroll_loop(int dice[])
{
	int dice_chosen[TOTAL_DICE];
	init_int_array(dice_chosen, TOTAL_DICE, NOT_CHOSEN);
	int rolls_this_round = 1;
	while (rolls_this_round < TOTAL_ROLLS_PER_ROUND)
	{
		// Modified printDice()
		printf("Dice:\n");
		for (int i = 0; i < TOTAL_DICE; i++)
		{
			printf("- %d: %d%s\n", i + 1, dice[i], dice_chosen[i] ? " (picked)" : "");
		}
		printf("Reroll options:\n");
		printf(" -1: Done (or don't reroll)\n");
		printf("  0: Reroll selected dice\n");
		printf("1-5: Select dice to reroll\n");
		int roll_input = get_int_input();
		if (roll_input == -1)
		{
			break;
		}
		else if (roll_input == 0)
		{
			reroll_dice(dice_chosen, dice);
			bubble_sort(dice, TOTAL_DICE);
			rolls_this_round++;
		}
		else if (roll_input > 0 && roll_input <= TOTAL_DICE)
		{
			dice_chosen[roll_input - 1] = CHOSEN;
		}
	}
}

/*
	Ensures the player has chosen a combination
	Post: The combination chosen is updated in the current player's struct
*/
void combination_loop(int current_player, int dice[], Player players[])
{
	int combination_input = 0;
	int has_chosen = NOT_CHOSEN;
	while (has_chosen == NOT_CHOSEN)
	{
		printf("Player %d is playing\n", current_player + 1);
		print_dice(dice);
		print_combinations(players[current_player].combinations);
		combination_input = get_int_input();
		combination_input = clamp_int(combination_input, 1, TOTAL_COMBINATIONS);
		if (players[current_player].combinations[combination_input - 1] == NOT_CHOSEN)
		{
			score_combination(combination_input, dice,
				&players[current_player].upper_score,
				&players[current_player].lower_score);
			has_chosen = CHOSEN;
		}
	}
	// Due to the valid index check in the while loop,
	// the combination array index will be valid here
	players[current_player].combinations[combination_input - 1] = CHOSEN;
}

/*
	Displays the results of the game
*/
void print_scores_and_winner(Player players[])
{
	pause_console("The results are in! Press any key to see...");
	int winner = -1;
	int greatest_score = 0;
	for (int i = 0; i < TOTAL_PLAYERS; i++)
	{
		int total_score = get_total_score(players[i]);
		if (total_score > greatest_score)
		{
			greatest_score = total_score;
			winner = i;
		}
		printf("Player %d total score: %d\n", i + 1, total_score);
	}
	printf("\nPlayer %d wins!\n", winner + 1);
}

/*
	Prints dice with enumerations
*/
void print_dice(int dice[])
{
	printf("Dice:\n");
	for (int i = 0; i < TOTAL_DICE; i++)
	{
		printf("- %d: %d\n", i + 1, dice[i]);
	}
}

/*
	Prints any/all unchosen combinations with score values
*/
void print_combinations(int combinations[])
{
	printf("Combinations:\n");
	for (int i = 0; i < 6; i++)
	{
		if (combinations[i] == NOT_CHOSEN)
		{
			printf("- %d: Sum of %d's\n", i + 1, i + 1);
		}
	}
	if (combinations[6] == NOT_CHOSEN)
	{
		printf("- 7: Three-of-a-kind (sum of all dice)\n");
	}
	if (combinations[7] == NOT_CHOSEN)
	{
		printf("- 8: Four-of-a-kind (sum of all dice)\n");
	}
	if (combinations[8] == NOT_CHOSEN)
	{
		printf("- 9: Full house (%d)\n", SCORE_FULL_HOUSE);
	}
	if (combinations[9] == NOT_CHOSEN)
	{
		printf("- 10: Small straight (%d)\n", SCORE_SMALL_STRAIGHT);
	}
	if (combinations[10] == NOT_CHOSEN)
	{
		printf("- 11: Large straight (%d)\n", SCORE_LARGE_STRAIGHT);
	}
	if (combinations[11] == NOT_CHOSEN)
	{
		printf("- 12: Yahtzee (%d)\n", SCORE_YAHTZEE);
	}
	if (combinations[12] == NOT_CHOSEN)
	{
		printf("- 13: Chance (sum of all dice)\n");
	}
}

/*
	Updates score values based on what combination is chosen, and what combinations are available
	upperScorePtr and lowerScorePtr are output parameters
*/
void score_combination(int combination_input, int dice[], int* upper_score_ptr, int* lower_score_ptr)
{
	if (combination_input < COMBINATION_THREE_OF_A_KIND)
	{
		int dice_value = combination_input;
		*upper_score_ptr += get_array_sum_of(dice, TOTAL_DICE, dice_value);
	}
	else if (combination_input == COMBINATION_THREE_OF_A_KIND)
	{
		if (has_x_of_a_kind(dice, 3))
		{
			*lower_score_ptr += get_array_sum(dice, TOTAL_DICE);
		}
	}
	else if (combination_input == COMBINATION_FOUR_OF_A_KIND)
	{
		if (has_x_of_a_kind(dice, 4))
		{
			*lower_score_ptr += get_array_sum(dice, TOTAL_DICE);
		}
	}
	else if (combination_input == COMBINATION_FULL_HOUSE)
	{
		if (has_full_house(dice))
		{
			*lower_score_ptr += SCORE_FULL_HOUSE;
		}
	}
	else if (combination_input == COMBINATION_SMALL_STRAIGHT)
	{
		if (has_x_straight(dice, 4))
		{
			*lower_score_ptr += SCORE_SMALL_STRAIGHT;
		}
	}
	else if (combination_input == COMBINATION_LARGE_STRAIGHT)
	{
		if (has_x_straight(dice, 5))
		{
			*lower_score_ptr += SCORE_LARGE_STRAIGHT;
		}
	}
	else if (combination_input == COMBINATION_YAHTZEE)
	{
		if (has_x_of_a_kind(dice, 5))
		{
			*lower_score_ptr += SCORE_YAHTZEE;
		}
	}
	else if (combination_input == COMBINATION_CHANCE)
	{
		*lower_score_ptr += get_array_sum(dice, TOTAL_DICE);
	}
}

/*
	Returns true if the array of dice contains an exact number (x) of duplicate values
*/
int has_x_of_a_kind(int dice[], int x)
{
	for (int i = 0; i < TOTAL_DICE; i++)
	{
		int found_exact_x_of_a_kind = 0;
		int count_same_kind = 0;
		for (int j = 0; j < TOTAL_DICE; j++)
		{
			if (dice[i] == dice[j])
			{
				count_same_kind++;
			}
			found_exact_x_of_a_kind = x == count_same_kind;
		}
		if (found_exact_x_of_a_kind)
		{
			return 1;
		}
	}
	return 0;
}

/*
	Returns true if the array of dice contains two exact sets of duplicate values
	If the number of dice is even, each set is exactly half the number of dice
	If the number of dice is odd (5, for example), one set will have one less die than the other (2 and 3, for example)
*/
int has_full_house(int dice[])
{
	int x1, x2;
	split_int(TOTAL_DICE, &x1, &x2);
	return has_x_of_a_kind(dice, x1) && has_x_of_a_kind(dice, x2);
}

/*
	Returns true if the array of dice contains a straight with at least x amount of elements
	Pre: integers in sorted_dice must be in ascending order
*/
int has_x_straight(int sorted_dice[], int x)
{
	for (int i = 0; i < TOTAL_DICE; i++)
	{
		int straight_count = 1;
		int last_value = sorted_dice[i];
		for (int j = i + 1; j < TOTAL_DICE; j++)
		{
			if (sorted_dice[j] == last_value + 1)
			{
				last_value++;
				straight_count++;
			}
			if (straight_count == x)
			{
				return 1;
			}
		}
	}
	return 0;
}

/*
	Gets the total score of a player, including a bonus if applicable
*/
int get_total_score(Player player)
{
	int total_score = player.upper_score + player.lower_score;
	if (player.upper_score >= SCORE_BONUS_THRESHOLD)
	{
		total_score += SCORE_BONUS;
	}
	return total_score;
}
