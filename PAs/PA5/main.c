/*
	Programmer: Aidan Linerud
	Assignment: PA 5
	Description: Implements the game of Yahtzee
	NOTE: yahtzee.h includes aidanlib.h
*/

#include "yahtzee.h"

int main(void)
{
	seed_rand();
	int menu_input = 0;
	while (menu_input != 3)
	{
		printf("YAHTZEE!\n");
		printf("1) Play\n");
		printf("2) Rules\n");
		printf("3) Exit\n");
		menu_input = get_int_input();
		if (menu_input == 1)
		{
			game_loop();
		}
		else if (menu_input == 2)
		{
			print_game_rules();
		}
	}
	printf("Goodbye!\n");
	return 0;
}
