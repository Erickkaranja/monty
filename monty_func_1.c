#include "monty.h"

/**
*
* Add - adds two top element on a stack and stores the value
	in the second index of the linked list.
* @stack: A pointer to the stack.
* @line_number: line on monty byte code.
*
*/
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	(*stack)->next->next->n += (*stack)->next->n;

pop(stack, line_number); 
}

/**
*
*sub - subtracts the top element of the stack from
	the second top element of the stack.
*
*@stack: A pointer to the stack.
*@line_number: line on monty byte code.
*/

void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	(*stack)->next->next->n -= (*stack)->next->n;

pop(stack, line_number);
}


/**
*
*mul - multiplies the second top element of the stack
	with the top element of the stack
* @stack: A pointer to the stack.
* @line_number: line on the monty byte code.
*/


void monty_mul(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	set_op_tok_error(short_stack_error(line_number, "mul"));
		return;

	(*stack)->next->next->n *= (*stack)->next->n;

pop(stack, line_number);
 }

/**
* div -  divides the second top element of the
	stack by the top element of the stack.
* @stack: A pointer to the stack.
*
*@ line_number: line on the monty byte code.
*/

void monty_div(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	set_op_tok_error(short_stack_error(line_number, "div"));
		return;

	if ((*stack)->next->n == 0)
	set_op_tok_error(div_error(line_number));
		return;

	(*stack)->next->next->n /= (*stack)->next->n;

pop(stack, line_number);
}
/**
*
* mod - computes the rest of the division of the second top
	element of the stack by the top element of the stack.
* @stack: pointer to the double linked list.
* @line_number: line on monty byte file.
*/
void monty_mod(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	set_op_tok_error(short_stack_error(line_number, "mod"));
		return;

	if ((*stack)->next->n == 0)
	set_op_tok_error(div_error(line_number));
		return;

	(*stack)->next->next->n %= (*stack)->next->n;

pop(stack, line_number);
}
