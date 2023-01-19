#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
*
* monty_nop -Does absolutely nothing for the Monty opcode 'nop'.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @line_number: The current working line number of a Monty bytecodes file.
*
*/
void monty_nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}

/**
*
* monty_pstr - prints the string starting at the
		top of the stack, followed by a new line.
* @stack: A pointer to the top node of a stack_t list.
* @line_number: The current working line number of a monty bytecode file.
*/

void monty_pstr(stack_t **stack, unsigned int line_number)

{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
/**
*
*monty_pchar - prints the char at the top of the stack, followed by a new line
*@stack: Pointer to the top node of the lnked list.
*@line_number:The current working line on the monty byte code.
*/
void monty_pchar(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}
/**
*
*monty_rotl -  rotates the stack to the top.
*
*@stack: Pointer to the doubly linked list.
*@line_number:The current working line on the monty byte code.
*/
void monty_rotl(stack_t **stack, unsigned int line_number)

{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}
/**
*
*monty_rotr - rotates the stack to the bottom.
*@stack: Pointer to the doubly linked list.
*@line_number: the current working line on the monty byte code.
*/

void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
* monty_stack - sets the dataformat to stack (LIFO).
*@stack: pointer to the top node of the double linked list.
* @line_number: the current working line on the monty byte file.
*
*/

void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}
/**
* 
*monty_queue - sets the format of the data to a queue (FIFO)
*@stack: Pointer to the top node of the double linked list.
*@line_number:The current working line on the monty byte file.
*/
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
