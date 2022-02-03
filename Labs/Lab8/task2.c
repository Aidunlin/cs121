#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand((unsigned int)time(NULL));
  
  int timesGenerated[101];
  for (int i = 0; i < 101; i++)
  {
    timesGenerated[i] = 0;
  }

  // Populate array with random integers,
  // store number of times generated

  int randInts[20];
  for (int i = 0; i < 20; i++)
  {
    int randInt = rand() % 100 + 1;
    randInts[i] = randInt;
    timesGenerated[randInt]++;
  }

  // Print each number if it was generated once,
  // and number of times it was generated

  for (int i = 0; i < 101; i++)
  {
    if (timesGenerated[i] > 0)
    {
      printf("%d: %d time(s)\n", i, timesGenerated[i]);
    }
  }

  return 0;
}

/*
  Write a program that populates an array with 20 random integers between 1 - 100.
  The program must traverse through the array and determine how many times each integer was generated.
  Use a second array of size 101 to keep track of the number of times each integer was generated.
  Initialize each item in the second array to 0.
  For each item in the first array, use it as the index into the second array and increment the contents found in the second array at the corresponding index.
  Note: for this problem we are willing to trade memory efficiency (the second array is mostly unused) for time efficiency.
  We know indexing into an array is very efficient.
*/
