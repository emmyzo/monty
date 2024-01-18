#include "monty.h"

/**
 * usage_error - prints error message if args is less or equal to 2
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - prints error when malloc fails
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_tools();
	exit(EXIT_FAILURE);
}

/**
 * file_open_error - prints error if file cannot be opened
 * @s: file
 */
void file_open_error(char *s)
{
	fprintf(stderr, "Error: Can't open file %s\n", s);
	free_tools();
	exit(EXIT_FAILURE);
}

/**
 * invalid_instruction - prints error message if command is unknown
*/
void invalid_instruction(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			tool->line_number, tool->tok[0]);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * not_int - prints error if value is not a valid int
 * @line_number: file no in the file
 */
void not_int(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
