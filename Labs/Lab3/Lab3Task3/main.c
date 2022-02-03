#include "score.h"

int main(void)
{
  printf("TASK 3: Weighted average\n");

  double exam1_score = get_score("Exam 1");
  double exam2_score = get_score("Exam 2");
  double lab1_score = get_score("Lab 1");
  double lab2_score = get_score("Lab 2");
  double project1_score = get_score("Project 1");
  double project2_score = get_score("Project 2");

  double exam_average = compute_average(exam1_score, exam2_score);
  double lab_average = compute_average(lab1_score, lab2_score);
  double project_average = compute_average(project1_score, project2_score);

  double weighted_average = compute_weighted_average(exam_average, lab_average, project_average);
  
  display_weighted_average(weighted_average);

  return 0;
}
