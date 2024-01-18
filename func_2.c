#include "monty.h"

/**
 * add - adds the top 2 elems in  the stack
 * @head: pointer to head node
 * @line_number: file line no
 *
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void)head;
	if (tool->len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tool->stack->next->n += tool->stack->n;
	temp = tool->stack;
	tool->stack = temp->next;
	free(temp);
	tool->len--;
}

/**
 * nop - does nothing
 * @head: pointer to head node
 * @line_number: file no in file
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * sub - subtracts the top 2 elems in  the stack
 * @head: pointer to head node
 * @line_number: file line no
 *
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void)head;
	if (tool->len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tool->stack->next->n -= tool->stack->n;
	temp = tool->stack;
	tool->stack = temp->next;
	free(temp);
	tool->len--;
}

/**
 * divide - divides the top 2 elems in  the stack
 * @head: pointer to head node
 * @line_number: file line no
 *
 */
void divide(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void)head;
	if (tool->len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	if (tool->stack->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tool->stack->next->n /= tool->stack->n;
	temp = tool->stack;
	tool->stack = temp->next;
	free(temp);
	tool->len--;
}

/**
 * mul - multiplies the top 2 elems in  the stack
 * @head: pointer to head node
 * @line_number: file line no
 *
 */
void mul(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void)head;
	if (tool->len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tool->stack->next->n *= tool->stack->n;
	temp = tool->stack;
	tool->stack = temp->next;
	free(temp);
	tool->len--;
}
