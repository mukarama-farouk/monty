#include "monty.h"

/**
 * f_sub -  subtracts the top element of the stack from
 * the second top element of the stack
 * @head: head of stack
 * @lineCount: line number
 *
 * Return: No return
 */
void f_sub(stack_t **head, unsigned int lineCount)
{
	stack_t *tmp;
	int diff;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineCount);
		fclose(gd.montyFile);
		free(gd.lineContent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	diff = (*head)->next->n - (*head)->n;
	(*head)->next->n = diff;
	free(tmp);

}
