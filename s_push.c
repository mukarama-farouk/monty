#include "monty.h"

/**
 * f_push - adds an element(node) to a stack
 * @head: Head of stack
 * @lineCount: line number
 *
 * Return: no return
 */
void f_push(stack_t **head, unsigned int lineCount)
{
	int n;
       	int i = 0;
	int flag = 0;

	printf("Push instruction at line %d. Argument value: %s\n", lineCount, gd.argValue);

	if (gd.argValue)
	{
		if (gd.argValue[0] == '-')
			i++;
		for (; gd.argValue[i] != '\0'; i++)
		{
			if (gd.argValue[i] > 57 || gd.argValue[i] < 48)
				flag = 1; 
		}
		if (flag == 1)
		{ 
			fprintf(stderr, "L%d: usage: push integer\n", lineCount);
			fclose(gd.montyFile);
			free(gd.lineContent);
			free_stack(*head);
			exit(EXIT_FAILURE); 
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineCount);
		fclose(gd.montyFile);
		free(gd.lineContent);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(gd.argValue);
	if (gd.insertMode == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}
