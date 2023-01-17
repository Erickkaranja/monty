#include "monty.h"

/**
  * push - pushes an element to the stack
  * @stack: double pointer to the first node
  * @line_number: value of new node
  */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));
	char *op;
	int i;

	if (element == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
