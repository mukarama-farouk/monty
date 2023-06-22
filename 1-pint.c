#include "monty.h"

/**
 * f_pint - prints the value at the top of the stack,
 * followed by a new line.
 * @head: head of stack
 * @lineCount: line count of stack
 *
 * Return: no return
 */
void f_pint(stack_t **head, unsigned int lineCount)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineCount);
		fclose(gd.montyFile);
		free(gd.lineContent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
