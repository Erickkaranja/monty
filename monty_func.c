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
	int num;

	if (element == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	op = strtok(NULL, DELIMS);
	if (op == NULL || stack == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = _strtol(op, line_number);
	element->n = num;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
		(element->next)->prev = element;
	*stack = element;
}

/**
* pint - prints the value at the top of the stack.
* @stack: Double pointer of the stack.
* @line_number: value of new node.
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
	printf("L<%d>: can't pint, stack empty", line_number);

	while (*stack)
	printf("%d", (*stack)->n);
	}
}

/**
* swap - swaps the top two elements of the stack.
* @stack: Double pointer to the stack.
* @line_number: Value of the new node.
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	UNUSED(line_number);
	if (!(*stack) || !((*stack)->next))
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack) = (*stack)->prev;
}
