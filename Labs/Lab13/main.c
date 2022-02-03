#include <stdio.h>
#include <math.h>

int power2(int number, int pow)
{
	int output = number;

	for (int i = 0; i < pow - 1; i++)
	{
		output <<= 2;
	}

	return output;
}

void print_decimal_binary(unsigned int x)
{
	unsigned int value = x;
	int binary_value[32] = {0};

	for (int i = 0; i < 32; i++)
	{
		int bit_value = pow(2, 31 - i);

		if (value / bit_value >= 1)
		{
			binary_value[i] = 1;
			value %= bit_value;
		}
	}

	printf("%10u or", x);

	for (int i = 0; i < 32; i++)
	{
		if (i % 8 == 0)
		{
			printf(" ");
		}

		printf("%d", binary_value[i]);
	}

	printf("\n");
}

unsigned int pack_characters(char c1, char c2, char c3, char c4)
{
	unsigned int packed = c1;

	packed = (packed << 8) | c2;
	packed = (packed << 8) | c3;
	packed = (packed << 8) | c4;

	return packed;
}

void task1()
{
	printf("\nTASK 1\n");

	unsigned int x = 255;
	print_decimal_binary(x);

	unsigned int result = x >> 4;
	print_decimal_binary(result);
}

void task2()
{
	printf("\nTASK 2\n");

	unsigned int x = 3;
	print_decimal_binary(x);

	unsigned int pow = 2;
	print_decimal_binary(pow);

	unsigned int result = power2(x, pow);
	print_decimal_binary(result);
}

void task3()
{
	printf("\nTASK 3\n");

	char c1 = 'C';
	char c2 = 'p';
	char c3 = 't';
	char c4 = 'S';

	print_decimal_binary(c1);
	print_decimal_binary(c2);
	print_decimal_binary(c3);
	print_decimal_binary(c4);

	unsigned int packed = pack_characters(c1, c2, c3, c4);
	print_decimal_binary(packed);
}

int main()
{
	task1();
	task2();
	task3();
	return 0;
}
