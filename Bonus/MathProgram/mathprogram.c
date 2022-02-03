#include "mathprogram.h"

void clear_console()
{
	system("cls");
}

void pause_console()
{
	system("pause");
}

int get_int_input()
{
	int input = 0;
	printf("> ");
	scanf("%d", &input);
	return input;
}

void get_initials(char initials[])
{
	do
	{
		printf("Enter your initials (ex: AHL):\n");
		scanf("%s", initials);
	} while (strlen(initials) != 3);
}

char* get_file_name(char initials[])
{
	char* file_name = "saves/___.txt";
	file_name[6] = initials[0];
	file_name[7] = initials[1];
	file_name[8] = initials[2];
	return file_name;
}

char* difficulty_to_str(Difficulty difficulty)
{
	if (difficulty == LEVEL_EASY)
	{
		return "Easy";
	}
	else if (difficulty == LEVEL_FAIR)
	{
		return "Fair";
	}
	else if (difficulty == LEVEL_INTERMEDIATE)
	{
		return "Intermediate";
	}
	else if (difficulty == LEVEL_HARD)
	{
		return "Hard";
	}
	else if (difficulty == LEVEL_IMPOSSIBLE)
	{
		return "Impossible";
	}
	else
	{
		return "_____";
	}
}

Difficulty validate_difficulty(Difficulty difficulty)
{
	if (difficulty < LEVEL_EASY)
	{
		return LEVEL_EASY;
	}
	else if (difficulty > LEVEL_IMPOSSIBLE)
	{
		return LEVEL_IMPOSSIBLE;
	}
	else
	{
		return difficulty;
	}
}

Difficulty get_difficulty_input()
{
	Difficulty input = LEVEL_EASY;
	printf("Choose a difficulty:\n");
	for (int i = LEVEL_EASY; i <= LEVEL_IMPOSSIBLE; i++)
	{
		printf("%d) %s\n", i, difficulty_to_str(i));
	}
	input = get_int_input();
	input = validate_difficulty(get_int_input());
	return input;
}

Profile new_profile()
{
	Profile profile;
	get_initials(profile.initials);
	profile.difficulty = LEVEL_EASY;
	profile.total_score = 0;
	return profile;
}

int load_profile(Profile* profile_ptr)
{
	FILE* profile_file = NULL;
	char* file_name = get_file_name(profile_ptr->initials);
	profile_file = fopen(file_name, "r");
	if (profile_file != NULL)
	{
		fscanf(profile_file, "%d", &profile_ptr->difficulty);
		fscanf(profile_file, "%d", &profile_ptr->total_score);
		fclose(profile_file);
		profile_ptr->difficulty = validate_difficulty(profile_ptr->difficulty);
		if (profile_ptr->total_score < 0)
		{
			profile_ptr->total_score = 0;
		}
		return 1;
	}
	return 0;
}

void save_profile(Profile profile)
{
	char* file_name = get_file_name(profile.initials);
	FILE* profile_file = NULL;
	profile_file = fopen(file_name, "w");
	if (profile_file != NULL)
	{
		fprintf(profile_file, "%d\n", profile.difficulty);
		fprintf(profile_file, "%d\n", profile.total_score);
		fclose(profile_file);
	}
}

int get_rand_int(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void do_problems(Difficulty difficulty)
{
	clear_console();
	for (int i = 0; i < 1; i++)
	{
		int guess_answer = 0;
		int guess_remainder = -1;
		int guess_denominator = 0;
		int correct_answer = 0;
		int correct_remainder = -1;
		int correct_denominator = 0;
		if (difficulty == LEVEL_EASY)
		{
			int n1 = get_rand_int(-9, 9);
			int n2 = get_rand_int(-9, 9);
			int n3 = get_rand_int(-9, 9);
			correct_answer = n1 + n2 + n3;
			printf("%d%+d%+d =\n", n1, n2, n3);
			guess_answer = get_int_input();
		}
		else if (difficulty == LEVEL_FAIR)
		{
			int n1 = get_rand_int(0, 9);
			int n2 = get_rand_int(0, 9);
			correct_answer = n1 * n2;
			printf("%dx%d =\n", n1, n2);
			guess_answer = get_int_input();
		}
		else if (difficulty == LEVEL_INTERMEDIATE)
		{
			int n1 = get_rand_int(0, 9);
			int n2 = get_rand_int(1, 9);
			correct_answer = n1 / n2;
			correct_remainder = n1 % n2;
			printf("%d/%d =\n", n1, n2);
			printf("Enter number then remainder (ex: 1 2):\n> ");
			scanf("%d %d", &guess_answer, &guess_remainder);
		}
		else if (difficulty == LEVEL_HARD)
		{
			int n1 = get_rand_int(-9, 9);
			int n2 = get_rand_int(-9, 9);
			int n3 = get_rand_int(-9, 9);
			
		}
		else if (difficulty == LEVEL_IMPOSSIBLE)
		{

		}
		if (guess_answer == correct_answer)
		{
			printf("Correct answer!\n");
		}
		else
		{
			printf("Incorrect answer! (%d)\n", correct_answer);
		}
		if (correct_remainder != -1)
		{
			if (guess_remainder == correct_remainder)
			{
				printf("Correct remainder!\n");
			}
			else
			{
				printf("Incorrect remainder! (%d)\n", correct_remainder);
			}
		}
		if (correct_denominator != 0)
		{
			if (guess_denominator == correct_denominator)
			{
				printf("Correct denominator!\n");
			}
			else
			{
				printf("Incorrect denominator! (%d)\n", correct_denominator);
			}
		}
		pause_console();
	}
}

void program()
{
	srand((unsigned int)time(NULL));
	clear_console();
	Profile profile = new_profile();
	load_profile(&profile);
	int choice = 0;
	while (choice != 3)
	{
		clear_console();
		printf("Welcome %s\n", profile.initials);
		printf("%s -- %d pts\n", difficulty_to_str(profile.difficulty), profile.total_score);
		printf("1) Select difficulty\n");
		printf("2) Do problems\n");
		printf("3) Exit\n");
		choice = get_int_input();
		if (choice == 1)
		{
			clear_console();
			profile.difficulty = get_difficulty_input();
			save_profile(profile);
		}
		else if (choice == 2)
		{
			do_problems(profile.difficulty);
		}
	}
}
