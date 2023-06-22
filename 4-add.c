#include "monty.h"

/**
 * f_add - A function which adds the the top
 * two elements of the stack
 * @head: head of the stack
 * @lineCount: Number line
 *
 * Return: no return
 */
void f_add(stack_t **head, unsigned int lineCount)
{
	stack_t *first, *second;
	int sum;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineCount);
		fclose(gd.montyFile);
		free(gd.lineContent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = first->next;
	sum = first->n + second->n;

	second->n = sum;
	*head = second;
	free(first);
}
