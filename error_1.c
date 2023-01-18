#include <stdio.h>
#include <stdlib.h>
/**
*
* usage_error - error type on wrong usage.
*
*/

int usage_error(void)
{
fprintf(stderr, "USAGE: monty file\n");
	return(EXIT_FAILURE);
}

/**
* open_error - error type if monty cannot open a file
* @filename: The error to be printed.
*
* Return: EXIT_STATUS.
*/

int open_error(char *filename)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);

	return(EXIT_FAILURE);
}

/**
*unknown_opcode_error - error type if input opcode is wrong.
*@opcode: The opcode function.
*@line_number: position of wrong opcode.
*/

int unknown_opcode_error(char *opcode, int line_number)
{
fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
*
*malloc_error - error type if malloc fails.
*
*/

int malloc_error(void)
{
fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
