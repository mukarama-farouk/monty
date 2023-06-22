#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack.
 * @head: head of stack
 * @lineCount: Counts the number of lines of a stack
 *
 * Return: no return
 */
void f_swap(stack_t **head, unsigned int lineCount)
{
	stack_t *cur = *head;
	int length = 0, ptr;

	while (cur != NULL)
	{
		cur = cur->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineCount);
		fclose(gd.montyFile);
		free(gd.lineContent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	cur = *head;
	ptr = cur->n;
	cur->n = cur->next->n;
	cur->next->n = ptr;
}

