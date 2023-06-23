#include "monty.h"

/**
 * f_div -  divides the second top element of the
 * stack by the top element of the stack
 * @head: head of stack
 * @lineCount: line number
 *
 * Return: Nothing
 */
void f_div(stack_t **head, unsigned int lineCount)
{
	stack_t *tmp;
	tmp = *head;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lineCount);
        	fclose(gd.montyFile);
        	free(gd.lineContent);
        	free_stack(*head);
        	exit(EXIT_FAILURE);
	}

	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineCount);
        	fclose(gd.montyFile);
        	free(gd.lineContent);
        	free_stack(*head);
        	exit(EXIT_FAILURE);
	}

	tmp->next->n /= tmp->n;
	*head = tmp->next;
	free(tmp);
}
