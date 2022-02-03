#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_prime(int num)
{
  int prime = 1;
  for (int i = 2; i < num; i++)
  {
    if (num % i == 0)
    {
      prime = 0;
      break;
    }
  }
  return prime;
}

void task1()
{
  /*
    With your team, write a program that reads in each of the integer values in a file and determines if the sum of the integers is prime.
    Determine if the sum of the individual digits, in the sum of the integers, is prime.
    Use functions where appropriate!
  */
  
  printf("\nTASK 1 (prime)\n");

  int sum = 0;
  FILE *values_file = fopen("values.txt", "r");
  do
  {
    int value = 0;
    fscanf(values_file, "%d", &value);
    sum += value;
  } while (!feof(values_file));
  fclose(values_file);
  printf("Sum of values = %d\n", sum);

  if (is_prime(sum))
  {
    printf("%d is prime!\n", sum);
  }
  else
  {
    printf("%d is NOT prime!\n", sum);
  }

  int sum_digits = 0;
  int temp_sum = sum;
  while (temp_sum > 0)
  {
    sum_digits += temp_sum % 10;
    temp_sum /= 10;
  }  
  printf("Sum of digits of %d = %d\n", sum, sum_digits);

  if (is_prime(sum_digits))
  {
    printf("%d is prime!\n", sum_digits);
  }
  else
  {
    printf("%d is NOT prime!\n", sum_digits);
  }
}

void task2()
{
  /*
    With your team, write a program that determines the factorial of n, represented n!, where n is entered by the user.
    Make sure that your program checks to see if n is greater than or equal to 0.
    As long as n is negative your program should continue to prompt for another value for n.
    Recall 0! is equal to 1 and 1! is also equal to 1.
    The factorial of a number such as n! is equal to n * (n – 1) * (n – 2) *… * 1.
    Use functions where appropriate!
  */
  
  printf("\nTASK 2 (factorial)\n");

  int n = -1;
  while (n < 0)
  {
    printf("Enter an integer (at least 0): ");
    scanf("%d", &n);
  }

  int factorial = 1;
  for (int i = n; i > 0; i--)
  {
    factorial *= i;
  }
  printf("%d! = %d\n", n, factorial);
}

void task3()
{
  /*
    Write a program that determines the Fibonacci number for the nth term.
    Recall, the first Fibonacci number is 0 and the second Fibonacci number is 1.
    The next number in the sequence is always determined by the sum of the previous two terms or numbers in the sequence.
    Fib (n) = Fib (n-1) + Fib (n-2).
    The n value should be entered by the user.
    Use functions where appropriate!
  */
  
  printf("\nTASK 3 (fibonacci)\n");

  int n = 0;
  while (n <= 0)
  {
    printf("Which fibonacci term? ");
    scanf("%d", &n);
  }

  int a = 0;
  if (n == 2)
  {
    a = 1;
  }
  else if (n > 2)
  {
    int b = 1;
    int c = 0;
    for (int i = 0; i < n - 1; i++)
    {
      c = a + b;
      a = b;
      b = c;
    }
  }
  printf("Term %d: %d\n", n, a);
}

void task4()
{
  /*
    Write a program that generates a random number between -100 to 100 and requires that the user guesses which number was generated.
    If the user guesses too high, then the program should say so.
    If the user guesses too low, then the program should say so again.
    The program should continue to loop until the user guesses the correct number.
    If the user guesses a number outside the range of -100 to 100, then the program should just prompt the user to re-enter a number without indicating if the guess was too high or too low.
    Keep track of the total number of guesses taken by the user.
    Use nested loops to solve this problem.
    Use functions where appropriate!
  */
  
  printf("\nTASK 4 (guess game)\n");

  srand((unsigned int) time(NULL));
  int rand_num = rand() % 201 - 100;
  int total_guesses = 0;
  int guess = 0;
  
  while (1)
  {
    printf("Guess a number (-100 to 100): ");
    scanf("%d", &guess);
    if (guess > 100 || guess < -100)
    {
      continue;
    }
    
    ++total_guesses;
    if (guess < rand_num)
    {
      printf("%d is too low! ", guess);
    }
    else if (guess > rand_num)
    {
      printf("%d is too high! ", guess);
    }
    else if (guess == rand_num)
    {
      printf("Correct! It is %d! Total guesses: %d\n", rand_num, total_guesses);
      break;
    }
  }
}

int main()
{
  task1();
  task2();
  task3();
  task4();
  return 0;
}
