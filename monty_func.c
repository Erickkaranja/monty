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
* pall - prints all the values on the stack,
*	starting from the top of the stack.
* @stack: Double pointer to the first node.
* @line_number: Value of new node.
*/

void pall(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
	return;
	}

	while (*stack)
	{
	printf("%d\n", (*stack)->n);
	(*stack)->next;
	}
}

/**
*
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
*pop - removes the top element of the stack.
*@stack: Double pointer to the stack.
*@line_number: Value of the new node.
*/
void pop(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
	printf("L<%d>: can't pop an empty stack", line_number);
	}
	int poped_data;
	stack_t *temp = *stack;
	*stack = (*stack)->next;

	poped_data = temp->n;
	free (temp);
}

/**
*
*swap - swaps the top two elements of the stack.
*
*@stack: Double pointer to the stack.
*
* @line_number: Value of the new node.
*/
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
	return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
