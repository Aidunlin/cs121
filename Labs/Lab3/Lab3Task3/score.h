#ifndef SCORE_H
#define SCORE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* Gets a score from the user */
double get_score(char* score_type);

/* Computes an average score */
double compute_average(double score1, double score2);

/* Computes a weighted average */
double compute_weighted_average(double exam_average, double lab_average, double project_average);

/* Displays the weighted average out of 100% */
void display_weighted_average(double weighted_average);

#endif
