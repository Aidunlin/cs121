#include "score.h"

/* Gets a score from the user */
double get_score(char* score_type)
{
  double score = 0;
  printf("Enter the score (in percent) for %s: ", score_type);
  scanf("%lf", &score);
  return score;
}

/* Computes an average score */
double compute_average(double score1, double score2)
{
  return (score1 + score2) / 2;
}

/* Computes a weighted average */
double compute_weighted_average(double exam_average, double lab_average, double project_average)
{
  return exam_average * 0.30 * 2 + lab_average * 0.05 * 2 + project_average * 0.15 * 2;
}

/* Displays the weighted average out of 100% */
void display_weighted_average(double weighted_average)
{
  printf("Weighted average: %.2lf%%\n", weighted_average);
}
