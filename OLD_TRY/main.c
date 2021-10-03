#include "header.h"
/**
 * main - start of program
 * @argc: count of arguments
 * @argv: list of values of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	char *buffer = NULL, *filename;
	size_t len = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	fd = fopen(filename, "r");
	if (filename == NULL || fd == NULL)
		printf("Error: Can't open file %s\n", filename);
	while (getline(&buffer, &len, fd) != EOF)
		parse_factor(buffer);
	free(buffer);
	fclose(fd);
	return (0);
}
/**
 * parse_factor - function to factorize and print the values
 * @buffer: string passed from file
 * Return: None
 */
void parse_factor(char *buffer)
{
	unsigned long long int i, factor, number = atoi(buffer);

	if (number < 4)
	{
		printf("%llu=%llu*1\n", number, number);
		return;
	}
	for (i = 2; i <= number; i++)
	{
		if (number % i == 0)
		{
			factor = number / i;
			break;
		}
	}

	printf("%llu=%llu*%llu\n", number, factor, i);
}
