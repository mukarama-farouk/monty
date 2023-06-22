#include "monty.h"

/**
 * f_pop - removes top node of the stack
 * @head: head of stack
 * @lineCount: counts the number of lines of stack
 *
 * Return: no return
 */
void f_pop(stack_t **head, unsigned int lineCount)
{
	stack_t *ptr;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineCount);
		fclose(gd.montyFile);
		free(gd.lineContent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	*head = ptr->next;
	free(ptr);
}
