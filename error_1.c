#include "monty.h"

/**
 * usage_error - error type on wrong usage.
 * Return: EXIT_STATUS.
 */

int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
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

	return (EXIT_FAILURE);
}

/**
 *unknown_opcode_error - error type if input opcode is wrong.
 *@opcode: The opcode function.
 *@line_number: position of wrong opcode.
 * Return: EXIT_STATUS.
 */

int unknown_opcode_error(char *opcode, int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - error type if malloc fails.
 *Return: EXIT_STATUS.
 */

int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * no_int_error - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * _strtol - wrapper around error, handling monty specific errors
 * @num_string: string that *should* represent an integer
 * @line_number: line counter of monty file
 * Return: long int that error converted
**/

int _strtol(char *num_string, unsigned int line_number)
{
	int base = 10;
	char *endptr;
	long val;

	errno = 0; /* To distinguish success/failure after call */
	val = strtol(num_string, &endptr, base);

	/* Check for various possible errors */

	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || (errno != 0 && val == 0))
	{
		/* perror("strtol"); */
		exit(EXIT_FAILURE);
	}

	if (endptr == num_string)
	{
		/* No digits were found */
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* If we got here, strtol() successfully parsed a number */
	/* return val; */

	if (num_string[0] != '\0')
		if (!isdigit(num_string[0]) && *endptr != '\0')
		/* I don't think this is testing for what I want. Oh, well ... */
		{
			/* trailing alpha on tail of number */
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	return (val);
}
