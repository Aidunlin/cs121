#include "connect4.h"

int main(void)
{
	int main_menu_choice = 0;

	while (main_menu_choice != 3)
	{
		display_main_menu();
		main_menu_choice = get_input();

		if (main_menu_choice == 1)
		{
			play_game();
		}
		else if (main_menu_choice == 2)
		{
			display_rules();
		}
	}

	return 0;
}
