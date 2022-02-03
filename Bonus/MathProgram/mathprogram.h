#ifndef MATHPROGRAM_H
#define MATHPROGRAM_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef enum difficulty
{
	LEVEL_EASY = 1,
	LEVEL_FAIR,
	LEVEL_INTERMEDIATE,
	LEVEL_HARD,
	LEVEL_IMPOSSIBLE
} Difficulty;

typedef struct profile
{
	char initials[3];
	Difficulty difficulty;
	int total_score;
} Profile;

void program();

#endif
