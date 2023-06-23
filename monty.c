#include "monty.h"

GlobalData gd = { NULL, NULL, NULL, 0 };

/**
* main - Entry point to monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t readLine = 1;
	stack_t *stack = NULL;
	unsigned int lineCount = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	gd.montyFile = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readLine > 0)
	{
		content = NULL;
		readLine = getline(&content, &size, file);
		gd.lineContent = content;
		lineCount++;
		if (readLine > 0)
		{
			execute(content, &stack, lineCount, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
