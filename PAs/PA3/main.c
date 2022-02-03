/*
  Programmer: Aidan Linerud
  Class: CptS 121, Fall 2021
  Programming Assignment: PA 3
  Date: September 17, 2021
  Description: Collects student data from a file,
    does various calculations on that data,
    and outputs the results to another file.
*/

#include "gpa.h"

int main(void)
{
  /* Collect records from input.dat file */

  FILE *infile = fopen("input.dat", "r");
  
  int r1_id = read_integer(infile);    // 12345678
  double r1_gpa = read_double(infile); // 3.78
  int r1_cs = read_integer(infile);    // 3
  double r1_age = read_double(infile); // 20.5
  
  int r2_id = read_integer(infile);    // 87654321
  double r2_gpa = read_double(infile); // 2.65
  int r2_cs = read_integer(infile);    // 2
  double r2_age = read_double(infile); // 19.25
  
  int r3_id = read_integer(infile);    // 08651234
  double r3_gpa = read_double(infile); // 3.10
  int r3_cs = read_integer(infile);    // 1
  double r3_age = read_double(infile); // 18.0
  
  int r4_id = read_integer(infile);    // 11112222
  double r4_gpa = read_double(infile); // 3.95
  int r4_cs = read_integer(infile);    // 4
  double r4_age = read_double(infile); // 22.5
  
  int r5_id = read_integer(infile);    // 22223234
  double r5_gpa = read_double(infile); // 2.45
  int r5_cs = read_integer(infile);    // 3
  double r5_age = read_double(infile); // 19.3333

  fclose(infile);

  /* Compute collected data */

  int total_records = 5;

  double gpa_sum = calculate_sum(r1_gpa, r2_gpa, r3_gpa, r4_gpa, r5_gpa);
  int cs_sum = calculate_sum((double)r1_cs, (double)r2_cs, (double)r3_cs, (double)r4_cs, (double)r5_cs);
  double age_sum = calculate_sum(r1_age, r2_age, r3_age, r4_age, r5_age);

  double gpa_mean = calculate_mean(gpa_sum, total_records);
  double cs_mean = calculate_mean((double)cs_sum, total_records);
  double age_mean = calculate_mean(age_sum, total_records);

  double gpa1_dev = calculate_deviation(r1_gpa, gpa_mean);
  double gpa2_dev = calculate_deviation(r2_gpa, gpa_mean);
  double gpa3_dev = calculate_deviation(r3_gpa, gpa_mean);
  double gpa4_dev = calculate_deviation(r4_gpa, gpa_mean);
  double gpa5_dev = calculate_deviation(r5_gpa, gpa_mean);
  double gpa_vary = calculate_variance(gpa1_dev, gpa2_dev, gpa3_dev, gpa4_dev, gpa5_dev, total_records);
  double gpa_stdev = calculate_standard_deviation(gpa_vary);

  double gpa_min = find_min(r1_gpa, r2_gpa, r3_gpa, r4_gpa, r5_gpa);
  double gpa_max = find_max(r1_gpa, r2_gpa, r3_gpa, r4_gpa, r5_gpa);

  /* Save computed data to output.dat file */

  FILE *outfile = fopen("output.dat", "w");

  print_double(outfile, gpa_mean);
  print_double(outfile, cs_mean);
  print_double(outfile, age_mean);

  fprintf(outfile, "\n");

  print_double(outfile, gpa_stdev);
  print_double(outfile, gpa_min);
  print_double(outfile, gpa_max);

  fclose(outfile);

  /* Done! */

  printf("Done!\n");

  return 0;
}
