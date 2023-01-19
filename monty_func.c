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
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
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
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
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

/**
* pall - prints all the values on the stack,
*       starting from the top of the stack.
* @stack: Double pointer to the first node.
* @line_number: Value of new node.
*/


void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
/**
*pop - removes the top element of the stack.
*@stack: Double pointer to the stack.
*@line_number: Value of the new node.
*/
void pop(stack_t **stack, unsigned int line_number)
{
	{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
}
