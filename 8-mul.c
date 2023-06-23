#include "monty.h"

/**
 * f_mul - multiplies the second top element of
 * the stack with the top element of the stack.
 * @head: head of stack
 * @lineCount: line number
 *
 * Return: no return
 */
void f_mul(stack_t **head, unsigned int lineCount)
{
	stack_t *first, *second;
	int mult;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lineCount);
		fclose(gd.montyFile);
		free(gd.lineContent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = first->next;
	mult = first->n * second->n;
	second->n = mult;
	*head = second;
	free(first);
}
