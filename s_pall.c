#include "monty.h"

/**
 * f_pall -  prints all the values on the stack, starting
 * from the top of the stack.
 * @head: head of stack
 * @lineCount: Not used in function
 *
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int lineCount)
{
	stack_t *cur;
	(void)lineCount;

	cur = *head;
	if (cur == NULL)
		return;
	while (cur != NULL)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}
