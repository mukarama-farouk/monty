#include "monty.h"
/**
* execute - Function that executes all the opcode
* @stack: head linked list - stack
* @lineCount: line_counter
* @file: pointer to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int lineCount, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push},
			      	{"pall", f_pall}, 
				{"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *opp;

	opp = strtok(content, " \n\t");
	if (opp && opp[0] == '#')
		return (0);
	gd.argValue = strtok(NULL, " \n\t");
	while (opst[i].opcode && opp)
	{
		if (strcmp(opp, opst[i].opcode) == 0)
		{	opst[i].f(stack, lineCount);
			return (0);
		}
		i++;
	}
	if (opp && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", lineCount, opp);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
