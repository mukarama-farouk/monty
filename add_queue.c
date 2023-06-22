#include "monty.h"
/**
 * add_queue - adds node to the end of a stack
 * @n: new data
 * @head: stack head
 *
 * Return: no return
 */
void add_queue(stack_t **head, int n)
{
	stack_t *new, *tmp;

	tmp = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
	}
	new->n = n;
	new->next = NULL;
	if (tmp != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!tmp)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		tmp->next = new;
		new->prev = tmp;
	}
}
