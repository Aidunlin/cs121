#include <stdio.h>
#include <stdlib.h>

int main()
{
  system("cls");
  int values[100];
  int count = 0;
  int value = 0;

  // Get integers from a file

  FILE *file = fopen("task1input.txt", "r");
  while (fscanf(file, "%d", &value) != EOF)
  {
    values[count] = value;
    count++;
    printf("%d, ", value);
  }
  fclose(file);

  // Reverse the array

  for (int i = 0; i < count / 2; i++)
  {
    int temp = values[i];
    values[i] = values[count - i - 1];
    values[count - i - 1] = temp;
  }

  // Print the array (again)

  printf("\n");
  for (int i = 0; i < count; i++)
  {
    printf("%d, ", values[i]);
  }
  printf("\n");

  return 0;
}

/*
  Write a program which populates an array with integer values read from a file.
  We do not know how many integers are in the file, so you must loop until the end of the file is reached.
  For this problem, you may NOT use the function feof().
  Instead, use the result returned from fscanf() to determine the end-of-file.
  Recall, we can set the result of fscanf() to an integer variable, and check to see if the integer variable is equal to the EOF marker.
  The program must take the items in the array and reverse them.
  You may use one array only to solve this problem.
*/
