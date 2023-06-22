#include "monty.h"
/**
 * f_queue - prints the top element
 * @head: stack head
 * @lineCount: line_number
 * Return: no return
*/
void f_queue(stack_t **head, unsigned int lineCount)
{
	(void)head;
	(void)lineCount;
	gd.insertMode = 1;
}

/**
 * f_stack - prints the top element
 * @head: stack head
 * @lineCount: line_number
 * Return: no return
*/
void f_stack(stack_t **head, unsigned int lineCount)
{
	(void)head;
	(void)lineCount;
	gd.insertMode = 0;
}
