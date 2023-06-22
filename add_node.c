#include "monty.h"

/**
 * add_node - Adds a node at the top of a stack
 * @n: new data
 * @head: Head of stack
 *
 * Return: no return
 */
void add_node(stack_t **head, int n)
{
	stack_t *new;
	stack_t *ptr;


	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	ptr = *head;
	if (ptr)
		ptr->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}

